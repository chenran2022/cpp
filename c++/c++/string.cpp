//STL  标准模板库

#include<iostream>
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
//	s.resize(100);//修改size,capacity不够也会增大capacity
//	//如果n大于当前的容器大小，则通过在容器结尾插入(inserting)适合数量的元素使得整个容器大小达到n。
//	//且如果给出val，插入的新元素全为val，否则，执行默认构造函数。
//	cout << s.size() << " " << s.capacity() << endl;
//	s.resize(5, 'a');
//	cout << s << endl;
//	cout << s.size() << " " << s.capacity() << endl;
//	s.resize(10,'2');
//	cout << s << endl;
//	cout << s.size() << " " << s.capacity() << endl;
//	cout << s[1] << "    " << s[5] << endl;
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
//	s.erase(5);
//	cout << s << endl;
//	s.erase(2, 3);//从第二个位置删除三个字符
//	cout << s << endl;
//	s.erase();
//	cout << s << endl;
//
//	return 0;
//}


//int main()
//{
//	string str("hello");
//	//获取字符数组首地址，用C字符串的形式遍历
//	const char* ch = str.c_str();
//	while (*ch)
//	{
//		cout << *ch << " " ;
//		++ch;
//	}
//	cout << endl;
//
//	cout << str << endl;//调用的是string的operator<<
//	cout << str.c_str() << endl;//直接输出const char*
//
//
//	str += '\0';
//	str += "world";
//
//	cout << str << endl;//调用的是string的operator<<	将对象数组中所有字符输出
//	cout << str.c_str() << endl;//直接输出const char*	遇到\0结束
//
//	//ascii码表（早期计算机只表示英文） 值和字母标点等的映射关系
//	//unsigned char  0-255
//	//编码表	值和表示符号（字母或者文字）映射关系
//
//	//计算机普及到全世界，需要表示很多国家的文字
//	//unicode是计算机科学领域里的一项业界标准，包括字符集、编码方案
//	//utf8  utf16  utf32
//	//linux utf8
//	//windows  gbk(中国自己制定的,把中文输进去)
//
//	/*char ch2[] = "中国";
//	cout << ch2 << endl;
//	ch2[1] = -47;
//	cout << ch2 << endl;
//	ch2[1] = -46;
//	cout << ch2 << endl;
//	ch2[1] = -48;
//	cout << ch2 << endl;*/
//	return 0;
//}


 //int main()
 //{
 //    string s1("www.test");
 //    string s2("sfkaj.cpp");
 //    string s3("test.c");
 //    string s4("s4.cpp.zip");


 //    //find 寻找某个字符的下标位置，找不到返回string::npos  size_t npos = -1;
 //    size_t pos1 = s1.find('.');
 //    if(pos1!=string::npos)
 //    {
 //        //substr()是C++语言函数，主要功能是复制子字符串，要求从指定位置开始，并具有指定的长度
 //        cout<<s1.substr(pos1)<<endl;
 //    }
 //    size_t pos2 = s2.find('.');
 //    if(pos2!=string::npos)
 //    {
 //        cout<<s2.substr(pos2)<<endl;
 //    }
 //    size_t pos3 = s3.find('.');
 //    if(pos3!=string::npos)
 //    {
 //        cout<<s3.substr(pos3)<<endl;
 //    }

 //    //rfind是从后往前找
 //    size_t pos4 = s4.rfind('.');
 //    if(pos4!=string::npos)
 //    {
 //        cout<<s4.substr(pos4)<<endl;
 //    }

 //    //协议  域名  资源名称
 //    string url("https://github.com/chenran2022?tab=repositories");
 //    //分离url  协议  域名  资源名称
 //    size_t i1=url.find(':');
 //    if(i1!=string::npos)
 //    {
 //        cout<<url.substr(0,i1)<<endl;
 //    }
 //    size_t i2=url.find('/',i1+3);
 //    cout<<i1<<"   "<<i2<<endl;
 //    if(i2!=string::npos)
 //    {
 //        cout<<url.substr(i1+3,i2-(i1+3))<<endl;;
 //    }
 //    string tmp = url.substr(i1 + 3, i2 - (i1 + 3));
 //    cout << tmp << endl;
 //    cout<<url.substr(i2+1)<<endl;
 //    return 0;
 //}


