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


//类对象作为类成员
//当其他类对象作为本类成员，构造时候先构造类对象，再构造自身，析构的顺序与构造相反

//#include<string>
//class Phone
//{
//public:
//	Phone(string n) :name(n)
//	{
//		cout << "Phone的构造函数调用" << endl;
//	}
//	~Phone()
//	{
//		cout << "Phone的析构函数调用" << endl;
//	}
//	string name;
//};
//class Person
//{
//public:
//	Person(string n,string p) :name(n), phone(p)
//	{
//		cout << "Person的构造函数调用" << endl;
//	}
//	~Person()
//	{
//		cout << "Person的析构函数调用" << endl;
//	}
//	string name;
//	Phone phone;
//};
//void test()
//{
//	Person p("张三","华为");
//	cout << p.name << "买了" << p.phone.name << endl;
//}
//int main()
//{
//	test();
//	return 0;
//}


//静态成员  :在成员变量或者成员函数前加上关键字static
//1：静态成员变量 
//	 所有对象共享同一份数据
//	 在编译阶段分配内存
//	 类内声明，类外初始化
//2：静态成员函数
//	 所有对象共享同一个函数
//	 静态成员函数只能访问静态成员变量

//class Person
//{
//public:
//	static void func()
//	{
//		age = 300;
//		//Height = 175;//静态成员函数不能访问非静态成员变量,无法区分到底是哪个对象的属性
//		cout << "静态成员函数的调用" << endl;
//	}
//	static int age;//类内声明
//	//静态成员变量也有访问权限
//	//静态成员函数也有访问权限
//private:
//	static void func2()
//	{
//		cout << "私有静态成员函数的调用" << endl;
//	}
//	static int ID;
//	int Height;
//};
//int Person::age = 100;//类外初始化
//int Person::ID = 520;
//void test1()
//{
//	Person p;
//	cout << p.age << endl;
//	Person p1;
//	p1.age = 200;
//	cout << p1.age << endl;
//	cout << p.age << endl;
//
//}
////静态成员变量不属于某个对象上，所有对象都共享同一份数据，所以静态成员变量有两种访问方式
//void test2()
//{
//	//1：通过对象进行访问
//	Person p1;
//	cout << p1.age << endl;
//	//2：通过类名进行访问
//	cout << Person::age << endl;
//	//cout << Person::ID << endl;//私有权限不可访问
//}
////静态成员函数也有两种访问方式
//void test3()
//{
//	Person p1;
//	//1：通过对象进行访问
//	p1.func();
//	//2：通过类名进行访问
//	Person::func();
//	cout << Person::age << endl;
//	//Person::fonc2();//类外不可访问私有静态成员函数
//}
//int main()
//{
//	//test1();
//	//test2();
//	test3();
//	return 0;
//}


//static int b = 2;
//void test1()
//{
//	Person p;
//	//空对象占用空间为1；
//	//c++编译器会给每个空对象也分配一个字节空间，是为了区分空对象占内存的位置，每个空对象也应该有独一无二的内存地址
//	cout << sizeof(p) << endl;
//}
//void test2()
//{
//	Phone P;
//	cout << sizeof(P) << endl;
//}
//int main()
//{
//	test1();
//	test2();
//
//	return 0;
//}

//C++中成员变量和成员函数是分开存储的
//每一个非静态成员函数只会诞生一份函数实例，也就是说多个同类型对象会公用一块代码
//通过this指针指向被调用的成员函数所属的对象

//this指针是隐含每一个非静态成员函数内的一种指针
//this指针不需要定义，直接使用即可
//用途：
//		1: 当形参和成员变量同名时， 解决命名冲突
//		2：在类的非静态成员函数中返回对象本身，用return *this

//class Person
//{
//public:
//	//Person(int a)
//	//{
//	//	a = a;//编译器默认这三个变量一样
//	//}
//
//	Person(int a)
//	{
//		this->a = a; //this指针指向被调用的成员函数所属的对象
//	}
//
//	///返回的拷贝值，不是p2本身
//	/*Person Increase(Person& p)
//	{
//		this->a += p.a;
//		return* this;
//	}*/
//
//	Person& Increase(Person& p)
//	{
//		this->a += p.a;
//		//this指向p2，*this是p2本身
//		return* this;
//	}
//	int a;
//};
//void test1()
//{
//	Person p(18);
//	cout << p.a << endl;
//}
//void test2()
//{
//	Person p1(12);
//	Person p2(12);
//	//链式编程
//	p2.Increase(p1).Increase(p1).Increase(p1);
//	cout << p2.a << endl;
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}//成员变量和成员函数是分开存储的
//只有非静态成员变量才属于类的对象上


