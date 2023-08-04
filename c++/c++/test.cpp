#include<iostream>
using namespace std;


//函数重载
//1:函数在同一定义域
//2:参数的个数不同、类型不同或顺序不同
//3:返回值不可以作为重载的条件

//void test()
//{
//	cout<<"wo"<<endl;
//}
//void test(int a)
//{
//	cout << a << endl;
//}
//
////void test(int a=10, int)//默认参数从左到右必须都是
////{
////	cout << "占位参数" << a<<endl;
////}
//
//void test(int, int b = 10)
//{
//	b = 100;
//	cout << "占位参数" << b << endl;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;//引用，别名.必须初始化，初始化后不能引用其他对象 
//  //int* const b = &a;
//	//b = 20;//*b=20;
//	std::cout << a << b << std::endl; 
//	cout << &a << endl;
//	cout << &b << endl;
//	test(a,b);
//	cout << a << endl;
//	cout << b << endl;
//	system("pause");
//	return 0;
//}


//引用传参：修改目标值

//void test(int& a)
//{
//	a = 100;
//}
//int main()
//{
//
//	int a = 10;
//	test(a);
//	cout << a << endl;
//	system("pause");
//	return 0;
//}


//引用作为函数重载的条件

//void test(int& a)//int &a=10;错误：引用必须指向一块合法的空间，而10是常量
//{
//	cout << "int &a" << endl;
//}
//void test(const int& a)//const int &a，编译器会优化：int tmp=10;const int &a=tmp;tmp占用一块合法的空间，所以会执行成功
//{
//	cout << "const" << endl;
//}
//int main()
//{
//	/*int a = 10;
//	test(a);*/
//
//
//	test(10);
// 
//	system("pause");
//	return 0;
//}

//函数重载参数有默认参数
//
//void test(int a, int b = 10)
//{
//	cout << "int a,int b=10" << endl;
//}
//void test(int a)
//{
//	cout << "int a" << endl;
//}
//
//int main()
//{
//	test(10);//两个函数都可以执行，所以会报错（二义性）
//	system("pause");
//	return 0;
//}

//类和对象
//封装、继承、多态

//#include<string.h>
//
//double PI = 3.14;
//class Circle
//{
//public:
//	double r;
//
//	double Calculate()
//	{
//		return 2 * PI * r;
//	}
//
//};
//
//class Student
//{
//public:
//	string name;
//	string hao;
//
//	void PrintStu()
//	{
//		cout << name << "  " << hao << endl;
//	}
//	void setName(string str)
//	{
//		name = str;
//	}
//};
//int main()
//{
//	Circle a;
//	a.r = 10;
//	cout << a.Calculate() << endl;
//	Student stu;
//	stu.name =  "chenran" ;
//	stu.hao = "202211060901";
//	stu.setName("zhangsan");
//	stu.PrintStu();
//	return 0;
//}

//class 的访问权限
//1：公共权限 public	成员：类内可以访问，类外可以访问
//2：保护权限 protected	成员：类内可以访问	类外不可访问	儿子可以访问父亲中的保护内容
//3：私有权限 private	成员：类内可以访问	类外不可访问	儿子不可访问父亲中的私有内容

//class Person
//{
//public:
//	string name;
//protected:
//	string car;
//private:
//	int password;
//public:
//	void set()
//	{
//		name = "chenran";
//		car = "地板车";
//		password = 54188;
//		cout << name << "  " << car << "  " << password << endl;
//	}//类内可以访问
//};
//int main()
//{
//	Person ps;
//	ps.name = "zhangsan";
//	/*ps.car = "宝马";
//	ps.password = 123456;*/
//	//类外不可访问
//	ps.set();
//	return 0;
//}


//struct与class的区别
//在C++中唯一的区别就是默认权限不同
//struct默认权限是公共权限，class默认权限是私有权限

//class C1
//{
//	int a;
//};
//struct S1
//{
//	int b;
//};
//int main()
//{
//	C1 c;
//	//c.a;//不可访问
//	S1 s;
//	s.b = 10;//可访问
//	system("pause");
//	return 0;
//}