// int main()
// {
//     string s1("hello");
//     string test1=s1+"wrold";    //+不改变变量本身，返回临时变量，效率低
//     cout<<s1<<"     "<<test1<<endl;
//     string test2=s1+="world";   //+=改变变量本身，返回本身
//     cout<<s1<<"     "<<test2<<endl;

//     //字符串比较
//     string str1("abcd");
//     string str2("bbcd");
//     cout<<(str1<str2)<<endl;
//     cout<<(str1<"bbcd")<<endl;
//     cout<<("bbcd"<str1)<<endl;
//     return 0;
// }



// //输出一句英语的最后一个单词的长度，每个单词以空格隔开
// int main()
// {
//     string s;
//     //cin>>s; //cin和scanf  遇到空白字符（空格、tab、换行）就停止
//     getline(cin,s);//遇到换行结束

//     size_t pos = s.rfind(' ');
//     cout<<s.size()-(pos+1)<<endl;
//     return 0;
// }

// namespace cr
// {
//     class string
//     {
//         public:
//             string():_str(nullptr)
//             {

//             }
//             string(char* str):_str(str)
//             {

//             }
//             size_t size()
//             {
//                 return strlen(_str);
//             }
//             char& operator[](size_t i)
//             {
//                 return _str[i];
//             }
//         private:
//             char* _str;
//     };
//     void test()
//     {
//         string s1("hello");
//         string s2;
//         for(size_t i=0;i<s1.size();++i)
//         {
//             // s1[i]+=1; 
//             //"hello"是代码段，不能被修改，会报错
//             //所以要在堆区开辟空间存放数据内容
//             cout<<s1[i]<<"  ";
//         }
//         cout<<endl;
//     }
// }
// int main()
// {
//     cr::test();
//     return 0;
// }


//namespace cr
//{
//    class string
//    {
//    public:
//         /*string():_str(nullptr)
//         {
//
//         }*/
//         /*string():_str(new char[1])
//         {
//             _str[0]='\0';
//         }*/  //全缺省可以省去
//
//         //string(char* str):_str(new char[strlen(str)+1])  //+1 是因为string对象中存储指针，指针指向的数组中存储字符，字符最后必须保留\0
//         //{
//         //    strcpy(_str,str);
//         //}
//        string(const char* str = ""):_str(new char[strlen(str)+1])  //+1 是因为string对象中存储指针，指针指向的数组中存储字符，字符最后必须保留\0
//        {
//            strcpy(_str, str);
//        }
//
//        string(const string& str):_str(new char[strlen(str._str)+1])
//        {
//			strcpy(_str, str._str);
//        }
//        ~string()
//        {
//            delete[] _str;
//            _str = nullptr;
//        }
//        size_t size()
//        {
//            return strlen(_str);
//            //strlen是直接解引用找'\0', 当_str为空指针的时候，就会报错, 所以默认构造函数要存一个\0
//        }
//        char& operator[](size_t i)
//        {
//            return _str[i];
//        }
//        const char* c_str()
//        {
//            return _str;
//        }
//        /*void operator=(const string& str)
//        {
//            if (this != &str)//防止自己给自己赋值
//            {
//                delete[] _str;
//                _str = new char[(strlen(str._str) + 1)];
//                strcpy(_str, str._str);
//            }
//        }*/
//        string& operator=(const string& str)
//        {
//            if (this != &str)//防止自己给自己赋值
//            {
//                delete[] _str;
//                _str = new char[(strlen(str._str) + 1)];
//                strcpy(_str, str._str);
//            }
//            return *this;
//        }
//    private:
//        char* _str;
//    };
//    void test1()
//    {
//        string s1("hello");
//        string s2;
//        for (size_t i = 0; i < s1.size(); ++i)
//        {
//            s1[i] += 1;
//
//            cout << s1[i] << "  ";
//        }
//        cout << endl;
//        for (size_t i = 0; i < s2.size(); ++i)
//        {
//            s2[i] = s1[i];
//
//            cout << s2[i] << "  ";
//        }
//        cout << endl;
//
//    }
//
//    void test2()
//    {
//        string s1("hello");
//        string s2(s1);  //浅拷贝会造成在析构函数里重复释放同一块空间
//        cout << s1.c_str() << endl;
//        cout << s2.c_str() << endl;
//        string s3("world11");
//        s2 = s1 = s3;
//        cout << s2.c_str() << endl;
//    }
//}
//int main()
//{
//     //cr::test1();
//    cr::test2();
//    return 0;
//}