//class Person
//{
//
//};
//class Phone
//{
//	int a;					//非静态成员变量，属于类的对象上
//	static int b;			//静态成员变量，不属于类的对象
//	void fun(){}			//非静态成员函数，不属于类的对象
//	static void fun2(){}	//静态成员函数，不属于类的对象
//};

//空指针访问成员函数
//在c++中，空指针也可以调用成员函数，但是要注意有没有用到this指针，如果用到了this指针，则需要对代码的健壮性进行判别。
//如果调用编译器确定函数（普通成员函数、静态成员函数），该成员函数中需要对this指针指向的内容进行读取或者修改，出错；反之无错；
//如果调用运行期确定函数（使用多态的虚函数），出错。

//class Person
//{
//public:
//	void showClass()
//	{
//		cout << "class Person" << endl;
//	}
//	void showage()
//	{
//		
//		cout << age << endl;// this->age
//	}
//	int age;
//};
//void test()
//{
//	Person* p = NULL;
//	//p->showage();//出错：该函数内使用了this指针
//	p->showClass();
//}
//int main()
//{
//	test();
//	return 0;
//}


//const修饰的成员函数

//class Person
//{
//	
//public:
//	//this 指针的本质，是指针常量，void* const this;指针的指向不可修改
//	//在成员函数后面加const，修饰的是this指针，让指针指向的值也不可修改
//	//即const void* const this;
//
//	//常函数
//	void showPerson()const
//	{
//		//this->m_A = 100;
//		//this = NULL;//this指针的指向不可修改
//		this->m_B = 200;
//	}
//
//	void func()
//	{
//		m_A = 100;
//	}
//	int m_A;
//	mutable int m_B;//特殊变量，即使在常函数中，也可以修改这个值，加关键字mutable
//};
//void test1()
//{
//	Person p;
//	p.showPerson();
//	cout << p.m_B << endl;
//}
//void test2()
//{
//	//常对象：在对象前加const，变为常对象
//	const Person p;
//	//p.m_A = 100;
//	p.m_B = 200;//特殊值，可以修改
//
//	//常对象只能调用常函数
//	p.showPerson();
//	//p.func();//常对象不可调用普通成员函数，因为普通成员函数可以修改属性
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}

//友元

//全局函数做友元

//#include<string.h>
//class Building
//{
//	//goodGay全局函数是building好朋友，可以访问Building的私有成员
//	friend void goodGay(Building& building);
//public:
//	Building()
//	{
//		Room = "客厅";
//		BedRoom = "卧室";
//	}
//public:
//	string Room;
//private:
//	string BedRoom;
//};
//
//void goodGay(Building& building)
//{
//	cout << building.Room << endl;
//	cout << building.BedRoom << endl;
//}
//
//void test1()
//{
//	Building building;
//	goodGay(building);
//}
//int main()
//{
//	test1();
//	return 0;
//}

//类做友元

//class Building
//{
//	//goodGay类是本类的好朋友，可以访问本类的私有属性
//	friend class goodGay;
//public:
//	Building();
//public:
//	string room;
//private:
//	string bedroom;
//};
//
//class goodGay
//{
//public:
//	goodGay();
//	void visit();//访问Building类的成员属性
//private:
//	Building* building;
//};
//Building::Building()
//{
//	room = "客厅";
//	bedroom = "卧室";
//}
//goodGay::goodGay()
//{
//	building = new Building;
//}
//void goodGay::visit()
//{
//	cout << building->room << endl;
//	cout << building->bedroom << endl;
//}
//int main()
//{
//	goodGay gg;
//	gg.visit();
//	return 0;
//}

//成员函数做友元

//#include<string>
//class Building;
//class goodGay
//{
//public:
//	goodGay();
//	void visit();//让visit函数可以访问Building中私有成员
//	void visit2();//让visit2函数不可以访问Building中私有成员
//	Building* building;
//};
//class Building
//{
//	//goodGay类下的visit成员函数作为本类的好朋友，可以访问私有成员
//	friend void goodGay::visit();
//public:
//	Building();
//	string room;
//private:
//	string bedroom;
//};
//Building::Building()
//{
//	room = "客厅";
//	bedroom = "卧室";
//}
//goodGay::goodGay()
//{
//	building = new Building;
//}
//void goodGay::visit()
//{
//	cout << building->room << endl;
//	cout << building->bedroom << endl;
//}
//void goodGay::visit2()
//{
//	cout << building->room << endl;
//	//cout << building->bedroom << endl;
//}
//int main()
//{
//	goodGay gg;
//	gg.visit();
//	gg.visit2();
//	return 0;
//}

