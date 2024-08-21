#include<iostream>
using namespace std;


/*
二叉搜索树概念
二叉搜索树又称二叉排序树，它或者是一棵空树，或者是具有以下性质的二叉树 :
若它的左子树不为空，则左子树上所有节点的值都小于根节点的值
若它的右子树不为空，则右子树上所有节点的值都大于根节点的值
它的左右子树也分别为二叉搜索树
*/


template<class T>
struct BSTreeNode	//binary serch tree
{

	BSTreeNode(const T& x=T()):_val(x),_left(nullptr),_right(nullptr)
	{}

	BSTreeNode<T>* _left;
	BSTreeNode<T>* _right;
	T _val;
};

template<class T>
class BSTree	//binary serch tree
{
public:
	typedef BSTreeNode<T> Node;
	bool Insert(const T& x)	//二叉搜索树插入值只能在空位置插入，并且不能插入已经有的值
	{

		// 如果树为空，直接插入
		if (nullptr == _root)
		{
			_root = new Node(x);
			return true;
		}

		//双指针记录上一次的位置
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (x > cur->_val)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if(x < cur->_val)
			{
				parent = cur;
				cur = cur->_left;
			}
			else   //不能插入已经有的值
			{
				return false;
			}
		}
		cur  = new Node(x);
		if (x > parent->_val)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	void _IsOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_IsOrder(root->_left);
		cout << root->_val << "  ";
		_IsOrder(root->_right);
	}
	void IsOrder()
	{
		_IsOrder(_root);
		cout << endl;
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
	tr.IsOrder();
	return 0;
}