//成员属性设置为私有
//优点1：可以自己控制读写权限
//优点2：对于写权限，可以检测数据的有效性

//#include<string.h>
//class Person
//{
//public:
//	void SetNmae(string str)
//	{
//		name = str;
//	}
//	string GetName()
//	{
//		return name;
//	}
//	void SetAge(int a)
//	{
//		if (a < 0 || a>150)
//		{
//			age = 0;
//			return;
//		}//检测数据的有效性
//		age = a;
//	}
//	
//	string GetLover()
//	{
//		lover = "she";
//		return lover;
//	}
//private:
//	string name;//可读可写
//	int age;//只写
//	string lover;//只读
//};
//int main()
//{
//	Person p;
//	p.SetNmae("chenran");
//	cout << p.GetName() << endl;
//	p.SetAge(19);
//	cout << p.GetLover() << endl;
//	return 0;
//}


//class Cube
//{
//public:
//	void SetCube(int a, int b, int c)
//	{
//		l = a;
//		w = b;
//		h = c;
//	}
//	int GetCubeS()
//	{
//		return 2 * (l * w + l * h + w * h);
//	}
//	int GetCubeV()
//	{
//		return l * w * h;
//	}
//	bool isSame(Cube& c2)
//	{
//		if (GetCubeS() == c2.GetCubeS() && GetCubeV() == c2.GetCubeV())
//			return true;
//		else
//			return false;
//	}
//private:
//	int l;
//	int w;
//	int h;
//};
////bool isSame(Cube& c1, Cube& c2)
////{
////	if (c1.GetCubeS() == c2.GetCubeS() && c1.GetCubeV() == c2.GetCubeV())
////		return true;
////	else
////		return false;
////}
//int main()
//{
//	Cube cube;
//	Cube cube2;
//	int a = 10;
//	int b = 20;
//	int c = 30;
//	cube2.SetCube(a, b, c);
//	cube.SetCube(10, 20, 30);
//	cout << cube.GetCubeS() << endl;
//	cout << cube.GetCubeV() << endl;
//	//int ret=isSame(cube,cube2);
//	int ret = cube.isSame(cube2);
//	if (ret)
//		cout << "相等" << endl;
//	else
//		cout << "不相等" << endl;
//	return 0;
//}

//类的声明与定义

//class Point
//{
//public:
//	void SetPoint(int x, int y)
//	{
//		p_x = x;
//		p_y = y;
//	}
//	int GetPoint_x()
//	{
//		return p_x;
//	}
//	int GetPoint_y()
//	{
//		return	p_y;
//	}
//private:
//	int p_x;
//	int p_y;
//};
//
//class Circle
//{
//public:
//	void SetCircle_r(int r)
//	{
//		m_r = r;
//	}
//	int GetCircle_r()
//	{
//		return m_r;
//	}
//	void SetCenter(Point Center)
//	{
//		m_Center = Center;
//	}
//	Point GetCenter()
//	{
//		return m_Center;
//	}
//private:
//	int m_r;
//	Point m_Center;//圆心
//};

//类的声明与定义
//#include"test.h"
//void Point::SetPoint(int x, int y)
//{
//	p_x = x;
//	p_y = y;
//}
//int Point::GetPoint_x()
//{
//	return p_x;
//}
//int Point::GetPoint_y()
//{
//	return	p_y;
//}
//
//
//void Circle::SetCircle_r(int r)
//{
//	m_r = r;
//}
//int Circle::GetCircle_r()
//{
//	return m_r;
//}
//void Circle::SetCenter(Point Center)
//{
//	m_Center = Center;
//}
//Point Circle::GetCenter()
//{
//	return m_Center;
//}
//void P_C(Point &p,Circle& c)
//{
//	if ((p.GetPoint_x() - c.GetCenter().GetPoint_x()) * (p.GetPoint_x() - c.GetCenter().GetPoint_x())
//		+ (p.GetPoint_y() - c.GetCenter().GetPoint_y()) * (p.GetPoint_y() - c.GetCenter().GetPoint_y())
//		== c.GetCircle_r() * c.GetCircle_r())
//	{
//		cout << "点在圆上"<<endl;
//	}
//	else if ((p.GetPoint_x() - c.GetCenter().GetPoint_x()) * (p.GetPoint_x() - c.GetCenter().GetPoint_x())
//		+ (p.GetPoint_y() - c.GetCenter().GetPoint_y()) * (p.GetPoint_y() - c.GetCenter().GetPoint_y())
//		> c.GetCircle_r() * c.GetCircle_r())
//	{
//		cout << "点在圆外"<<endl;
//	}
//	else
//		cout << "点在圆内"<<endl;
//}
//
//int main()
//{
//	Point p;
//	p.SetPoint(10, 10);
//
//	Point c;
//	c.SetPoint(0, 0);
//
//	Circle C1;
//	C1.SetCenter(c);
//	int r = 10;
//	C1.SetCircle_r(r);
//
//	P_C(p, C1);
//	return 0;
//}


