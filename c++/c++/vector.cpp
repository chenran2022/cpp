//STL  标准模板库
//
#include<iostream>
#include<vector>
#include<algorithm> //算法库
#include<assert.h>
using namespace std;


//三种遍历方式
void test_vector1()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	vector<int> v2(v1);

	for (auto au : v1)		//被编译器替换成迭代器方式遍历支持的
	{
		cout << au << "  ";
	}
	cout << endl;
	for (int i=0;i<v2.size();++i)
	{
		cout << v2[i] << "  ";
	}
	cout << endl;

	vector<int> v3;
	v3.push_back(20);
	v3.push_back(50);
	v3.push_back(30);
	v3.push_back(40);
	v3.push_back(60);
	v1 = v3;
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << "  ";
		++it;
	}
	cout << endl;
}


//四种类型的迭代器
void test_vector2()
{
	//
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	//1.普通正向迭代器  （变量不是const修饰的）  可读可写
	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		*it += 1;
		cout << *it << "  ";
		++it;
	}
	cout << endl;

	const vector<int> v2(v1); 
	//2.const迭代器  (变量是const修饰的，返回值也是const修饰的指针)  只读不可写
	vector<int>::const_iterator it2 = v2.begin();
	while (it2 != v2.end())
	{
		//*it2 = 1;  //不可写
		cout << *it2 << "  ";
		++it2;
	}
	cout << endl;

	//3.反向迭代器  rbegin和rend返回值是reverse_iterator类型的  （变量不是const修饰的）
	vector<int>::reverse_iterator it3 = v1.rbegin(); 
	while (it3 != v1.rend())
	{
		*it3 += 4;
		cout << *it3 << "  ";
		++it3;
	}
	cout << endl;

	//4.const修饰的反向迭代器  rcbegin和crend返回值是const_reverse_iterator类型的  (变量是const修饰的)
	vector<int>::const_reverse_iterator it4 = v2.crbegin();
	while (it4 != v2.crend())
	{
		//*it4 += 1;  //不可写
		cout << *it4 << "  ";
		++it4;
	}
	cout << endl;
}


//capacity容量的增长速度 编译器不同增长速度可能会不一样 这里是1.5倍增容，linux是2倍增容
//增容次数越多，效率越低，每次增容都要付出代价；
//相对而言，倍数高，增容次数越少，效率越高，但浪费的空间更多
//可以使用reserve函数来缓解增容次数
void test_vector3()
{
	vector<int> v1;
	int cap = v1.capacity();
	cout << cap << endl;
	//v1.reserve(100);  可以使用reserve函数来缓解增容次数,不能使用resize，因为resize会初始化
	for (int i = 0; i < 100; ++i)
	{
		v1.push_back(1);
		if (cap != v1.capacity())
		{
			cap = v1.capacity();
			cout << cap << endl;
		}
	}
}


//抛异常
void test_vector4()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	//v1[4] = 6;  //越界，出现assert错误，程序直接终止
	v1.at(4) = 1; //捕获异常
}


//vector 几个常用的接口
void test_vector5()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	v1.pop_back();
	for (auto au : v1)
	{
		cout << au << "  " ;
	}
	cout << endl;


	/*insert(iterator, val);
	insert(iterator, n, val);
	insert(iterator, InputIterator first, InputIterator last);*/
	v1.insert(v1.begin(), 0);
	v1.insert(v1.begin(), 2,-1);
	for (auto au : v1)
	{
		cout << au << "  ";
	}
	cout << endl;


	v1.erase(v1.begin());
	for (auto au : v1)
	{
		cout << au << "  ";
	}
	cout << endl;


	//vector没有find的接口，
	//如果想要查找某一个值的下标，可以使用算法中的find函数模板（不仅vector可以使用）
	//在前闭后开的区间内查找第一个为目标值的地址，如果找不到，就会返回区间的最后一个地址end()
	vector<int>::iterator pos = find(v1.begin(), v1.end(), 3);
	cout << *pos << endl;
	if (pos != v1.end())
		v1.erase(pos);
	for (auto au : v1)
	{
		cout << au << "  ";
	}
	cout << endl;


	vector<int> v2;
	v2.push_back(10);
	v2.push_back(-2);
	v2.push_back(3);
	v2.push_back(0);
	sort(v2.begin(), v2.end());
	for (auto au : v2)
	{
		
		cout << au << "  ";
	}
	cout << endl;
}


