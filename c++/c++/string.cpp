//STL  标准模板库

#include <iostream>
#include<string>
using namespace std;



//int main()
//{
//	string s1;
//	string s2("hfdsjak");
//	string s3(s2);
//	string s4 = "dfsa";	//编译器会优化成类似于s2
//	string s6 = s4;
//
//	string s5(10, 'a'); //初始化为n个字符的字符串
//	string s7("fsafasf", 4);//初始化为字符串的前n个字符
//	string s8(s2, 1, 4);//从string字符串的某个位置起指定长度拷贝初始化
//	string s9(s2, 1);
//	string s10(s2, 1, string::npos);
//	//9、10一样，9有个缺省默认值npos,到字符串结尾
//
//	cout << s5 << endl;
//	cout << s7 << endl;
//	cout << s8 << endl;
//	cout << s9 << endl;
//	cout << s10 << endl;
//
//	cout << s1 << endl;
//	cout << s2 << endl;
//	cout << s3 << endl;
//	cout << s4 << endl;
//	cout << s6 << endl;
//	return 0;
//}


//int main()
//{
//	//string s("12345");
//	//s.push_back('6');//push_back只能尾插一个字符
//	//cout << s << endl;
//	//s.append("789");//append可以尾插字符串
//	//cout << s << endl;
//
//	////+=既可以尾插一个字符，也可以尾插字符串
//	//s += '1';
//	//cout << s << endl;
//	//s += "12345";
//	//cout << s << endl;
//
//
//	//将数字字符串转成整型
//	string s("123412");
//	int tmp = 0;
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		tmp *= 10;
//		tmp += (s[i]-'0');//字符数字转为整形
//	}
//	cout << tmp;
//
//	return 0;
//}




//迭代器不一定是指针，像指针一样的东西
//迭代器分为四种：
//			方向：正向和反向
//			属性：普通和const
//
//int str2int(const string& str)
//{
//	//str被const修饰，str.begin返回的是const_inerator
//	//string::iterator it = str.begin();
//	string::const_iterator it = str.begin();
//	//const_inerator只能读，不能写
//	int num = 0;
//	while (it != str.end())
//	{
//		//*it = 1;//不能写
//		num *= 10;
//		num += (*it-'0');
//		++it;
//	}
//
//	//逆向const迭代器
//	//auto ri = str.rbegin();
//	string::const_reverse_iterator ri = str.rbegin();
//	int num2 = 0;
//	while (ri != str.rend())
//	{
//		//*ri = 1;//不能写
//		num2 *= 10;
//		num2 += (*ri - '0');
//		++ri;
//	}
//	return num2;
//}
//int main()
//{
//	string s("hello");
//	//[]+下标 
//	//写
//	size_t i = 0;
//	for (; i < s.size(); ++i)
//	{
//		s[i] += 1;
//	}
//	//读
//	for (i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//
//	//迭代器
//	//写
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		*it -= 1;
//		++it;
//	}
//
//	//读
//	it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " " ;
//		++it;
//	}
//	cout << endl;
//	//范围for  
//	//C++11  原理-》被替换成迭代器
//	for (auto au : s)
//	{
//		cout  << au << " ";
//	}
//	cout << endl;
//
//	//逆向迭代器,逆向访问
//	string::reverse_iterator ri = s.rbegin();
//	while (ri != s.rend())
//	{
//		cout << *ri << " ";
//			++ri;
//	}
//
//	cout << endl;
//	string nums("12345");
//	cout << str2int(nums) << endl;
//
//	return 0;
//}



//int main()
//{
//	string s("hello");
//	string s2("fdsafsa");
//	cout << s.size() << endl;
//	cout << s.length() << endl;
//	cout << s2.size() << endl;
//	cout << s2.length() << endl;
//
//	cout << s.max_size() << endl;//没什么意义
//
//	cout << s.capacity() << endl;
//	cout << s2.capacity() << endl;
//
//	s2 += "fasfsdfas";
//	cout << s2.capacity() << endl;
//
//	s2.clear();
//	cout << s2.capacity() << endl;
//	cout << s2.size() << endl;
//
//	return 0;
//}



//int main()
//{
//	string s;
//	//s.reserve(100);//修改capacity,不会修改size
//	//cout << "size" << s.size() << endl;
//
//	//s.resize(100);//修改size,capacity不够也会增大capacity
//	//cout << s.size() << " " << s.capacity() << endl;
//	//s.resize(5, 'a');
//	//cout << s << endl;
//	//cout << s.size() << " " << s.capacity() << endl;
//	//s.resize(10,'2');
//	//cout << s << endl;
//	//cout << s.size() << " " << s.capacity() << endl;
//
//	int cp = s.capacity();
//	int i = 0;
//	for (; i < 100; ++i)
//	{
//		s.push_back('w');
//		if (s.capacity() != cp)
//		{
//			cout << "newcp:" << s.capacity() << endl;
//			cp = s.capacity();
//		}
//	}
//	return 0;
//}


//int main()
//{
//	string s("1231");
//	//在指定位置插入
//	s.insert(s.begin(), '0');
//	cout << s << endl;
//	s.insert(2, "wht");
//	cout << s << endl;
//
//	/*s.erase(5);
//	cout << s << endl;*/
//	s.erase(2, 3);//从第二个位置删除三个字符
//	cout << s << endl;
//	s.erase();
//	cout << s << endl;
//
//	return 0;
//}