//对象的初始化和清理

//构造函数：创建对象时为对象的成员赋值，构造函数由编译器自动调用，无需手动调用
//析构函数:	对象销毁前系统自动调用，无需手动调用

//class Person
//{
//public:
//	//构造函数：
//		/*	语法：类名(){}
//			没有返回值也不写void
//			函数名称和类名相同
//			构造函数可以有参数，所以可以发生重载
//			程序在调用对象时自动调用构造函数，无需手动调用，且只会调用一次*/
//	Person()
//	{
//		cout << "构造函数" << endl;
//	}
//	//析构函数：
//			/*	语法：~类名(){}
//			没有返回值也不写void
//			函数名称和类名相同，在名称前加上符号~
//			构造函数不可以有参数，所以不可以发生重载
//			程序在对象销毁前自动调用构造函数，无需手动调用，且只会调用一次*/
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//	//注意：构造和析构都是必须有的实现，如果我们自己不提供，编译器会提供一个空实现的构造和析构
//};
//int main()
//{
//
//	Person P;
//	system("pause");
//	return 0;
//}

//构造函数的分类和调用
//分类：
//1：按参数分类：有参构造和无参构造（默认构造）
//2: 按照类型分类：普通构造函数和拷贝构造函数

//class Person
//{
//public:
//	Person()
//	{
//		cout << "无参构造" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "有参构造" << endl;
//	}
//	Person(const Person& p) 
//	//拷贝构造函数：把p的属性拷贝到当前对象身上，const是为了不修改p
//	{
//		age = p.age;
//		cout << "拷贝构造" << endl;
//	}
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//
//	int age;
//};
//
////调用：
//void test1()
//{
//	//1：括号法
//	Person p1;//默认构造函数调用
//	//注意：使用默认构造函数调用不能加()
//	//		Person p1();因为编译器会认为这是一个声明
//	Person p2(10);//有参构造函数调用
//	Person p3(p2);//拷贝函数调用
//	cout << p2.age << endl;
//	cout << p3.age << endl;
//
//	//2：显示法
//	Person p4;
//	Person p5 = Person(20);//有参构造函数调用
//	Person p6 = Person(p5);//拷贝函数调用
//	Person(10);//匿名对象：当前行执行后，系统会立即回收掉匿名对象
//	cout << "test匿名对象" << endl;
//	//注意：不能利用拷贝构造函数初始化匿名对象
//	//		Person(p5);编译器会认为 Person(p5)===Person p5;
//	
//	//3:隐式转换法
//	Person p6 = 30;//相当于Person p6 = Person (30);
//	Person p7 = p6;//相当于Person p7 = Person (p6);
//}
//int main()
//{
//	test1();
//	system("pause");
//	return 0;
//}


//拷贝构造函数调用时机
//1：使用一个已经创建完毕的对象来初始化一个新对象
//2：值传递的方式给函数参数传值
//3：以值方式返回局部对象

