#include<iostream>
#include<unordered_map>
#include<unordered_set>
#include<map>
#include<set>
#include<vector>
#include<time.h>

using namespace std;

//unordered：没有次序的，无序的
//unordered_map & unordered_set底层都是使用哈希实现的

void test_unordered_map()
{
	//去重， 无序
	unordered_map<string, string> um;
	um.insert(make_pair("int", "iii"));
	um.insert(make_pair("string", "ssss"));
	um["char"] = "cccc";
	um["string"] = "cccc";
	unordered_map<string, string>::iterator umit = um.begin();
	while (umit != um.end())
	{
		cout << umit->first << "  " << umit->second << endl;
		++umit;
	}

	cout << endl;

	//去重+有序
	map<string, string> m;
	m.insert(make_pair("int", "iii"));
	m.insert(make_pair("string", "ssss"));
	m["char"] = "cccc";
	m["string"] = "cccc";
	map<string, string>::iterator mit = m.begin();
	while (mit != m.end())
	{
		cout << mit->first << "  " << mit->second << endl;
		++mit;
	}
}
void test_unordered_set()
{
	//去重， 无序
	unordered_set<int> uset;
	uset.insert(4);
	uset.insert(4);
	uset.insert(4);
	uset.insert(4);
	uset.insert(2);
	uset.insert(1);
	uset.insert(7);
	uset.insert(10);

	unordered_set<int>::iterator uit = uset.begin();
	while (uit != uset.end())
	{
		cout << *uit <<"  ";
		uit++;
	}
	cout << endl;

	//去重+有序
	set<int> st;
	st.insert(4);
	st.insert(4);
	st.insert(4);
	st.insert(4);
	st.insert(2);
	st.insert(1);
	st.insert(7);
	st.insert(10);

	set<int>::iterator it = st.begin();
	while (it != st.end())
	{
		cout << *it << "  ";
		++it;
	}
}

/*
map/set和unordered_map/unordered set 有什么区别和联系?
1、他都可以可以实现key和key/value的搜索场景，并且功能和使用基本一样。
2、map/set的底层是使用红黑树实现的，遍历出来是有序的，增删查改的时间复杂度是0(logN)
3、unordered_map/unordered_set的底层是使用哈希表实现的，遍历出来是无序的，增删查改的时间复杂度是0(1)
4、map和set是双向迭代器，unordered_map和unorded_set是单向迭代器
*/

//性能测试
void test_op()
{
	unordered_set<int> us;
	set<int> s;
	int n = 100000;
	vector<int> vec;
	vec.reserve(n);
	srand(time(0));
	for (int i = 0; i < n ; ++i)
	{
		vec.push_back(rand());
	}

	size_t begin1 = clock();
	for (auto au : vec)
	{
		us.insert(au);
	}
	size_t end1 = clock();
	cout << "unordered_set insert:" << end1 - begin1 << endl;

	size_t begin2 = clock();
	for (auto au : vec)
	{
		s.insert(au);
	}
	size_t end2 = clock();
	cout << "set insert:" << end2 - begin2 << endl;

	size_t begin3 = clock();
	for (auto au : vec)
	{
		us.find(au);
	}	
	size_t end3 = clock();
	cout << "unordered_set find:" << end3 - begin3 << endl;

	size_t begin4 = clock();
	for (auto au : vec)
	{
		s.find(au);
	}
	size_t end4 = clock();
	cout << "set find:" << end4 - begin4<< endl;

	size_t begin5 = clock();
	for (auto au : vec)
	{
		us.erase(au);
	}
	size_t end5 = clock();
	cout << "unordered_set erase:" << end5 - begin5 << endl;

	size_t begin6 = clock();
	for (auto au : vec)
	{
		s.erase(au);
	}
	size_t end6 = clock();
	cout << "set erase:" << end6 - begin6 << endl;

}
int main()
{
	//test_unordered_map();
	//test_unordered_set();

	test_op();
	return 0;
}