//运算符重载

//加号运算符重载：实现两个自定义数据类型相加的运算
//class Person
//{
//public:
//	//1、成员函数重载+号
//	/*Person operator+ (Person & p)
//	{
//		Person temp;
//		temp.m_A = this->m_A + p.m_A;
//		temp.m_B = this->m_B + p.m_B;
//		return temp;
//	}*/
//	int m_A;
//	int m_B;
//};
////2、全局函数重载+号
//Person operator+(Person& p1, Person& p2)
//{
//	Person temp;
//	temp.m_A = p1.m_A + p2.m_A;
//	temp.m_B = p1.m_B + p2.m_B;
//	return temp;
//}
//Person operator+(Person& p1, int num)
//{
//	Person temp;
//	temp.m_A = p1.m_A + num;
//	temp.m_B = p1.m_B + num;
//	return temp;
//}
//void test1()
//{
//	Person p1,p2;
//	p1.m_A = 10;
//	p1.m_B = 10;
//	p2.m_A = 10;
//	p2.m_B = 10;
//	//成员函数重载的本质调用
//	//Person p3 = p1.operator+(p2);
//
//	//全局函数重载的本质调用
//	//Person p3 = operator+(p1, p2);
//
//	//上式可简化为下式
//	Person p3 = p1 + p2;
//	cout << p3.m_A << "  " << p3.m_B << endl;
//	//运算符重载也可以发生函数重载
//	Person p4 = p1 + 100;//Person + int 相当于operator+(p1,100)
//	cout << p4.m_A << "  "<< p4.m_B << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}
//总结1：对于内置数据类型的表达式的运算符是不可能改变的
//总结2：不要滥用运算符重载 (滥用：+号的名称来实现减法运算)

//左移运算符重载<<  : 重载左移运算符配合友元可以实现输出自定义数据类型

//class Person
//{
//	//如果访问类内的私有成员，就要用到友元
//	friend ostream& operator<<(ostream& cout, Person& p);
//public:
//	//如果用成员函数重载左移运算符，p.operator<<(cout),使用时cout在右边，而不是左边：p<<cout 。所以左移运算符重载要通过全局函数实现
//	//cout是输出流类型，只有一个，所以用&引用,名称可以随便取别名
//	/*void operator<<(ostream& cout)
//	{
//
//	}*/
//	int m_a;
//	int m_b;
//};
////void operator<<(ostream& cout, Person& p)
////{
////	cout << p.m_a << "  " << p.m_b;
////	//此形式不能实现链式结构，例如在后面加上endl
////	//cout<<p<<endl 属于链式结构，cout<<p 的返回类型为void ， void<<endl出错，所以函数返回类型应为ostream&
////}
//
//ostream& operator<<(ostream& cout, Person& p)
//{
//	cout << p.m_a << "  " << p.m_b;
//	return cout;
//}
////当<<右边为内置数据类型时，就会调用原来定义的函数（函数重载）
//int main()
//{
//	Person p;
//	p.m_a = 10; 
//	p.m_b = 20;
//	cout << p << "hello word"<<p<<endl;
//	return 0;
//}

//递增运算符重载

