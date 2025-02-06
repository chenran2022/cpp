#include <iostream>
using namespace std;

//1、二叉搜索树。 - 》存储数据的同时方便进行高效搜索(在此之前的数据结构的搜索基本都是暴力搜索)。
//问题 : 极端情况下(比如有序的方式进行插入)，二叉搜索树就会退化成单链形式，效率变为0(N), 效率低下。
//2、AVL树。 - 》在二叉树搜索树基础之上加了一个条件 : 左右子树高度差不超过1，并且左右子树也满足次条件。(也就说所有子树都满足)
//增删查改搜素效率非常高 : 0(1ogN)
//(如果内存是够的情况下，将所有中国人的信息放到树中，查找一个人的信息最多只需要31次，大家可以感受一下AVL树的效率，如果是暴力搜素需要14亿次)
//3、红黑树。

/*
复习AVL树:
1、增、删、查、改 :
	增 : a、按搜索树规则插入	b、更新平衡因子		c、更新过程中出现平衡因子为2 / -2, 则根据情况判断是那种旋转，进行旋转。
	删 : a、按搜索树的规则删除	b、更新平衡因子		c、更新过程中出现平衡因子为2 / -2, 则根据情况判断是哪种旋转，进行旋转处理。
	
	删除跟插入基本相反
	1、	右边插入，父亲平衡因子++，左边插入父亲平衡因子--
		右边删除，父亲平衡因子--”左边删除父亲平衡因子++
	2、	插入后，父亲的平衡因子变成0，说明父亲所在的树高度不变，更新结束
		删除后，父亲的平衡因子变成0，说明父亲所在的树高度变了，继续往上更新
	3、	插入后，父亲的平衡因子变成1 / -1，说明父亲所在的树高度变了，继续往上更新
		删除后，父亲的平衡因子变成1 / -1，说明父亲所在的树高度不变，更新结束
	4、	插入 / 删除后，父亲的平衡因子变成2 / -2，说明不平衡，旋转处理

查和改:
1、搜索树中key是不允许修改的，因为如果修改了整棵树可能就破坏了。 key/value的场景下可以修改value。
2、查和改和二叉树搜索树是一样的。
*/


/*
红黑树:
	搜素二叉树，节点中加了颜色，不是红色就是黑色，
	树中最长的路径不超过最短的路径的2倍
	AVL树是严格平衡二叉搜索树
	红黑树是近似平衡二叉搜索树
		1.每个结点不是红色就是黑色
		2.根节点是黑色的
		3.如果一个节点是红色的，则它的两个孩子结点是黑色的，也就是不存在连续的红节点
		4.对于每个结点，从该结点到其所有后代叶结点的简单路径上，均包含相同数目的黑色结点
		5.每个叶子结点都是黑色的(此处的叶子结点指的是空结点，不是以前说的叶子节点，是指以前的叶子节点的空子节点)
思考:为什么满足上面的性质，红黑树就能保证:其最长路径中节点个数不会超过最短路径节点个数的两倍?

总结一下: a、根是黑的  b、没有连续的红节点  c、每条路径都有相同数量的黑节点
	最短的路径:全黑	
	最长的路径:一黑一红(相间分布)
	所以最多是2倍

	增删查改时间复杂度是:0(LogN)
		最短路径是:0(logN)
		最长路径是:2*0(logN)
也就是说理论上而言，红黑树的效率比AVL树略差
但是现在，硬件的运算速度非常快，他们之间己经基本没有差异了。因为常规数据集中1ogN足够小，2*logN差异不大。
为什么AVLTree和红黑树性能基本差了2倍，但是我们认为基本是一样的呢?
因为硬件足够快，比如10亿个数查找AVLTree最多查找30次。红黑树最多查找60次。30和60最现在的硬件基本是一样的

但是插入删除同样节点红黑树比AVL树旋转更少，因为AVLTree更严格的平衡其实是通过多旋转达到的。
所以红黑树的应用广泛，在实现上更方便
*/


enum Color 
{ 
	BLACK, 
	RED
};

template<class K,class V>
class RBTreeNode
{
public:
	RBTreeNode<K,V>* _left;
	RBTreeNode<K,V>* _right;
	RBTreeNode<K,V>* _parent;
	pair<K, V> _kv;
	Color _color;

