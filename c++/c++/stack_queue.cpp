#include<stack>
#include<queue>
#include<iostream>
#include<assert.h>
using namespace std;

//stack 和 queue 没有迭代器， 属于STL的第二类 容器适配器
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
int main()
{
	test_stack();
	test_queue();
	
	return 0;
}