//class MyInteger
//{
//	friend ostream& operator<<(ostream& cout, MyInteger myint);
//public:
//	MyInteger()
//	{
//		m_num = 0;
//	}
//	//前置++重载
//	//返回值类型为引用，如果不是引用，会创建一个新的变量，导致链式代码出错
//	MyInteger& operator++()
//	{
//		m_num++;
//		return *this;
//	}
//
//	//后置++重载
//	//MyInteger operator++(int)  其中int为占位参数，目的是与前置++区分
//	//返回值类型不能为&引用，因为tmp是个临时变量，局部变量就会被释放，之后再访问就是非法访问了
//	//但是后置++不能进行链式代码了，与前置++不同
//	MyInteger operator++(int)
//	{
//		//先记录到当前的值，再进行++，最后再返回原来的值
//		MyInteger tmp = *this;
//		m_num++;
//		return tmp;
//	}
//private:
//	int m_num;
//};
//ostream& operator<<(ostream& cout, MyInteger myint)
//{
//	cout << myint.m_num;
//	return cout;
//}
////左移重载写ostream& operator<<(ostream& cout, MyInteger& myint)时，此时第二个参数有&，
////为什么前置递增（cout << ++myint）可以，而后置递增（cout << myint++）会报错
////1、前置递增（++myint）时，重载返回的是对象myint，因此可以采用引用的方式传左移重载函数（ << ）中进行重载；
////2、但后置递增（myint++）时，对象myint虽然加了1，但是返回的却是局部变量temp记录的值（常量）而不是对象myint，
////此时需要拿个变量去接收，但是左移重载函数并没有实现此功能，而是直接传进去引用了，
////相当于MyInteger & myint = 10（直接给常量起别名myint，但这是非法的）。
//
//void test1()
//{
//	MyInteger myint;
//	cout << ++(++myint) << endl;
//	cout << myint << endl;
//}
//void test2()
//{
//	MyInteger myint1;
//	cout << ((myint1++)++)++ << endl;
//	cout << myint1 << endl;//实际上只递增了一次
//}
//int main()
//{
//	test1();
//	test2();
//	return 0;
//}

//赋值运算符重载
//C++编译器至少给一个类添加四个函数
//1.默认构造函数(无参，函数体为空)
//2.默认析构函数(无参，函数体为空)
//3.默认拷贝构造函数,对属性进行值拷贝
//4.赋值运算符 operator= 对属性进行值拷贝
//如果类中有属性指向堆区，做赋值操作时也会出现深浅拷贝的问题
//class Person
//{
//public:
//	Person(int age)
//	{
//		m_age = new int(age);
//	}
//	~Person()
//	{
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//	}
//	//返回类型为Person& ,可以进行链式操作
//	Person& operator=(Person& p)
//	{
//		//编译器提供的是浅拷贝
//		//m_age = p.m_age;
//
//		//应先判断是否有属性在堆区，如果有先释放，然后再深拷贝
//		if (m_age != NULL)
//		{
//			delete m_age;
//			m_age = NULL;
//		}
//		m_age = new int(*p.m_age);
//		return *this;
//	}
//	int* m_age;
//};
//void test1()
//{
//	Person p1(10);
//	Person p2(20);
//	Person p3(30);
//	p3 = p2 = p1;
//	cout << *p1.m_age << endl;
//	cout << *p2.m_age << endl;
//	cout << *p3.m_age << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}

//关系运算符重载

//class Person
//{
//public:
//	Person(string name, int age)
//	{
//		this->name = name;
//		this->age = age;
//	}
//	bool operator==(Person& p)
//	{
//		if (name == p.name && age == p.age)
//			return true;
//		else
//			return false;
//	}
//	bool operator!=(Person& p)
//	{
//		if (name != p.name || age != p.age)
//			return true;
//		else
//			return false;
//	}
//	string name;
//	int age;
//};
//int main()
//{
//	Person p1("www", 18);
//	Person p2("www", 18);
//	if (p1 == p2)
//	{
//		cout << "p1==p2" << endl;
//	}
//	else
//	{
//		cout << "p1!=p2" << endl;
//	}
//	if (p1 != p2)
//	{
//		cout << "p1!=p2" << endl;
//	}
//	else
//	{
//		cout << "p1==p2" << endl;
//	}
//	return 0;
//}


//函数调用运算符()重载
//由于重载后使用的方式非常像函数的调用，因此成为仿函数
//仿函数没有固定写法，非常灵活
//#include<string>
//class MyPrint
//{
//public:
//	
//	void operator()(string test)
//	{
//		cout << test << endl;
//	}
//	string test;
//};
//void MyPrint2(string test)
//{
//	cout << test << endl;
//}
//void test1()
//{
//	MyPrint myprint;
//	myprint("hello");//由于重载后使用的方式非常像函数的调用，因此成为仿函数
//	MyPrint2("world");
//}
////仿函数没有固定写法，非常灵活
////加法类
//class MyAdd
//{
//public:
//	int operator()(int num1,int num2)
//	{
//		return num1 + num2;
//	}
//};
//void test2()
//{
//	MyAdd myadd;
//	cout << myadd(10, 20) << endl;
//	
//	//匿名函数对象
//	cout << MyAdd()(100, 200) << endl;
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}



//继承 

//继承的好处：可以减少代码的重复
//语法：  class 子类 ：继承方式  父类
//子类也叫派生类，父类也叫基类

