/*
STL中的部分容器，比如：vector、list、deque、forward_list(C++11)等，
这些容器统称为序列式容器，因为其底层为线性序列的数据结构，里面存储的是元素本身。
那什么是关联式容器？它与序列式容器有什么区别？
关联式容器也是用来存储数据的，与序列式容器不同的是，
其里面存储的是<key, value>结构的键值对，在数据检索时比序列式容器效率更高
*/

#include<iostream>
#include<set>
#include<map>
using namespace std;

/*
1. set是按照一定次序存储元素的容器
2. 在set中，元素的value也标识它(value就是key，类型为T)，并且每个value必须是唯一的。
	set中的元素不能在容器中修改(元素总是const)，但是可以从容器中插入或删除它们。
3. 在内部，set中的元素总是按照其内部比较对象(类型比较)所指示的特定严格弱排序准则进行排序。
4. set容器通过key访问单个元素的速度通常比unordered_set容器慢，但它们允许根据顺序对子集进行直接迭代。
5. set在底层是用二叉搜索树(红黑树)实现的。
*/
//set特点：快  增删查：O(logN)	 不允许修改
void test_set()
{
	set<int> s;
	s.insert(6);
	s.insert(2);
	s.insert(10);
	s.insert(8);
	s.insert(6);
	s.insert(1);

	//排序＋去重	set底层是一个搜索二叉树，使用InOrder中序遍历进行排序
	set<int>::iterator it = s.begin();
	while (it != s.end())
	{
		//*it = 1;//不允许修改
		cout << *it++ << "  ";
	}
	cout << endl;

	for (auto au : s)
	{
		cout << au << "  ";
	}
	cout << endl;

	set<int> copy(s);
	for (auto au : copy)
	{
		cout << au << "  ";
	}
	cout << endl;

	set<int>::iterator pos = s.find(8); //搜索二叉树的查找：O(logN)
	//set<int>::iterator pos = find(s.begin(), s.end(), 8);//算法里的查找:O(N) ,效率低
	if (pos != s.end())
	{
		s.erase(pos); //使用迭代器删除时不能传入end()，否则报错
	}
	//使用数据对象传值删除，如果没有这个值就不删除，不报错
	int i = 10;
	s.erase(i);
	s.erase(100);

	for (auto au : s)
	{
		cout << au << "  ";
	}
	cout << endl;
}


/*
1. map是关联容器，它按照特定的次序(按照key来比较)存储由键值key和值value组合而成的元素。
2. 在map中，键值key通常用于排序和惟一地标识元素，而值value中存储与此键值key关联的内容。
键值key和值value的类型可能不同，并且在map的内部，key与value通过成员类型value_type绑定在一起，
为其取别名称为pair: typedef pair<const key, T> value_type;
template <class T1, class T2>
struct pair
{
	typedef T1 first_type;
	typedef T2 second_type;
	T1 first;
	T2 second;
	pair(): first(T1()), second(T2())
	{}
	pair(const T1& a, const T2& b): first(a), second(b)
	{}
};
3. 在内部，map中的元素总是按照键值key进行比较排序的。
4. map中通过键值访问单个元素的速度通常比unordered_map容器慢，
但map允许根据顺序对元素进行直接迭代(即对map中的元素进行迭代时，可以得到一个有序的序列)。
5. map支持下标访问符，即在[]中放入key，就可以找到与key对应的value。
6. map通常被实现为二叉搜索树(更准确的说：平衡二叉搜索树(红黑树))。
*/
void test_map()
{
	map<int, int> m;
	//m.insert(1, 1); //不能这样插入
	m.insert(pair<int, int>(1, 1));
	m.insert(pair<int, int>(3, 3));
	m.insert(pair<int, int>(2, 2));//pair的构造函数，构造出一个匿名对象
	m.insert(make_pair(10, 10));//make_pair是一个函数模板，返回值是一个pair对象，优点是不用声明模板参数。可以自动推演

	map<int, int>::iterator it = m.begin();
	while (it != m.end())
	{
		//cout << *it << endl; //报错，因为这里的*it是pair<const key, T>，没有重载输出
		cout << (*it).first << "-" << (*it).second << endl;
		cout << it->first << "-" << it->second << endl;
		//operator->返回值的是节点中值的指针，即pair<const key, T>*，而it->->first可读性差，所以编译器优化了，省略一个->
		++it;
	}
	cout << endl;

	for (auto& au : m)
	{
		cout << au.first << "-" << au.second << endl;
	}

	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉" };
	map<string,int> countTree;
	for (const auto& str : arr)
	{
		map<string,int>::iterator ret = countTree.find(str);
		if (ret == countTree.end())
		{
			countTree.insert(make_pair(str, 1));
		}
		else
		{
			ret->second++;
		}
	}
	for (auto& au : countTree)
	{
		cout << au.first << "-" << au.second << endl;
	}
}

int main()
{
	//test_set();
	test_map();
	return 0;
}