	//这里颜色默认为红色，因为规则里面 每条路径包含相同数目的黑色结点 比 不连续的红色节点 更复杂
	RBTreeNode(pair<K, V> kv):_kv(kv),_color(RED),_left(nullptr),_right(nullptr),_parent(nullptr)
	{
	}
};

template<class K,class V>
class RBTree
{
public:
	typedef RBTreeNode<K,V> Node;

	bool Insert(pair<K, V> kv)
	{
		//空树 就令根节点为黑
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_color = BLACK; // 根节点是黑色的
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (cur->_kv.first < kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
				return false;
		}
		cur = new Node(kv);
		cur->_parent = parent;
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;			
		}
		else
		{
			parent->_right = cur;
		}


		//颜色处理：cur是插入节点  p是parent  g是grandparent  u是uncle
		/*
		p是黑就结束
		第一种情况：cur默认为红，p是红，若u存在且是红，g为黑  
				=》p和u变黑，g变红。
				1.如果g是根节点，把g变黑，结束；
				2.如果g不是根节点，再看g的父亲颜色。如果g的父亲为黑，结束；如果g的父亲为红，继续向上处理
			这样变后，没有连续的红节点，且保持了子树中每条路径的黑节点数目不变
		不管cur是新增节点还是子树的父节点(原来是黑，由于变色处理变为红)，cur是红，p是红，只要u存在且是红 =》p和u变黑，g变红，继续向上处理
		
		第二种情况：cur默认为红，p是红，g为黑，u不存在或者为黑。cur与p与g是一种直线关系(都是左节点 或 都是右节点的关系)
				如果u不存在，则cur一定是新增节点，因为要每条路径要保持相同数目的黑色节点
				如果u存在为黑，则cur一定不是新增节点，cur原来是黑，由于子树第一种情况变色处理变为红
				不管u是不存在还是为黑，处理方式一样：旋转(左旋或右旋) + 变色(p变黑，g变红)

		第三种情况：cur默认为红，p是红，g为黑，u不存在或者为黑。cur与p与g是一种折线关系(一个左节点 一个右节点的关系)
				如果u不存在，则cur一定是新增节点，因为要每条路径要保持相同数目的黑色节点
				如果u存在为黑，则cur一定不是新增节点，cur原来是黑，由于子树第一种情况变色处理变为红
				不管u是不存在还是为黑，处理方式一样：双旋转(左右双旋或右左双旋) + 变色(cur变黑，g变红)
		*/

		cur->_color = RED;//新增节点默认为红色
		while (parent && parent->_color == RED)
		{
			Node* grandparent = parent->_parent;
			if (parent==grandparent->_left)
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
		return true;
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
		cout << root->_kv.first << " " << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	Node* Find(const K& k)
	{

		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first > k)
			{
				cur = cur->_left;
			}
			else if (cur->_kv.first < k)
			{
				cur = cur->_right;
			}
			else
				return cur;
		}
		return nullptr;

	}

	/*
	红黑树的验证
		红黑树的检测分为两步：
		1. 检测其是否满足二叉搜索树(中序遍历是否为有序序列)
		2. 检测其是否满足红黑树的性质
	*/
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
		while(pCur)
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

	/*
		删除操作总共分为5种情况
		https://www.cnblogs.com/fornever/archive/2011/12/02/2270692.html
	*/
	/*
	红黑树与AVL树的比较
		红黑树和AVL树都是高效的平衡二叉树，增删改查的时间复杂度都是O($log_2 N$)，红黑树不追
		求绝对平衡，其只需保证最长路径不超过最短路径的2倍，相对而言，降低了插入和旋转的次数，
		所以在经常进行增删的结构中性能比AVL树更优，而且红黑树实现比较简单，所以实际运用中红黑树更多
	*/
	private:
		Node* _root=nullptr;
	};

void test()
{
	int a[] = { 4, 2, 6, 1, 3, 5, 15, 7, 16, 14 };
	RBTree<int, int> rb;
	for (int i = 0; i < 10; i++)
	{
		rb.Insert(make_pair(a[i], a[i]));
	}
	rb.InOrder();
	cout << rb.IsValidRBTree()<<endl;
}
int main() 
{

	test();
	return 0;
}