//父类
//class BasePage
//{
//public:
//	void left()
//	{
//		cout << "左边页面的内容" << endl;
//	}
//	void right()
//	{
//		cout << "右边页面的内容" << endl;
//	}
//	void header()
//	{
//		cout << "头部页面的内容" << endl;
//	}
//	void footer()
//	{
//		cout << "底部页面的内容" << endl;
//	}
//};
////子类
//class CPP :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "CPP内容" << endl;
//	}
//};
//class PY :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "py内容" << endl;
//	}
//};
//class Java :public BasePage
//{
//public:
//	void content()
//	{
//		cout << "Java内容" << endl;
//	}
//};
//void test1()
//{
//	CPP cpp;
//	cpp.header();
//	cpp.left();
//	cpp.right();
//	cpp.footer();
//	cpp.content();
//
//	PY py;
//	py.header();
//	py.left();
//	py.right();
//	py.footer();
//	py.content();
//
//	Java java;
//	java.header();
//	java.left();
//	java.right();
//	java.footer();
//	java.content();
//}
//int main()
//{
//	test1();
//	return 0;
//}

//继承方式

//公共权限
//class Base1
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//class Son1 :public Base1
//{
//public:
//	void func()
//	{
//		m_a = 10;//父类中的公共权限的成员，到子类中依然是公共权限
//		m_b = 10;//父类中的保护权限的成员，到子类中依然是保护权限
//		//m_c = 10;//父类中的私有权限的成员，子类访问不到
//	}
//};
//void test1()
//{
//	Son1 son1;
//	son1.m_a = 100;
//	//son1.m_b = 100;//son1中的m_b依然是保护权限，类外不可访问
//}
//
////保护继承
//class Base2
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//class Son2 :protected Base2
//{
//public:
//	void func()
//	{
//		m_a = 10;//父类中的公共权限的成员，到子类中变为保护权限
//		m_b = 10;//父类中的保护权限的成员，到子类中依然是保护权限
//		//m_c = 10;//父类中的私有权限的成员，子类访问不到
//	}
//};
//void test2()
//{
//	Son2 son2;
//	//son2.m_a = 100; //son2中的m_a变为保护权限，类外不可访问
//	//son2.m_b = 100; //son2中的m_b依然是保护权限，类外不可访问
//	//son2.m_c = 100; //son2中的m_c是私有权限，类外不可访问
//}
//
////私有权限
//class Base3
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//class Son3 :private Base3
//{
//public:
//	void func()
//	{
//		m_a = 10;//父类中的公共权限的成员，到子类中变为私有权限
//		m_b = 10;//父类中的保护权限的成员，到子类中变为私有权限
//		//m_c = 10;//父类中的私有权限的成员，子类访问不到
//	}
//};
//class GrandSon :public Son3
//{
//public:
//	void func()
//	{
//		//m_a = 100;
//		//m_b = 100;
//		//因为Son3中m_a  m_b为私有权限，孙子也无法访问儿子的私有内容
//	}
//};
//void test3()
//{
//	Son3 s3;
//	//s3.m_a = 100;//son3中的m_a变为私有权限，类外不可访问
//	//s3.m_b = 100;//son3中的m_b变为私有权限，类外不可访问
//}
//int main()
//{
//	test1();
//	return 0;
//}

//继承中的对象模型

//class Base
//{
//public:
//	int m_a;
//protected:
//	int m_b;
//private:
//	int m_c;
//};
//class Son :public Base
//{
//public:
//	int s1;
//};
//void test1()
//{
//	Son s1;
//	cout << sizeof(s1) << endl;
//	//16
//	//父类中所有非静态成员属性都会被子类继承下去
//	//父类中的私有属性，是被编译器隐藏了，因此访问不到，但是确实被继承下去了
//}
//int main()
//{
//	test1();
//	return 0;
//}

//继承中的析构和构造顺序

//class Base
//{
//public:
//	Base()
//	{
//		cout << "Base的构造函数" << endl;
//	}
//	~Base()
//	{
//		cout << "Base的析构函数" << endl;
//	}
//};
//class Son :public Base
//{
//public:
//	Son()
//	{
//		cout << "Son的构造函数" << endl;
//	}
//	~Son()
//	{
//		cout << "Son的析构函数" << endl;
//	}
//};
//int main()
//{
//	//Base b1;
//	Son s1;
//	//先构造父类，再构造子类，析构顺序与构造顺序相反
//	return 0;
//}

//继承同名成员处理方式

