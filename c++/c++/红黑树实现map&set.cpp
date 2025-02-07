#include <iostream>
using namespace std;


enum Color
{
	BLACK,
	RED
};

template<class T>
struct RBTreeNode
{
	RBTreeNode<T>* _left;
	RBTreeNode<T>* _right;
	RBTreeNode<T>* _parent;
	T _data;	//这里的T 如果是map，T就是pair<K, V>；如果是set，T就是K
	Color _color;

	//这里颜色默认为红色，因为规则里面 每条路径包含相同数目的黑色结点 比 不连续的红色节点 更复杂
	RBTreeNode(const T& data) :_data(data), _color(RED), _left(nullptr), _right(nullptr), _parent(nullptr)
	{
	}
};

template<class T>
struct __TreeIterator
{
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T> Self;
	Node* _node;

	__TreeIterator(Node* node) :_node(node)
	{}
	T& operator*()
	{
		return _node->_data;
	}

	T* operator->()
	{
		return &_node->_data;
	}
	Self& operator++()
	{

		Node* SubL = _node->_right;
		if (SubL)
		{
			//1. 右子树不为空，中序下一个是右子树的最左节点
			while (SubL->_left)
			{
				SubL = SubL->_left;
			}
			_node = SubL;
		}
		else
		{
			//2. 右子树为空，表示_node所在的子树已经完成，需要往上找
			//沿着路径往上，孩子是父亲的左节点的那个祖先
			Node* cur = _node;
			Node* parent = cur->_parent;
			while (parent && cur == parent->_right)
			{
				cur = parent;
				parent = cur->_parent;
			}
			_node = parent;
		}
		return *this;
	}
	Self& operator--()
	{
		return *this;
	}
	bool operator!=(const Self& self)
	{
		return _node != self._node;
	}


};

template<class K, class T,class KOfT>
class RBTree
{
public:
	typedef RBTreeNode<T> Node;
	typedef __TreeIterator<T> iterator;


	//红黑树一般按照中序进行排列，所以迭代器的begin是最左节点
	iterator begin()
	{
		Node* cur = _root;
		while (cur && cur->_left)
		{
			cur = cur->_left;
		}
		return iterator(cur);
	}

	iterator end()
	{
		return iterator(nullptr);
	}
	//这里的T 如果是map，T就是pair<K, V>；如果是set，T就是K
	//如果是pair，下面就不能直接去比较大小，pair比较大小是first比较完之后还会比较second，而map只要求比较first的大小，不能写出一个通用的比较方式
	//所以要用仿函数

	//插入成功返回插入的节点迭代器，true
	//插入失败，返回已经存在的节点迭代器，false
	//返回值是pair是为了容易实现operator[]
	pair<iterator,bool> Insert(const T& data)
	{
		//空树 就令根节点为黑
		if (_root == nullptr)
		{
			_root = new Node(data);
			_root->_color = BLACK; // 根节点是黑色的
			return make_pair(iterator(_root),true);
		}

		KOfT koft;
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) > koft(data))
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (koft(cur->_data) < koft(data))
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return make_pair(iterator(cur),false);
		}
		cur = new Node(data);
		Node* newnode = cur;

		cur->_parent = parent;
		if (koft(cur->_parent->_data) > koft(data))
		{
			parent->_left = cur;
		}
		else
		{
			parent->_right = cur;
		}

		cur->_color = RED;//新增节点默认为红色
		while (parent && parent->_color == RED)
		{
			Node* grandparent = parent->_parent;
			if (parent == grandparent->_left)
			{
				Node* uncle = grandparent->_right;
				//第一种情况：cur默认为红，p是红，若u存在且是红，g为黑
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandparent->_color = RED;

					//继续向上处理
					cur = grandparent;
					parent = cur->_parent;
				}
				//情况2和3：cur默认为红，p是红，g为黑，u不存在或者为黑。
				else
				{
					//可以把情况3变为情况2
					if (cur == parent->_right)
					{
						//第三种情况
						RotateL(parent);//先进行左旋，之后再进行右旋
						swap(cur, parent);
					}

					//第二种情况
					RotateR(grandparent);
					parent->_color = BLACK;
					grandparent->_color = RED;

					//右旋之后parent称为了grandparent的父节点，且parent的颜色为黑，对上面没有影响，可以结束了
					break;
				}
			}
			else
			{
				Node* uncle = grandparent->_left;
				//第一种情况：cur默认为红，p是红，若u存在且是红，g为黑
				if (uncle && uncle->_color == RED)
				{
					parent->_color = BLACK;
					uncle->_color = BLACK;
					grandparent->_color = RED;

					//继续向上处理
					cur = grandparent;
					parent = cur->_parent;
				}
				//情况2和3：cur默认为红，p是红，g为黑，u不存在或者为黑。
				else
				{
					//可以把情况3变为情况2
					if (cur == parent->_left)
					{
						//第三种情况
						RotateR(parent);//先进行右旋，之后再进行左旋
						swap(cur, parent);
					}

					//第二种情况
					RotateL(grandparent);
					parent->_color = BLACK;
					grandparent->_color = RED;

					//左旋之后parent称为了grandparent的父节点，且parent的颜色为黑，对上面没有影响，可以结束了
					break;
				}
			}
		}
		_root->_color = BLACK;
		return make_pair(iterator(newnode), true);
	}
	void RotateR(Node* parent)
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		parent->_left = SubLR;

		if (SubLR)
		{
			SubLR->_parent = parent;
		}

		if (_root == parent)
		{
			SubL->_parent = nullptr;
			_root = SubL;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
				pparent->_left = SubL;
			else
				pparent->_right = SubL;
			SubL->_parent = pparent;

		}
		parent->_parent = SubL;
		SubL->_right = parent;
	}

	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		parent->_right = SubRL;
		SubR->_left = parent;
		if (SubRL)
		{
			SubRL->_parent = parent;
		}

		if (_root == parent)
		{
			SubR->_parent = nullptr;
			_root = SubR;
		}
		else
		{
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
				pparent->_left = SubR;
			else
				pparent->_right = SubR;
			SubR->_parent = pparent;

		}
		parent->_parent = SubR;
	}

	void InOrder()
	{
		_InOrder(_root);
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		//cout << root->_kv.first << " " << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	iterator* Find(const K& k)
	{
		KOfT koft;
		Node* cur = _root;
		while (cur)
		{
			if (koft(cur->_data) > koft(k))
			{
				cur = cur->_left;
			}
			else if (koft(cur->_data) < koft(k))
			{
				cur = cur->_right;
			}
			else
				return iterator(cur);
		}
		return iterator(nullptr);

	}

	bool IsValidRBTree()
	{
		Node* pRoot = _root;
		// 空树也是红黑树
		if (nullptr == pRoot)
			return true;
		// 检测根节点是否满足情况
		if (BLACK != pRoot->_color)
		{
			cout << "违反红黑树性质二：根节点必须为黑色" << endl;
			return false;
		}
		// 获取任意一条路径中黑色节点的个数
		size_t blackCount = 0;
		Node* pCur = pRoot;
		while (pCur)
		{
			if (BLACK == pCur->_color)
				blackCount++;
			pCur = pCur->_left;
		}
		// 检测是否满足红黑树的性质，k用来记录路径中黑色节点的个数
		size_t k = 0;
		return _IsValidRBTree(pRoot, k, blackCount);
	}
	bool _IsValidRBTree(Node* pRoot, size_t k, const size_t blackCount)
	{
		//走到null之后，判断k和black是否相等
		if (nullptr == pRoot)
		{
			if (k != blackCount)
			{
				cout << "违反性质四：每条路径中黑色节点的个数必须相同" << endl;
				return false;
			}
			return true;
		}
		// 统计黑色节点的个数
		if (BLACK == pRoot->_color)
			k++;
		// 检测当前节点与其双亲是否都为红色(如果检查孩子是否为红，情况多些，与检查父节点是否为红效果相同)
		Node* pParent = pRoot->_parent;
		if (pParent && RED == pParent->_color && RED == pRoot->_color)
		{
			cout << "违反性质三：没有连在一起的红色节点" << endl;
			return false;
		}
		return _IsValidRBTree(pRoot->_left, k, blackCount) &&
			_IsValidRBTree(pRoot->_right, k, blackCount);
	}

private:
	Node* _root = nullptr;
};


