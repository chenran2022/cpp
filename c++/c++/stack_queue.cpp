#include<stack>
#include<queue>
#include<iostream>
#include<assert.h>
using namespace std;
#include<list>
#include<vector>
#include<functional>  //仿函数
#include<deque>  
//双端队列
//支持任意位置插入删除，也支持随机访问，
//也就是说它既有vector的优点，也有list的优点看起来好像可以替代vector和list的一个容器
//但是实际上随机访问的效率很低，低于vector。 
//头部和尾部操作性能高：O(1),增容代价小
//deque并不是真正连续的空间，而是由一段段连续的小空间拼接而成的，实际deque类似于一个动态的二维数组，
//deque的缺陷：
//与vector比较，deque的优势是：头部插入和删除时，不需要搬移元素，效率特别高，而且在扩容时，也不需要搬移大量的元素，因此其效率是必vector高的。
//与list比较，其底层是连续空间，空间利用率比较高，不需要存储额外字段。
//但是，deque有一个致命缺陷：不适合遍历，
//因为在遍历时，deque的迭代器要频繁的去检测其是否移动到某段小空间的边界，导致效率低下，
//而序列式场景中，可能需要经常遍历，因此在实际中，需要线性结构时，
//大多数情况下优先考虑vector和list，deque的应用并不多，
//而目前能看到的一个应用就是，STL用其作为stack和queue的底层数据结构：
//1.stack和queue不需要遍历(因此stack和queue没有迭代器)，只需要在固定的一端或者两端进行操作。
//2. 在stack中元素增长时，deque比vector的效率高(扩容时不需要搬移大量数据)；queue中的元素增长时，deque不仅效率高，而且内存使用率高。


//stack 、queue 、priority_queue没有迭代器，因为他们有特殊的性质，属于STL的第二类 容器适配器(通过容器进行适配转换)
 
void test_stack()
{
	stack<int> st;
	st.push(1);
	st.push(2);
	st.push(3);
	st.push(4);

	while (!st.empty())
	{
		cout << st.top() << " ";
		st.pop();
	}
	cout << endl;
}

void test_queue()
{
	queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.push(4);
	while (!q.empty())
	{
		cout << q.front() << " ";
		q.pop();
	}
	cout << endl;
}
void test_priority_queue()
{
	//priority_queue<int> pq;						//默认大的优先级高
	priority_queue<int,vector<int>,greater<int>> pq;//想要实现小的优先级高，要使用仿函数
	pq.push(1);
	pq.push(20);
	pq.push(3);
	pq.push(40);
	pq.push(1);
	pq.push(100);
	pq.push(1);
	while (!pq.empty())
	{
		cout << pq.top() << "  ";
		pq.pop(); 
	}
	cout << endl;
}
int main()
{
	/*test_stack();
	test_queue();*/
	test_priority_queue();
	return 0;
}

//
//namespace cr
//{
//	template<class T,class Container>
//	class stack
//	{
//	public:
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//		void pop()
//		{
//			_con.pop_back();
//		}
//		T& top()
//		{
//			return _con.back();  //容器的最后一个元素直接引用
//		}
//		bool empty()
//		{
//			return _con.empty();
//		}
//		int size()
//		{
//			return _con.size();
//		}
//	private:
//		Container _con;
//	};
//
//	void test_stack1()
//	{
//		//cr::stack<int, vector<int>> st;
//		//cr::stack<int, list<int>> st;
//		cr::stack<int, deque<int>> st;
//		st.push(1);
//		st.push(2);
//		st.push(3);
//		st.push(4);
//		
//		while (!st.empty())
//		{
//			cout << st.top() << "  ";
//			st.pop();
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	cr::test_stack1();
//	return 0;
//}


//
//namespace cr
//{
//	template<class T,class Container>
//	class queue
//	{
//	public:
//		void push(const T& x)
//		{
//			_con.push_back(x);
//		}
//		void pop()
//		{
//			_con.pop_front();
//		}
//		T& top()
//		{
//			return _con.back();  //容器的最后一个元素直接引用
//		}
//		T& front()
//		{
//			return _con.front(); //容器的第一个元素直接引用
//		}
//		bool empty()
//		{
//			return _con.empty();
//		}
//		int size()
//		{
//			return _con.size();
//		}
//	private:
//		Container _con;
//	};
//
//	void test_queue1()
//	{
//		//cr::queue<int, vector<int>> q;  //queue不能使用vector，因为vector没有提供pop_front接口
//		//cr::queue<int, list<int>> q;
//		cr::queue<int, deque<int>> q;
//		q.push(1);
//		q.push(2);
//		q.push(3);
//		q.push(4);
//		
//		while (!q.empty())
//		{
//			cout <<	q.front() << "  ";
//			q.pop();
//		}
//		cout << endl;
//	}
//}
//int main()
//{
//	cr::test_queue1();
//	
//	return 0;
//}


