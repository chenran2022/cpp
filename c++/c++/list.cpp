//为什么会有list？
//list是为了补充vector的缺点存在的
//vector缺点：
//	1.头插和中间的插入删除效率很低, O(N)，因为需要挪动数据
//	2.插入数据空间不够时需要增容，增容需要开辟新空间、拷贝数据、释放旧空间，付出很大的代价
//vector优点：
//	1.支持下标的随机访问，间接的就很好的支持排序、二分查找、堆算法等
//list的出现就是为了解决vector的缺陷
//list优点：
//	1.头插和中间的插入删除效率高, O(1),因为不需要挪动数据
//	2.插入数据是新增节点，不需要增容
//list缺点：
//	1.不支持随机访问
//
//综上，list和vector是相辅相成的两个容器

#include<list>
#include<iostream>
#include<assert.h>
using namespace std;


//void print_list(const list<int>& lt)
//{
//	list<int>::const_iterator it = lt.begin();
//	while (it != lt.end())
//	{
//		cout << *it << "  ";
//		++it;
//	}
//	cout << endl;
//}
//void test_list1()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_front(0);
//
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		cout << *it << "  ";
//		++it;
//	}
//	cout << endl;
//
//	list<int> l2(l);
//	print_list(l2);
//
//	list<int> l3;
//	l3 = l2;
//	//只要容器支持迭代器，就可以使用范围for操作
//	for (auto au : l3)
//	{
//		cout << au << "  ";
//	}
//	cout << endl;
//
//	list<int>::reverse_iterator rit = l3.rbegin();
//	while (rit != l3.rend())
//	{
//		cout << *rit << "  ";
//		++rit;
//	}
//	cout << endl;
//}
////支持的操作接口的角度分迭代器的类型：单向（forwawrd_list),双向（list),随机(vector)
////从使用的场景的角度分迭代器的类型：（正向迭代器、反向迭代器）+ const迭代器
//
//
//void test_list2()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_front(0);
//	l.push_front(-1);
//	print_list(l);
//
//	l.pop_back();
//	l.pop_front();
//	print_list(l);
//
//	list<int>::iterator pos = find(l.begin(), l.end(), 1);
//	if (pos != l.end())
//	{
//		l.insert(pos, 100); //list插入并不会造成迭代器失效
//		print_list(l);
//		l.erase(pos);		//list  erase会造成迭代器失效
//	}
//	print_list(l);
//	
//	
//	//splice 转移一个list到另一个list
//	list<int> l2;
//	l2.push_back(100);
//	list<int>::iterator it = l2.begin();	
//	l2.splice(it, l);
//	print_list(l2);
//
//	//remove  从list中找值删掉
//	l2.remove(100);
//	print_list(l2);
//
//	//sort   reverse
//	l.push_back(2);
//	l.push_back(3);
//	l.push_front(0);
//	l.push_front(-1);
//	l.sort();
//	print_list(l);
//	l.reverse();
//	print_list(l);
//
//}
//
//
////迭代器失效
//void test_list3()
//{
//	list<int> l;
//	l.push_back(1);
//	l.push_back(2);
//	l.push_back(3);
//	l.push_front(0);
//	l.push_front(-1);
//
//	list<int>::iterator it = l.begin();
//	while (it != l.end())
//	{
//		if (*it == 3)
//		{
//			//l.erase(it);  //迭代器失效
//			it = l.erase(it);
//		}
//		else
//		{
//			++it;
//		}
//	}
//}
//int main()
//{
//	//test_list1();
//	//test_list2();
//	test_list3();
//	return 0;
//}





//list的底层实现   list的迭代器是一个节点的指针
namespace cr
{
	template<class T>
	struct __list_node
	{
		__list_node<T>* next;
		__list_node<T>* prev;
		T _data;

		__list_node<T>(const T& x = T()):_data(x)
		{}
	};


	// __list_iterator<T, T&, T*> iterator;  //可读可写
	// __list_iterator<T, const T&, const T*> const_iterator;  //可读不可写
	template<class T,class Ref,class Ptr>
	struct __list_iterator
	{
		typedef __list_node<T> Node;
		typedef __list_iterator< T, Ref, Ptr> Sef;
		Node* _node;

		__list_iterator(Node* node):_node(node)
		{}
		////*it
		//T& operator*()
		//{
		//	return _node->_data;
		//}

		////it->
		//T* operator->()
		//{
		//	return &_node->_data;
		//}

		// 禁止 const_iterator 可以修改，需要返回 const T&  const T*
		
		//*it
		Ref operator*()
		{
			return _node->_data;
		}

		//it->
		Ptr operator->()
		{
			return &_node->_data;
		}
		
		//++it
		Sef& operator++()
		{
			_node = _node->next;
			return *this;
		}

		//it++
		Sef& operator++(int)
		{
			Sef tmp(*this);
			//_node = _node->next;
			++(*this);
			return tmp;
		}
		
		//--it
		Sef& operator--()
		{
			_node = _node->prev;
			return *this;
		}

		//it--
		Sef& operator--(int)
		{
			Sef tmp(*this);
			//_node = _node->prev;
			--(*this);
			return tmp;
		}

		//it!=end()
		bool operator!=(const Sef& it)
		{
			return _node != it._node;
		}
	};
	template<class T>
	class list
	{
		typedef __list_node<T> Node;
	
