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
		_parent(nullptr).
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

			}
		}
		return true;
	}

private:
	Node* _root = nullptr;

};
int main()
{
	
	return 0;
}