//迭代器失效
void test_vector6()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(4);
	v1.push_back(4);
	v1.push_back(4);

	//1.
	//vector<int>::iterator it = v1.begin();
	//
	//v1.push_back(5); 
	////迭代器失效  
	////原因：push_back会导致vector扩容，旧空间不够扩容的话会拷贝到新空间内扩容，但迭代器还是指向旧空间
	////push_back  insert  resize  reserve 等可能会扩容的接口都会导致迭代器失效
	//while (it != v1.end())
	//{
	//	cout << *it << "   ";
	//	++it;
	//}
	//cout << endl;



	//2. 
	vector<int>::iterator it = v1.begin();

	while (it != v1.end())
	{
		if (*it % 2 == 0)
		{
			//v1.erase(it); 
			////迭代器失效
			////删除it之后，it的位置就不对了，it就失效了 ，再++就不行，会有各种各样的问题
			////vs下报错是编译器检查的 ，一定报错
			////gcc下没有严格的检查，有可能会报错，也有不报错但结果不对


			//解决办法：
			it = v1.erase(it); //erase返回删除的it的下一个位置的迭代器

		}
		else 
		{
			++it;
		}
	}
	for (auto au : v1)
	{

		cout << au << "  ";
	}
	cout << endl;

}
//int main()
//{
//	//test_vector1();
//	//test_vector2();
//	//test_vector3();
//	//test_vector4();
//	//test_vector5();
//	//test_vector6();
//	
//
//	return 0;
//}



//vector的实现