	public:
		//带头双向循环链表
		list()
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head;
		}
		list(const list<T>& lt)
		{
			_head = new Node;
			_head->next = _head;
			_head->prev = _head; 

			/*const_iterator it = lt.begin();
			while (it != lt.end())
			{
				push_back(*it);
				++it;
			}*/

			for (auto au : lt)
				push_back(au);
		}
		/*list<T>& operator=(const list<T>& lt)
		{
			if (this == &lt)
			{
				return *this;
			}
			if (begin() != end())
				clear();
			
			for (auto au : lt)
				push_back(au);

			return *this;
		}*/

		list<T>& operator=(list<T> lt)
		{
			swap(_head, lt._head);
			return *this;
		}
		~list()
		{
			clear();
			delete[] _head;
			_head = nullptr;
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
			}
		}
		typedef __list_iterator<T ,T&,T*> iterator;
		typedef __list_iterator<T, const T&, const T*> const_iterator;
		iterator begin()  //头结点的下一个节点
		{
			return iterator(_head->next);
		}
		iterator end()   //头节点
		{
			return iterator(_head);
		}
		const_iterator begin()const
		{
			return const_iterator(_head->next);
		}
		const_iterator end()const
		{
			return const_iterator(_head);
		}
		void push_back(const T& x)
		{
			//1.
			//Node* tail = _head->prev;

			//Node* new_node = new Node(x);  //需要Node构造函数
			///*Node* new_node = new Node;
			//new_node->_data = x;*/
			//new_node->next = _head;
			//new_node->prev = tail;
			//tail->next = new_node;
			//_head->prev = new_node; 

			//2.
			insert(end(), x);
		}

		void pop_back()
		{
			erase(--end());
		}
		void push_front(const T& x)
		{
			insert(begin(), x);
		}
		void pop_front()
		{
			erase(begin());
		}
		void insert(iterator pos, const T& x)
		{
			Node* cur = pos._node;
			Node* prev = cur->prev;
			Node* new_node = new Node(x);
			new_node->next = cur;
			new_node->prev = prev;
			prev->next = new_node;
			cur->prev = new_node;
		}

		//list.erase会导致迭代器失效，vector.insert也会导致迭代器失效，因为vector增容会重新开辟一块空间，而list.insert不会导致迭代器失效
		void erase(iterator pos)	
		{
			assert(pos._node != pos._node->next);
			assert(pos != end());
			Node* prev = pos._node->prev;
			Node* next = pos._node->next;
			prev->next = next;
			next->prev = prev;
			delete pos._node;
		}
	private:
		Node* _head;
	};

	struct Date
	{
		Date():_year(2000),_month(1),_day(1)
		{

		}
		Date(int year,int month,int day):_year(year),_month(month),_day(day)
		{}
	
		int _year;
		int _month;
		int _day;
	};
	void print_list(const list<int>& lt)
	{
		//const list<int>& lt   不能被修改
		list<int>::const_iterator it = lt.begin();
		while (it != lt.end())
		{
			//*it = 1;
			cout << *it << "  ";
			++it;
		}
		cout << endl;
	}
	void test_list1()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int>::iterator it = lt.begin();
		while (it != lt.end())
		{
			*it = 1;
			cout << *it << "  ";
			++it;
		}
		cout << endl;
		print_list(lt);
	}
	void test_list2()
	{
		list<Date> lt;
		lt.push_back(Date());
		lt.push_back(Date());
		lt.push_back(Date());

		list<Date>::iterator it = lt.begin();
		while (it != lt.end())
		{
			//cout << *it << "  ";  //对于自定义类型，如果没有重载<<,就不能使用*it

			//it->  it.operator->()  Date*
			//这里原本应该是it->->_year,但为了可读性，编译器特殊处理了一下
			cout << it->_year << "  " << it->_month << "  " << it->_day << endl; //更喜欢这么用
			cout << (*it)._year << "  " << (*it)._month << "  " << (*it)._day << endl;
			++it;
		}
		cout << endl;
	}
	void test_list3()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		print_list(lt);

		lt.insert(++lt.begin(), 100);
		print_list(lt);
		
		lt.insert(++lt.end(), 250);
		print_list(lt);

		lt.push_back(360);
		lt.push_front(520);
		print_list(lt);


		lt.erase(lt.begin());
		print_list(lt);
		lt.pop_back();
		print_list(lt);

		lt.clear();
		lt.push_back(30);
		print_list(lt);
	}
	void test_list4()
	{
		list<int> lt;
		lt.push_back(1);
		lt.push_back(2);
		lt.push_back(3);
		lt.push_back(4);

		list<int> lt2(lt);
		print_list(lt2);

		list<int> lt3;
		lt3 = lt;
		print_list(lt3);
	}

}

int main()
{
	//cr::test_list1();
	//cr::test_list2();
	//cr::test_list3();
	cr::test_list4();

	//Node* cur
	//iterator it
	/*当他们都指向同一个节点，那么在物理内存中他们都是存的这个节点的地址，物理上一样
	但是它们的类型不同，意义不一样
	比如*cur是一个指针的解引用，取到的值是这个节点
	而*it是调用调用迭代器的operator*，返回值是这个节点存的值*/
	return 0;
}

//总结
//1、vector和list的区别 ?
//2、vector和list底层是如何实现的 ?
//3、vector是如何增容的 ?
//4、什么是迭代器失效 ?
//
//
//vector是一个可动态增长的数组
//优点 : 随机访问 operator[]->很好的支持排序、二分查找、堆算法的等等
//缺点 : 头部或者中间的插入删除效率低 + 空间不够了以后增容的代价较大

//list是一个带头双向循环的链表
//优点:任意位置插入删除数据效率高，0(1)
//缺点 : 不支持随机访问
//总结 : vector和list是两个相辅相成，互补的容器