//class Person
//{
//public:
//	Person()
//	{
//		cout << "无参构造" << endl;
//	}
//	Person(int a)
//	{
//		age = a;
//		cout << "有参构造" << endl;
//	}
//	Person(const Person& p) 
//	{
//		age = p.age;
//		cout << "拷贝构造" << endl;
//	}
//	~Person()
//	{
//		cout << "析构函数" << endl;
//	}
//
//	int age;
//};
//
////1：使用一个已经创建完毕的对象来初始化一个新对象
//void test1()
//{
//	Person p1(10);
//	Person p2(p1);
//	cout << p2.age << endl;
//}
//
////2：值传递的方式给函数参数传值
//void doWork(Person p)  //相当于隐式转换法：Person p = p 
//{
//
//}
//void test2()
//{
//	Person p;
//	doWork(p);
//}
//
////3：以值方式返回局部对象
//Person doWork2()
//{
//	Person p1;
//	cout << (int*)&p1 << endl;
//	return  Person(p1);
//}
//void test3()
//{
//	Person p = doWork2();
//	cout << (int*)&p << endl;
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}


//构造函数调用规则：
// 默认构造函数（无参，函数体为空）
// 默认析构函数（无参，函数体为空）
// 默认拷贝构造函数，对属性进行值拷贝（浅拷贝）
// 
// 创建一个了类，C++编译器会给每一个类都添加至少三个函数：默认构造、析构函数、拷贝构造
// 
//如果用户定义有参构造函数，C++不再提供默认无参构造，但会提供默认拷贝构造
//如果用户定义拷贝构造函数，C++不再提供其他构造函数


//深拷贝和浅拷贝
//浅拷贝：简单的赋值拷贝操作
//深拷贝：在堆区重新申请空间，进行拷贝操作
//默认拷贝函数就是浅拷贝

//class Person
//{
//public:
//	Person()
//	{
//		cout << "无参构造" << endl;
//	}
//	Person(int a,int h)
//	{
//		age = a;
//		Height = new int(h);
//		cout << "有参构造" << endl;
//	}
//	/*Person(const Person& p)
//	{
//		age=p.age;
//		Height=p.Height;
//		cout << "浅拷贝构造" << endl;
//	}*/
//	Person(const Person& p)
//	{
//		age = p.age;
//		Height = new int(*p.Height);
//		cout << "深拷贝构造" << endl;
//	}
//	~Person()
//	{
//		//析构代码：将堆区的空间进行释放
//		//注意：拷贝构造函数里的浅拷贝会造成堆区的内存重复释放，造成非法操作，所以要进行深拷贝
//		if (Height != NULL)
//		{
//			delete Height;
//			Height = NULL;
//		}
//		cout << "析构函数" << endl;
//	}
//	int age;
//	int* Height;
//};
//void test()
//{
//	Person p1(18,175);
//	cout << p1.age << "  " << *p1.Height << endl;
//	Person p2(p1);
//	cout << p2.age << "  " << *p2.Height << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//初始化列表 - 用来初始化属性
//语法   -  构造函数():属性一(值1),属性二(值2),...{}
//1.常量成员，因为常量只能初始化不能赋值，所以必须放在初始化列表里面
//2.引用类型，引用必须在定义的时候初始化，并且不能重新赋值，所以也要写在初始化列表里面
//3. 没有默认构造函数的类类型，因为使用初始化列表可以不必调用默认构造函数来初始化，而是直接调用拷贝构造函数初始化
//class Person
//{
//public:
//	/*Person(int a, int b, int c)
//	{
//		m_a = a;
//		m_b = b;
//		m_c = c;
//	}*/
//	/*Person() :m_a(10), m_b(20), m_c(30)
//	{
//
//	}*/
//	Person(int a,int b,int c) :m_a(a), m_b(b), m_c(c)
//	{
//
//	}
//	int m_a;
//	int m_b;
//	int m_c;
//};
//void test()
//{
//	/*Person p(10, 20, 30);
//	cout << p.m_a << "  " << p.m_b << "  " << p.m_c << endl;*/
//	/*Person p1;
//	cout << p1.m_a << "  " << p1.m_b << "  " << p1.m_c << endl;*/
//	Person p2(10, 20, 30);
//	cout << p2.m_a << "  " << p2.m_b << "  " << p2.m_c << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}