//
////实现增删查改的string
//#include<assert.h>
//namespace cr
//{
//	class string
//	{
//	public:
//		typedef char* iterator;
//		iterator begin()
//		{
//			return _str;
//		}
//		iterator end()
//		{
//			return _str + _size;
//		}
//		friend istream& operator>>(istream& cin, string& str);
//		string(const char* str = "") :_str(new char[strlen(str) + 1])
//		{
//			_size = strlen(str);	//已经有多少个有效字符
//			_capacity = _size;    //能存多少个有效字符，'\0'不是又是有效字符，所以不+1
//			strcpy(_str, str);
//		}
//
//		//深拷贝  —— 传统写法
//		/*string(const string& str):_str(new char[strlen(str._str) +1])
//		{
//			strcpy(_str, str._str);
//		}*/
//		
//		//深拷贝—— 现代写法
//		string(const string& str) :_str(nullptr),_size(0),_capacity(0)
//		{
//			string tmp(str._str);
//			this->Swap(tmp);
//		}
//		~string()
//		{
//			delete[] _str;
//			_str = nullptr;
//			_size = _capacity = 0;
//		}
//		size_t size()const
//		{
//			return _size;
//		}
//		size_t capacity()const
//		{
//			return _capacity;
//		}
//		const char* c_str() const
//		{
//			return _str;
//		}
//		char& operator[](size_t i)
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//		const char& operator[](size_t i) const 
//		{
//			assert(i < _size);
//			return _str[i];
//		}
//
//		//赋值运算符重载——传统写法
//		/*string& operator=(const string& str)
//		{
//			if (this != &str)
//			{
//				delete[] _str;
//				_str = new char[str.size() + 1];
//				strcpy(_str, str._str);
//			}
//			return *this;
//		}*/
//
//		//赋值运算符重载——现代写法  --简洁
//		string& operator=(string str)
//		{
//			//1.
//			//if (this != &str)
//			//{
//			//	string tmp(str);  //已经实现了拷贝构造
//			//	this->Swap(tmp);
//			//}
//
//			//2.更简洁
//			this->Swap(str);
//			return *this;
//		}
//		void Swap(string& s)
//		{
//			swap(_str,s._str);
//			swap(_size, s._size);
//			swap(_capacity, s._capacity);
//			
//		}
//		void reserve(size_t n)		//将容量扩展到n
//		{
//			if (n > _capacity)
//			{
//				char* newstr = new char[n + 1];
//				strcpy(newstr, _str);
//				delete[] _str;
//				_str = newstr;
//				_capacity = n;
//			}
//		}
//
//		void resize(size_t n, char ch = '\0')   //将扩大的空间内容用字符ch填补
//		{
//			if (n < _size)
//			{
//				_size = n;
//				_str[n] = '\0';
//			}
//			else
//			{
//				if (n > _capacity)
//				{
//					reserve(n);
//				}
//				int i = _size;
//				for (; i < n; i++)
//				{
//					_str[i] = ch;
//				}
//				_size = n;
//				_str[n] = '\0';
//			}
//		}
//		void push_back(const char ch)
//		{
//			//空间满了进行增容
//			if (_size == _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
//				/*char* newstr = new char[newcapacity + 1];
//				strcpy(newstr, _str);
//				delete[] _str;
//				_str = newstr;
//				_capacity = newcapacity;*/
//				reserve(newcapacity);
//			}
//			_str[_size] = ch;
//			_size++;
//			_str[_size] = '\0';  //注意！！！
//		}
//		void append(const char* str)
//		{
//			//空间不够了进行增容
//			int len = strlen(str);
//			if (_size + len > _capacity)
//			{
//				size_t newcapacity = _size + len;
//				/*char* newstr = new char[newcapacity + 1];
//				strcpy(newstr, _str);
//				delete[] _str;
//				_str = newstr;
//				_capacity = newcapacity;*/
//				reserve(newcapacity);
//
//			}
//			strcpy(_str + _size, str);
//			_size += len;
//		}
//		string& operator+=(const char ch)
//		{
//			this->push_back(ch);
//			return *this;
//		}
//		string& operator+=(const char* str)
//		{
//			
//			this->append(str);
//			return *this;
//		}
//		string& insert(size_t pos, char ch)  //下标为pos
//		{
//			//assert(pos < _size);	//不能在最后一位插入
//			assert(pos <= _size);
//			if (_size == _capacity)
//			{
//				size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
//				reserve( newcapacity );
//			}
//			if (pos == _size)
//			{
//				_str[pos + 1] = '\0';
//			}
//			int n = _size;
//			while (n > pos)
//			{
//				_str[n] = _str[n-1];
//				--n;
//			}
//			_str[pos] = ch;
//			_size++;
//			return *this;
//			
//		}
//		string& insert(size_t pos, const char* str)	//下标为pos
//		{
//			assert(pos <= _size);
//			size_t len = strlen(str);
//			
//			if ((_size + len) >= _capacity)
//			{
//				size_t newcapacity = _size + strlen(str);
//				reserve(newcapacity);
//			}
//			if (pos == _size)
//			{
//				*this += str;
//			}
//			else
//			{
//				int n = _size;
//				while (n >=(int)pos)  //pos是size_t类型的，在比较时会把n的类型转换为size_t再比较
//				{
//					_str[n + len] = _str[n];
//					--n;
//				}
//
//				//把str加到_str中，不能用strcpy，因为strcpy会拷贝\0 ,可以使用strncpy指定个数
//
//				/*int i = 0;
//				while (i < len)
//				{
//					_str[n] = str[i];
//					n++;
//					i++;
//				}*/
//				strncpy(_str + pos, str, len);
//				_size += len;
//				return *this;  
//			}
//			
//		}
//		void erase(size_t pos, size_t len = npos)
//		{
//			assert(pos < _size);
//			if (len >= (_size - pos))  //删除的个数大于等于pos后所有有效字符个数
//			{
//				_str[pos] = '\0';
//				_size = pos;
//			}
//			else
//			{
//				size_t i = pos;
//				for (; i <=(_size-len); i++)
//				{
//					_str[i] = _str[i + len];
//
//				}
//				_size -= len;
//			}
//		}
//		size_t find(char ch, size_t pos = 0)
//		{
//			
//			for (size_t i = pos; i < _size; i++)
//			{
//				if (ch == _str[i])
//					return i;
//			}
//			return npos;
//		}
//		size_t find(const char* str, size_t pos = 0)
//		{
//			/*int len = strlen(str);
//			for (size_t i = pos; i <= _size - len; i++)
//			{
//				if (_str[i] == str[0])
//				{
//					int j = 1;
//					for (j = 1; j < len; j++)
//					{
//						if (_str[i + j] != str[j])
//							break;
//					}
//					if (j == len)
//						return i;
//				}
//			}
//			return npos;*/
//
//			char* ch = strstr(_str + pos, str);
//			if (ch == nullptr)
//			{
//				return npos;
//			}
//			else
//			{
//				return ch - _str;
//			}
//		}
//
//		bool operator<(const string& str)
//		{
//			//_str<str._str
//			return strcmp(_str, str._str) < 0;
//		}
//		bool operator==(const string& str)
//		{
//			return strcmp(_str, str._str) == 0;
//		}
//		/*bool operator>(const string& str)
//		{
//			return strcmp(_str, str._str) > 0;
//		}*/
//		bool operator>(const string& str)
//		{
//			return !(*this <= str);
//		}
//		bool operator<=(const string& str)
//		{
//			//return (strcmp(_str, str._str) == 0)||(strcmp(_str, str._str) > 0);
//			return *this < str || *this == str;
//		}
//		bool operator>=(const string& str)
//		{
//			return !(*this < str);
//		}
//		bool operator!=(const string& str)
//		{
//			return !(*this == str);
//		}
//	private:
//		char* _str;
//		size_t _size;		//已经有多少个有效字符
//		size_t _capacity;	//能存多少个有效字符，'\0'不是有效字符
//		static size_t npos;
//
//	};
//	size_t string::npos = -1;
//	istream& operator>>(istream& cin, string& str)
//	{
//		if (str._size != 0)  //默认的cin会把原有值覆盖掉
//		{
//			/*delete[] str._str;*/  //不能这么释放空间，因为后面会对_str进行赋值，会造成内存泄漏
//			str._str[0] = '\0';
//			str._size = 0;
//		}
//		while (1)
//		{
//			char ch;
//			//cin >> ch;  //cin会自动把空白字符过滤掉，认为输入下一个变量，所以cin不会接收到空白字符
//			ch = cin.get();  //可以接受空白字符
//			if (ch == ' ' || ch == '\n' || ch == '\t')
//			{
//				break;
//			}
//			else
//			{
//				str += ch;
//			}
//		}
//	
//		return cin;
//	}
//	ostream& operator<<(ostream& cout, const string& str)
//	{
//		//cout << str.c_str();
//		int i = 0;
//		size_t size = str.size();
//		for (i = 0; i < size; ++i)
//		{
//			cout << str[i];
//		}
//		return cout;
//	}
//}
//int main()
//{
//	//cr::string s1("hello");
//	////cin >> s1;
//	//cout << s1 << endl;
//
//	////三种遍历方式
//	//int i = 0;
//	//for (i = 0; i < s1.size(); ++i)
//	//{
//	//	cout << s1[i];
//	//}
//	//cout << endl;
//
//	////iterator
//	//cr::string::iterator it = s1.begin();
//	//while (it != s1.end())
//	//{
//	//	cout << *it;
//	//	++it;
//	//}
//	//cout << endl;
//
//	////范围for是由迭代器支持的，也就是说这段代码最终会被编辑器替换成迭代器
//	////iterator begin()	end()
//	//for (auto au : s1)
//	//{
//	//	cout << au;
//	//}
//	//cout << endl;
//
//
//
//	//s1.push_back('s');
//	//cout << s1 << endl;
//	//s1.append("fsafsaf");
//	//cout << s1 << endl;
//	//s1 += "23131";
//	//cout << s1 << endl;
//
//
//	/*cr::string ss1("erji");
//	cout << ss1 << endl;
//	ss1.insert(1, 'w');
//	cout << ss1 << endl;
//	ss1.insert(0, '1');
//	cout << ss1 << endl;
//	ss1.insert(6, '4');
//	cout << ss1 << endl;
//	ss1.insert(7, "woshi");
//	cout << ss1 << endl;
//	ss1.insert(0, "niba");
//	cout << ss1 << endl;
//	ss1.insert(5, "521");
//	cout << ss1 << endl;*/
//
//
//	/*cr::string s1("woshida");
//	s1.insert(0,"fsfse");
//	cout << s1 << endl;*/
//	//s1.resize(10, 'w');
//	//cout << s1 << endl;
//	////s1.resize(1, 'w');
//	////cout << s1 << endl;
//	//s1.erase(6, 10);
//	//cout << s1 << endl;
//
//
//	/*cr::string s1("woshishuaige");
//	cout << s1.find('i', s1.find('i')+1) << endl;
//	cout << s1.find("ge", s1.find('i') + 1) << endl;*/
//
//	//cr::string s2("woshi");
//	//string s3("oumaga");
//	//cin >> s2;
//	//cout << s2 << endl;
//	//cin >> s3; //string会把原先的内容覆盖掉
//	//cout << s3 << endl;
//
//	cr::string s1("handsome");
//	cr::string s2("beautiful");
//	s2 = s1;
//	cout << s1 << endl << s2 << endl;
//	return 0;
//}