//class Base
//{
//public:
//	Base()
//	{
//		a = 200;
//	}
//	void func()
//	{
//		cout << "Base func()" << endl;
//	}
//	void func(int a)
//	{
//		cout << "Base func(int a)" << endl;
//	}
//	int a;
//};
//class Son :public Base
//{
//public:
//	Son()
//	{
//		a = 100;
//	}
//	void func()
//	{
//		cout << "Son func()" << endl;
//	}
//	int a;
//};
//int main()
//{
//	Son s1;
//	cout << s1.a << endl;
//	//如果通过子类对象访问父类中的同名成员，需要加作用域
//	cout << s1.Base::a << endl;
//
//	//同名函数
//	s1.func();//直接调用是子类中的成员函数
//	s1.Base::func();//调用父类中的同名函数，需加作用域
//
//	//如果子类中出现了和父类同名的成员函数，子类中的同名成员会隐藏掉父类中所有的同名成员函数，包括重载函数
//	//访问父类中被隐藏掉的同名成员函数，需加作用域
//	//s1.func(100);
//	s1.Base::func(100);
//	return 0;
//}

//继承中同名静态成员处理方式

//class Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Base func()" << endl;
//	}
//	static void func(int a)
//	{
//		cout << "Base func(int a)" << endl;
//	}
//};
//int Base::m_a = 100;
//
//class Son :public Base
//{
//public:
//	static int m_a;
//	static void func()
//	{
//		cout << "Son func()" << endl;
//	}
//};
//int Son::m_a = 200;
//
////同名静态成员属性
//void test1()
//{
//	//1. 通过对象访问
//	Son s1;
//	cout << s1.m_a << endl;
//	cout << s1.Base::m_a << endl;
//
//	//2. 通过类名访问
//	cout << Son::m_a << endl;
//	//第一个::代表通过类名访问，第二个::代表访问父类作用域下
//	cout << Son::Base::m_a << endl;
//}
//
////同名静态成员函数
//void test2()
//{
//	//1. 通过对象访问
//	Son s1;
//	s1.func();
//	s1.Base::func();
//
//	//2. 通过类名访问
//	Son::func() ;
//	//第一个::代表通过类名访问，第二个::代表访问父类作用域下
//	Son::Base::func();
//
//	//如果子类中出现了和父类同名的静态成员函数，子类中的同名静态成员会隐藏掉父类中所有的同名成员函数，包括重载函数
//	//访问父类中被隐藏掉的同名成员函数，需加作用域
//	//s1.func(100);
//	Son::Base::func(100);
//}
//int main()
//{
//	//test1();
//	test2();
//	return 0;
//}

//多继承语法
//class 子类：继承方式 父类1，继承方式 父类2...
//当父类中出现同名成员，需加作用域

//class Base1
//{
//public:
//	Base1()
//	{
//		m_a = 100;
//	}
//	int m_a;
//};
//class Base2
//{
//public:
//	Base2()
//	{
//		m_a = 200;
//	}
//	int m_a;
//};
//class Son:public Base1,public Base2
//{
//public:
//	Son()
//	{
//		m_c = 300;
//		m_d = 400;
//	}
//	int m_c;
//	int m_d;
//};
//void test1()
//{
//	Son s;
//	cout << sizeof(Son) << endl;//16
//	cout << s.Base1::m_a << endl;
//	cout << s.Base2::m_a << endl;
//}
//int main()
//{
//	test1();
//	return 0;
//}

//菱形继承
//两个派生类继承同一个基类
//又有一个类同时继承这两个派生类
//这种继承被称为菱形继承，或钻石继承

//class Animal
//{
//public:
//	int m_age;
//};
////继承之前加上关键字virtual，变为虚继承
////Animal父类变为虚基类
//class Sheep:virtual public Animal{};
//class Tuo :virtual public Animal{};
//class SheepTuo :public Sheep, public Tuo{};
//int main()
//{
//	SheepTuo st;
//	st.Sheep::m_age = 18;
//	st.Tuo::m_age = 28;
//	//当菱形继承，两个父类拥有相同数据，需加上作用域区分
//	cout << st.Sheep::m_age << endl;
//	cout << st.Tuo::m_age << endl;
//	//这份数据只有一份就可以，菱形继承会导致资源浪费
//	// 可以利用虚继承解决这个问题
//	cout << st.m_age << endl;
//
//	cout << sizeof(SheepTuo) << endl;
//	//24: 因为虚继承方式中会多出一个虚指针，用于指向同一份数据，所以大小会多出一个指针的大小
//	return 0;
//}
