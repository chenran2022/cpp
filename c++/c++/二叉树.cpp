#include<iostream>
#include<string>
using namespace std;


/*
二叉搜索树概念
二叉搜索树又称二叉排序树，它或者是一棵空树，或者是具有以下性质的二叉树 :
若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
它的左右子树也分别为二叉搜索树
*/

//key模型

template<class K>
struct BSTreeNode	//binary search tree
{

	BSTreeNode(const K& key=K()):_key(key),_left(nullptr),_right(nullptr)
	{}

	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;
};
/*
template<class K>
class BSTree	//binary search tree
{
public:
	typedef BSTreeNode<K> Node;
	bool Insert(const K& key)	//二叉搜索树插入值只能在空位置插入，并且不能插入已经有的值
	{

		// 如果树为空，直接插入
		if (nullptr == _root)
		{
			_root = new Node(key);
			return true;
		}

		//双指针记录上一次的位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else   //不能插入已经有的值
			{
				return false;
			}
		}
		cur  = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << "  ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	//删除某个数据：
	//1.左为空，父亲指向我的右
	//2.右为空，父亲指向我的左
	//3.左右都不为空，不能直接删除，使用替换法删除，找到左子树的最右节点(最大节点)或者右子树的最左节点(最小节点)替换
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了
				//1.左为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						//判断cur是父节点的左还是右
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;

				}
				//2.右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						//判断cur是父节点的左还是右
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;

				}
				//3.左右都不为空
				else
				{
					//左子树最大节点的右为空，右子树的最小节点的左为空
					Node* rightMinParent = cur; //不能直接给空
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					cur->_key = rightMin->_key;
					if (rightMinParent->_left == rightMin)
					{
						rightMinParent->_left = rightMin->_right;
					}
					else	//当删除的是cur的右子节点时，
					{
						rightMinParent->_right = rightMin->_right;
					}
					delete rightMin;

				}
				return true;
			}
		}
		return false;
	}
private:
	Node* _root=nullptr;
};

int main()
{
	BSTree<int> tr;
	int a[] = { 8, 3, 1, 10, 6, 4, 7, 14, 13 };
	for (auto au : a)
	{
		tr.Insert(au);
	}
	tr.InOrder();

	tr.erase(8);
	tr.InOrder();

	for (auto au : a)
	{
		tr.erase(au);
		tr.InOrder();
	}
	return 0;
}
*/


//key/value模型

template<class K, class V>
struct BSTreeNode	//binary search tree
{

	BSTreeNode(const K& key = K(), const V& val = V())
		:_key(key), _val(val), _left(nullptr), _right(nullptr)
	{}

	BSTreeNode<K,V>* _left;
	BSTreeNode<K,V>* _right;
	K _key;
	V _val;
};

template<class K,class V>
class BSTree	//binary search tree
{
public:
	typedef BSTreeNode<K,V> Node;
	bool Insert(const K& key,const V& val)	//二叉搜索树插入值只能在空位置插入，并且不能插入已经有的值
	{

		// 如果树为空，直接插入
		if (nullptr == _root)
		{
			_root = new Node(key,val);
			return true;
		}

		//双指针记录上一次的位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else   //不能插入已经有的值
			{
				return false;
			}
		}
		cur  = new Node(key,val);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << "-"<<root->_val<<"  ";
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}
	Node* Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else
			{
				return cur;
			}
		}
		return nullptr;
	}

	//删除某个数据：
	//1.左为空，父亲指向我的右
	//2.右为空，父亲指向我的左
	//3.左右都不为空，不能直接删除，使用替换法删除，找到左子树的最右节点(最大节点)或者右子树的最左节点(最小节点)替换
	bool erase(const K& key)
	{
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				//找到了
				//1.左为空
				if (cur->_left == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_right;
					}
					else
					{
						//判断cur是父节点的左还是右
						if (parent->_left == cur)
						{
							parent->_left = cur->_right;
						}
						else
						{
							parent->_right = cur->_right;
						}
					}
					delete cur;

				}
				//2.右为空
				else if (cur->_right == nullptr)
				{
					if (cur == _root)
					{
						_root = cur->_left;
					}
					else
					{
						//判断cur是父节点的左还是右
						if (parent->_left == cur)
						{
							parent->_left = cur->_left;
						}
						else
						{
							parent->_right = cur->_left;
						}
					}
					delete cur;

				}
				//3.左右都不为空
				else
				{
					//左子树最大节点的右为空，右子树的最小节点的左为空
					Node* rightMinParent = cur; //不能直接给空
					Node* rightMin = cur->_right;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin = rightMin->_left;
					}
					cur->_key = rightMin->_key;
					if (rightMinParent->_left == rightMin)
					{
						rightMinParent->_left = rightMin->_right;
					}
					else	//当删除的是cur的右子节点时，
					{
						rightMinParent->_right = rightMin->_right;
					}
					delete rightMin;

				}
				return true;
			}
		}
		return false;
	}
private:
	Node* _root=nullptr;
};

int main()
{
	/*
	BSTree<string, string> dict;
	dict.Insert("string", "字符串");
	dict.Insert("tree", "树");
	dict.Insert("Chinese", "中文");

	string str;
	while (cin >> str)
	{
		BSTreeNode<string, string>* ret = dict.Find(str);
		if (ret)
		{
			cout << ret->_val << endl;
		}
		else
		{
			cout << "无此单词" << endl;
		}
	}*/


	// 统计水果出现的次数
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉" };
	BSTree<string,int> countTree;
	for (const auto& str : arr)
	{
		// 先查找水果在不在搜索树中
		// 1、不在，说明水果第一次出现，则插入<水果, 1>
		// 2、在，则查找到的节点中水果对应的次数++
		//BSTreeNode<string, int>* ret = countTree.Find(str);
		auto ret = countTree.Find(str);
		if (ret == nullptr)
		{
			countTree.Insert(str, 1);
		}
		else
		{
			ret->_val++;
		}
	}
	countTree.InOrder();
	return 0;
}

/*
插入和删除操作都必须先查找，查找效率代表了二叉搜索树中各个操作的性能。
对有n个结点的二叉搜索树，若每个元素查找的概率相等，
则二叉搜索树平均查找长度是结点在二叉搜索树的深度的函数，即结点越深，则比较次数越多。
最优情况下，二叉搜索树为完全二叉树(或者接近完全二叉树)，其平均比较次数为：log2(N)
最差情况下，二叉搜索树退化为单支树(或者类似单支)，其平均比较次数为：N/2
二叉搜索树退化，使二叉搜索树性能丢失，需要使二叉搜索树平衡，可以使用AVL树和红黑树
*/
