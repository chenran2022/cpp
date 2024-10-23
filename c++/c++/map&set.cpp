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
#include<string>
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
3. 在内部，map中的元素总是按照键值key进行比较排序的。(string按ascll码值比较大小排序)
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
}

void test_map2()
{
	map<string, string> m1;
	m1.insert(pair<string, string>("sort", "排序"));
	m1.insert(make_pair("dog", "狗"));
	m1.insert(make_pair("son", "kong"));

	map<string, string>::iterator it = m1.begin();
	while (it != m1.end())
	{
		cout << it->first << ":" << it->second << endl;
		++it;
	}
}
void test_map3()
{
	string arr[] = { "苹果", "西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "香蕉", "苹果", "香蕉" };
	map<string, int> countTree;
	for (const auto& str : arr)
	{
		map<string, int>::iterator ret = countTree.find(str);
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
	cout << endl;


	string arr3[] = { "苹果", "苹果","西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "西瓜","香蕉", "苹果", "香蕉","香蕉" };
	map<string, int> m3;
	for (auto& au : arr3)
	{
		//1.如果水果没有在map中，则插入成功。bool为true
		//2.如果水果已经在map中，插入失败，bool为false，通过返回值得到水果所在的节点迭代器，++次数
		pair<map<string, int>::iterator, bool> ret = m3.insert(make_pair(au, 1));
		if (ret.second == false)
		{
			ret.first->second++;
		}
	}
	for (auto& au : m3)
	{
		cout << au.first << ":" << au.second << endl;
	}
	cout << endl;


	//使用[]统计次数，[]内是key的值，返回的是key所对应的value值
	string arr2[] = { "苹果", "苹果","西瓜", "苹果", "西瓜", "苹果", "苹果", "西瓜",
	"苹果", "西瓜","香蕉", "苹果", "香蕉","香蕉" };
	map<string, int> countMap2;
	for (auto& au : arr2)
	{
		countMap2[au]++;	
		//[]内是key的值，返回的是key所对应的value值
		//1.如果水果不在map中，则插入pair<string,int()>,即pair<au,0>;返回映射对象(value)的引用，再++
		//2.如果水果在map中，插入失败，返回string所在映射对象(value)的引用，再++
	}
	for (auto& au : countMap2)
	{
		cout << au.first << ":" << au.second << endl;
	}
	cout << endl;

	//[]的原理：insert
	/*
	mapped_type& operator[](const key_type& k)
	{
		return ((this->insert(make_pair(k, mapped_type()))).first)->second;
		return (*((this->insert(make_pair(k, mapped_type()))).first)).second;
	}
	mapped_type是value的类型的宏定义
	this->insert(make_pair(k, mapped_type()))  --》 pair<iterator,bool>
	this->insert(make_pair(k, mapped_type()))).first	--》 iterator/pair<first,second>/pair<key_type,mapped_type)
	(*((this->insert(make_pair(k, mapped_type()))).first)).second  --》 mapped_type

	这里不是用find实现，而是用insert实现
	假如用find，如果map中没有k，该如何实现？
	用insert实现
	1.如果k不在map中，则插入pair<k,mapped_type()>,再返回映射对象的引用
	2.如果k在map中，则插入失败，返回k所在节点中的映射对象的引用

	map的operator[]作用：
	1.插入
	2.查找k对应的映射对象
	3.修改k对用的映射对象
	*/

	countMap2["橘子"];//插入
	countMap2["橘子"] = 3; //修改k对用的映射对象
	cout << countMap2["橘子"] << endl;//查找k对应的映射对象
	countMap2["梨"] = 5;//插入+修改
	//一般用operator[]来插入+修改，不用查找是因为如果k不存在，就会插入数据
}
/*
map总结：
增：insert  operator[]
删：erase
改：operator[]
查：find	一般不用operator[]
遍历：iterator  范围for	（注意在map中存的是pair<k,v>键值对）
*/
int main()
{
	//test_set();
	//test_map();
	//test_map2();
	test_map3();
	return 0;
}