namespace cr
{
	template<class K, class V>
	class map
	{
	public:
		struct MapKeyOfT
		{
			const K& operator()(const pair<K, V>& kv)
			{
				return kv.first;
			}
		};
		typedef typename RBTree<K, pair<K, V>, MapKeyOfT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> Insert(const pair<K, V>& kv)
		{
			return _t.Insert(kv);
		}

		//[]内是key的值，返回的是key所对应的value值
		//	map的operator[]作用：
		//	1.插入(当原来不存在key)
		//	2.查找k对应的映射对象
		//	3.修改k对用的映射对象
		V& operator[](const K& key)
		{
			pair<iterator, bool> ret = _t.Insert(make_pair(key,V()));
			return ret.first->second;//这里的->是irerator的运算符重载，同下
			//return ret.first._node->_data.second;
		}
	private:
		RBTree<K, pair<K, V>, MapKeyOfT> _t;
	};


	template<class K>
	class set
	{
	public:
		struct SetKeyOfT
		{
			const K& operator()(const K& k)
			{
				return k;
			}
		};
		typedef typename RBTree<K, K, SetKeyOfT>::iterator iterator;
		iterator begin()
		{
			return _t.begin();
		}
		iterator end()
		{
			return _t.end();
		}

		pair<iterator,bool> Insert(const K& k)
		{
			return _t.Insert(k);
		}
	private:
		RBTree<K, K, SetKeyOfT> _t;
	};
}

void test_map()
{
	cr::map<int, int> m;
	m.Insert(make_pair(1, 1));
	m.Insert(make_pair(2, 2));
	m.Insert(make_pair(3, 3));
	m.Insert(make_pair(4, 4));
	cr::map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}
void test_set()
{
	cr::set<int> s;
	s.Insert(1);
	s.Insert(2);
	s.Insert(3);
	s.Insert(4);
	s.Insert(5);
	cr::set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;
}
int main()
{

	test_map();
	test_set();

	//使用[]统计次数，[]内是key的值，返回的是key所对应的value值
	string arr2[] = { "苹果", "苹果","西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "西瓜","香蕉", "苹果", "香蕉","香蕉" };
	cr::map<string, int> countMap2;
	for (auto& au : arr2)
	{
		countMap2[au]++;	
		//[]内是key的值，返回的是key所对应的value值
		//1.如果水果不在map中，则插入pair<string,int()>,即pair<au,0>;返回映射对象(value)的引用，再++
		//2.如果水果在map中，插入失败，返回string所在映射对象(value)的引用，再++
	}
	for (auto& au : countMap2)
	{
		cout << au.first << ":" << au.second << endl;
	}
	cout << endl;

	return 0;
}