namespace cr
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		vector() :_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{}
		//vector(const vector<T>& x)
		//{
		//	//1.
		//	//_start = new T[x.capacity()];
		//	/*memcpy(_start, x.begin(),sizeof(T)*x.size());
		//	_finish = _start + x.size();
		//	_endofstorage = _start + x.capacity();*/

		//	//2.
		//	_start = new T[x.capacity()];
		//	_finish = _start;
		//	_endofstorage = _start + x.capacity();
		//	for (int i=0;i<x.size();++i)
		//	{
		//		*_finish = x[i];
		//		++_finish;
		//	}

		//}
		vector(const vector<int>& x) :_start(nullptr), _finish(nullptr), _endofstorage(nullptr)
		{
			//使用这种方法一定要先_start(nullptr), _finish(nullptr)初始化
			//因为reserve里计算sz会用到_finish和_start
			reserve(x.capacity());
			for (const auto& au : x)
			{
				push_back(au);
			}
		}
		~vector()
		{
			delete[] _start;
			_start = _finish = _endofstorage = nullptr;
		}
		//vector<T>& operator=(const vector<int>& x)
		//{

		//	if (this!=&x)
		//	{
		//		delete[] _start;
		//		_start = nullptr;
		//	}
		//	_start = new T[x.capacity()];
		//	memcpy(_start, x.begin(),sizeof(T)*x.size());
		//	_finish = _start + x.size();
		//	_endofstorage = _start + x.capacity();



		//	//使用下面这种方法一定要先_start(nullptr), _finish(nullptr)初始化
		//	//因为reserve里计算sz会用到_finish和_start
		//	/*_start = nullptr;
		//	_finish = nullptr;
		//	reserve(x.capacity());
		//	for (const auto& au : x)
		//	{
		//		push_back(au);
		//	}*/
		//	return *this;
		//}
		vector<T>& operator=(vector<int> v)  //拷贝构造出一个临时变量，现代写法
		{
			swap(v);
			return *this;
		}

		//由于使用内置swap函数交换两个变量，会进行三个深拷贝，代价太大，所以定义了swap成员函数
		//v1.swap(v2)
		void swap(vector<T>& v)
		{
			//因为swap函数同名，下面的swap使用的是全局下的swap函数
			::swap(_start, v._start);
			::swap(_finish, v._finish);
			::swap(_endofstorage, v._endofstorage);
		}
		iterator begin()
		{
			return _start;
		}
		iterator end()
		{
			return _finish;
		}
		const_iterator begin()const
		{
			return _start;
		}
		const_iterator end()const
		{
			return _finish;
		}
		void reserve(size_t n)
		{
			size_t sz = size();
			T* tmp = new T[n];
			if (_start)
			{
				//memcpy(tmp, _start, sizeof(T) * sz);  //按字节拷贝，浅拷贝，当T是string时会出错
				for (size_t i = 0; i < sz; ++i)
				{
					tmp[i] = _start[i];		   //调用的是operator= 深拷贝
				}
				delete[] _start;   //释放自定义类型时,会释放掉自定义类型的每一个成员变量,string里的_str就会释放掉
			}
			_start = tmp;
			//_finish = _start + size();  
			//不能直接用size(),因为这个接口也是根据_finish和_start算的，这俩已经不属于同一块数据区域了
			_finish = _start + sz;
			_endofstorage = _start + n;
		}
		void push_back(const T& x)
		{
			/*if (_finish == _endofstorage)
			{
				size_t newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
			}
			*_finish = x;
			++_finish;*/

			insert(_finish, x);
		}
		void pop_back()
		{
			/*assert(size());
			--_finish;*/

			erase(_finish - 1);
		}

		//vector.insert 是在iterator位置插入，而不是在下标[]插入
		void insert(iterator pos, const T& val)
		{
			assert(pos <= _finish && pos >= _start);
			if (_finish == _endofstorage)
			{
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : 2 * capacity();
				reserve(newcapacity);
				pos = _start + n;  //扩容之后，原来的pos迭代器失效了,需要重新计算位置
			}
			iterator end = _finish;
			while (end > pos)
			{
				*end = *(end - 1);
				--end;
			}
			*pos = val;
			++_finish;
		}
		iterator erase(iterator pos)
		{
			assert(pos < _finish && pos >= _start);
			iterator it = pos;
			while (it != _finish)
			{
				*it = *(it +1);
				++it;
			}
			--_finish;
			return pos;
		}
		void resize(size_t n, const T& val = T())  //由于T的类型不知道，有可能是自定义类型，缺省值用T()
		{
			assert(n > 0);
			if (n <= size())
			{
				_finish = _start + n;
			}
			else
			{
				if ( n > capacity())
				{
					reserve(n);
				}
				
				while (_finish < _start + n)
				{
					*_finish = val;
					++_finish;
				}
				
			}
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}
		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}
		size_t size()const
		{
			return _finish - _start;
		}
		size_t capacity() const
		{
			return _endofstorage - _start;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void print_vector(const vector<int>& v)
	{
		vector<int>::const_iterator it = v.begin();
		while (it != v.end())
		{
			//*it += 1;   //不可写
			cout << *it << "  ";
			it++;
		}
		cout << endl;
	}
	void test_vector1()
	{
		vector<int> v;
		
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		
		v.pop_back();
		print_vector(v);
		
		vector<int>::iterator it = v.begin();
		while (it != v.end()) 
		{
			cout << *it << "  ";
			it++;
		}
		cout << endl;
		cout << v.size() << endl << v.capacity() << endl;

		for (auto au : v)   //会被替换成迭代器（即替换成上面的代码），如果把begin()改成Begin(),就不能使用范围for，因为找不到begin
		{
			au -= 1;  //并不会改变v的值，因为这里只是把v赋值给au
			cout << au << "   ";
		}
		cout << endl;

		for (auto& au : v)   
		{
			au -= 1;  //会改变v的值
			cout << au << "   ";
		}
		cout << endl;

		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << "   ";
		}
		cout << endl;
	}

	void test_vector2()
	{
		vector<int> v;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		print_vector(v);

		v.insert(v.begin() + 3, 10);
		v.insert(v.begin(), 100);
		print_vector(v);

		v.erase(v.begin());
		v.erase(v.begin()+3);
		v.erase(v.end()-1);
		print_vector(v);
	}
	void test_vector3()
	{
		vector<int> v;
		v.reserve(10);
		cout << v.size() << endl << v.capacity() << endl;

		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		cout << v.size() << endl << v.capacity() << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << "   ";
		}
		cout << endl;

		v.resize(8, 10);
		cout << v.size() << endl << v.capacity() << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << "   ";
		}
		cout << endl;

		v.resize(20, 100);
		cout << v.size() << endl << v.capacity() << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << "   ";
		}
		cout << endl;

		v.resize(25);   //缺省值给的是int()  
		cout << v.size() << endl << v.capacity() << endl;
		for (int i = 0; i < v.size(); ++i)
		{
			cout << v[i] << "   ";
		}
		cout << endl;


		//内置类型
		//用于初始化它们的语法使它们看起来像是由默认构造函数或默认拷贝构造函数构造的。
		int i = int();  //0
		int j = int(1); //1
		double d = double(); //0.0
		double e = double(1.1); //1.1
		cout << i << endl << j << endl << d << endl << e << endl;

	}
	void test_vector4()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);

		print_vector(v);
		vector<int> v2(v);
		v2.push_back(10);

		v2 = v;
		print_vector(v2);

		vector<int> v3 = v;
		print_vector(v3);
	}

	//memcpy更深一层次的深浅拷贝问题，当T是string时的增容问题
	void test_vector5()
	{
		vector<string> v;
		v.push_back("1111111111111111111111111111111111111");
		v.push_back("2222222222222222222222222222222222222");
		v.push_back("333333333333333333333333333333");
		for (auto& au : v)

		{
			cout << au << "   ";  //出现乱码
		}
		//在reserve增容时，只是把_start进行深拷贝，但string 的_start里面包含_str,_str并没有进行深拷贝
		//在reserve增容时，delete[]不仅会把_start释放掉，也会把_strat里的_str指向的内容delete释放掉
		//所以在增容时，不能使用memcpy(tmp, _start, sizeof(T) * sz);按字节拷贝，浅拷贝，当T是string时会出错
		cout << endl;
	}
}
int main()
{
	//cr::test_vector1();
	//cr::test_vector2();
	//cr::test_vector3();
	//cr::test_vector4();
	cr::test_vector5();
	return 0;
}
