#include<iostream>

using namespace std;

//map底层结构：高度平衡二叉搜索树
//AVLTree 
//1.搜索二叉树
//2.要求树的左右子树的高度差不超过1，树左子树和右子树也满足高度差不超过1.（树及所有子树都满足前面条件）

//为了方便实现，在每个节点中引入平衡因子的概念（只是一种方式，并不是必须的）
//平衡因子 = 右子树高度 - 左子树高度
//高度基本可以控制在O(logN)
//AVLTree的增删查改效率都在O(logN)


template<class K,class V> 
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;

	int _bf;	//平衡因子
	pair<K, V> _kv;
	AVLTreeNode(const pair<K, V>& kv) 
		:_left(nullptr),
		_right(nullptr),
		_parent(nullptr),
		_bf(0),
		_kv(kv)
	
	{}
};

template<class K, class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	
	bool Insert(const pair<K,V>& kv)
	{
		// 1.先按二叉搜索树插入
		if (_root == nullptr)
		{
			_root = new Node(kv);
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
			else if (cur->_kv.first <  kv.first)  //如果是multimap，这里是cur->_kv.first <=  kv.first
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}

		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		//2.更新平衡因子 
		//平衡因子是用来衡量树有没有出问题的
		//插入的时候只影响节点的祖先的平衡因子值（并不是所有祖先都变），不影响其他节点的

		//cur是parent的左，parent->_bf--; cur是parent的右，parent->_bf++;
		//更新完parent->bf,如果parent->bf==0，说明parent的高度不变，更新结束，插入完成。(更新之前parent->bf==1或-1，变为0说明把低的填补上了，对上层没有影响)
		//更新完parent->bf,如果parent->bf==1或-1，说明parent的高度变了，继续向上更新。（更新之前parent->bf==0，变为1或-1，高度变高了，对上层有影响）
		//更新完parent->bf,如果parent->bf==2或-2，说明parent所在的子树出现了不平衡，需要旋转处理。

		while (parent)
		{
			if (cur == parent->_left)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0)
				break;
			else if (parent->_bf == 1 || parent->_bf == -1)
			{
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2)
			{
				//parent所在的子树出现了不平衡，需要旋转处理。
				//1.旋转的前提是它依旧是搜索二叉树
				//2.旋转成平衡树。
				//3.旋转结束后，插入完成。

				//旋转路径是直线，就是单旋
				//旋转路径是折线，就是双旋
				if (parent->_bf == 2)
				{
					if (parent->_right->_bf == 1)
					{
						RotateL(parent);
					}
					else if (parent->_right->_bf == -1)	//右左双旋
					{
						RotateRL(parent);//右左双旋：先右旋再左旋
					}
				}
				else if (parent->_bf == -2)
				{
					if (parent->_left->_bf == -1)
					{
						RotateR(parent);
					}
					else if (parent->_left->_bf == 1)	//左右双旋
					{
						RotateLR(parent);//左右双旋：先左旋再右旋
					}
				}
				// 旋转结束后，插入完成。
				// 因为旋转结束后，parent的高度恢复到了插入节点之前的高度，对上层没有影响，所以不需要再更新祖先的平衡因子值。
				break;
			}
		}
		return true;
	}

	//左旋
	void RotateL(Node* parent)
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;

		parent->_right = SubRL;
		SubR->_left = parent;

		//SubRL不为空节点，SubRL->_parent改为parent
		if (SubRL)
		{
			SubRL->_parent = parent;
		}

		//1.parent为根节点，SubR更改为根节点
		//2.parent为整棵树的子树，SubR的父节点更改为parent的父节点，parent的父节点的左或右子树更改为SubR
		if (parent == _root)
		{
			SubR->_parent = nullptr;
			_root = SubR;
		}
		else
		{
			//parent的父节点的左或右子树更改为SubR
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
			{
				pparent->_left = SubR;
			}
			else
			{
				pparent->_right = SubR;
			}

			SubR->_parent = pparent;
		}

		parent->_parent = SubR;
		parent->_bf = 0;
		SubR->_bf = 0;
	}

	 //右旋
	void RotateR(Node* parent)
	{

		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;

		parent->_left = SubLR;
		SubL->_right = parent;

		//SubLR不为空节点，SubLR->_parent改为parent
		if (SubLR)
		{
			SubLR->_parent = parent;
		}

		//1.parent为根节点，SubL更改为根节点
		//2.parent为整棵树的子树，SubL的父节点更改为parent的父节点，parent的父节点的左或右子树更改为SubL
		if (parent == _root)
		{
			SubL->_parent = nullptr;
			_root = SubL;
		}
		else
		{
			//parent的父节点的左或右子树更改为SubL
			Node* pparent = parent->_parent;
			if (parent == pparent->_left)
			{
				pparent->_left = SubL;
			}
			else
			{
				pparent->_right = SubL;
			}
			SubL->_parent = pparent;
		}

		parent->_parent = SubL;
		parent->_bf = 0;
		SubL->_bf = 0;
	}

	//在不同的位置插入，会导致最终的平衡因子不同

	void RotateRL(Node* parent)	//右左双旋
	{
		Node* SubR = parent->_right;
		Node* SubRL = SubR->_left;
		int bf = SubRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		//平衡因子的调整要根据图来理解
		if (bf == -1)
		{
			parent->_bf = 0;
			SubR->_bf = 1;
			SubRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			SubR->_bf = 0;
			SubRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			SubR->_bf = 0;
			SubRL->_bf = 0;
		}
	}


	void RotateLR(Node* parent)	//左右双旋
	{
		Node* SubL = parent->_left;
		Node* SubLR = SubL->_right;
		int bf = SubLR->_bf;	

		RotateL(parent->_left);
		RotateR(parent);
		
		if (bf == -1)
		{
			parent->_bf = 1;
			SubL->_bf = 0;
			SubLR->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = 0;
			SubL->_bf = -1;
			SubLR->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			SubL->_bf = 0;
			SubLR->_bf = 0;
		}
	}

	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_kv.first << " " << root->_kv.second << endl;
		_InOrder(root->_right);
	}
	void InOrder()
	{
		_InOrder(_root);
		cout << endl;
	}

	bool _IsBalance(Node* root)
	{
		if (root == nullptr)
			return true;
		if (abs(root->_bf) > 1)
			return false;
		return _IsBalance(root->_left) && _IsBalance(root->_right);
	}	
	bool IsBalance()
	{
		return _IsBalance(_root);
	}

private:
	Node* _root = nullptr;

};

void test()
{
	int a[] = { 1,2,3,4,5,6,7,8,9,10 };
	AVLTree<int, int> avl;
	for (int i = 0; i < 10; i++)
	{
		avl.Insert(make_pair(a[i], a[i]));
	}
	avl.InOrder();
	cout << avl.IsBalance() << endl;
}
int main()
{
	AVLTree<int, int> avl;
	avl.Insert(make_pair(1, 1));
	avl.Insert(make_pair(2, 2));
	test();
	return 0;
}

