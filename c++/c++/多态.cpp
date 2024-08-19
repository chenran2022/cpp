#include<iostream>
using namespace std;

/*
多态的两个条件：
1.虚函数的重写
2.父类对象的指针或者引用去调用虚函数
满足多态：跟调用对象的类型无关，跟指向对象有关，指向哪个对象就是调用的他的虚函数
不满足多态：跟调用对象的类型有关，类型是什么调用的就是谁的虚函数

虚函数的重写(覆盖)：派生类中有一个跟基类完全相同的虚函数
(即派生类虚函数与基类虚函数的返回值类型、函数名字、参数列表完全相同)，
称子类的虚函数重写了基类的虚函数。

virtual关键字:	可以修饰成原函数，为了完成虚函数的重写，满足多态的条件之一
				可以在菱形继承中，去完成虚继承，解决数据冗余和二义性。
两个地方使用了同一个关键字，但是他们互相之间没有一点关联
*/

//class Person 
//{
//public:
//	virtual void BuyTicket() { cout << "买票-全价" << endl; }
//};
//class Student : public Person
//{
//public:
//	virtual void BuyTicket() { cout << "买票-半价" << endl; }
//	/*注意：在重写基类虚函数时，派生类的虚函数在不加virtual关键字时，
//	虽然也可以构成重写(因为继承后基类的虚函数被继承下来了在派生类依旧保持虚函数属性),
//	但是该种写法不是很规范，不建议这样使用*/
//	/*void BuyTicket() { cout << "买票-半价" << endl; }*/
//};
//void Func(Person& p)
//{
//	//满足多态的情况,跟调用对象的类型无关，跟指向对象有关，指向哪个对象就是调用的他的虚函数
//	p.BuyTicket();
//}
//void Func1(Person* p)
//{
//	//满足多态的情况,跟调用对象的类型无关，跟指向对象有关，指向哪个对象就是调用的他的虚函数
//	p->BuyTicket();
//}
//void Func2(Person  p)
//{
//	//不满足多态的情况
//	p.BuyTicket();
//}
//int main()
//{
//	Person ps;
//	Student st;
//	Func(ps);
//	Func(st);
//	
//	Func1(&ps);
//	Func1(&st);
//
//	Func2(ps);
//	Func2(st);
//	return 0;
//}

/*
虚函数重写的两个例外：
1. 协变(基类与派生类虚函数返回值类型不同,返回值必须是基类和派生类的指针或引用)
派生类重写基类虚函数时，与基类虚函数返回值类型不同。
即基类虚函数返回基类对象的指针或者引用，派生类虚函数返回派生类对象的指针或者引用时，称为协变
2. 析构函数的重写(基类与派生类析构函数的名字不同)
如果基类的析构函数为虚函数，此时派生类析构函数只要定义，无论是否加virtual关键字，
都与基类的析构函数构成重写，虽然基类与派生类析构函数名字不同。虽然函数名不相同，
看起来违背了重写的规则，其实不然，这里可以理解为编译器对析构函数的名称做了特殊处理，
编译后析构函数的名称统一处理成destructor。
*/
//1.协变
/*class A {};
class B : public A {};
class Person {
public:
	virtual A* f() { return new A; }
	virtual Person* f1() { return new Person; }
};
class Student : public Person {
public:
	virtual B* f() { return new B; }
	virtual Student* f1() { return new Student; }
};*/

//2. 析构函数的重写
/*class Person {
public:
	virtual ~Person() { cout << "~Person()" << endl; }
	//编译后析构函数的名称统一处理成destructor。
};
class Student : public Person {
public:
	virtual ~Student() { cout << "~Student()" << endl; }
	//编译后析构函数的名称统一处理成destructor。
};
// 只有派生类Student的析构函数重写了Person的析构函数，下面的delete对象调用析构函数，才能构成多态，
// 才能保证p1和p2指向的对象正确的调用析构函数。
int main()
{
	Person* p1 = new Person;
	delete p1;

	Person* p2 = new Student;
	//如果不使用虚函数重写析构，delete就不会调用Student的析构函数，
	//因为不满足多态，跟调用对象的类型有关，类型是什么调用的就是谁的虚函数
	//如果Student析构函数中有资源释放这里没有被调用到，就会发生内存泄漏，所以析构函数定义要定义为虚函数

	delete p2;

	return 0;
}*/

/*
class A
{
public:
	virtual void func(int val = 1) { std::cout << "A->" << val << std::endl; }
	virtual void test() //A* this
	{
		func();//满足多态条件 
	}
};
class B : public A
{
public:
	void func(int val = 0) 
	//成员函数继承只会把函数名、参数、返回值继承下来，不会继承函数体，
	//然后虚函数重写只会重写函数体，所以这里的int val = 0不起作用,前提是在满足多态的条件下
	{
		std::cout << "B->" << val << std::endl; 
	}
};
int main(int argc, char* argv[])
{
	A* pa = new B;
	pa->func();
	B* p = new B;
	p->test();
	p->B::func();//不满足多态
	return 0;
}
*/


//C++11 override 和 final

//final：修饰虚函数，表示该虚函数不能再被重写;修饰类，表示该类不能被继承
/*class Car final  //修饰类，表示该类不能被继承
{
public:
	virtual void Drive() final {}//修饰虚函数，表示该虚函数不能再被重写;
};
class Benz :public Car
{
public:
	virtual void Drive() { cout << "Benz-舒适" << endl; }
};*/

//override : 检查派生类虚函数是否重写了基类某个虚函数，如果没有重写编译报错。
/*class Car {
public:
	virtual void Dirve() {}
};
class Benz :public Car {
public:
	virtual void Drive() override { cout << "Benz-舒适" << endl; }
};
int main()
{
	return 0;
}*/

/*
重载:	1.两个函数在同一作用域
		2.函数名相同，参数不同
	
重写(覆盖):	1.两个函数分别在基类和派生类的作用域
			2.函数名 / 参数 / 返回值都必须相同(协变例外)
			3.两个函数必须是虚函数

重定义(隐藏)：	1.两个函数分别在基类和派生类的作用域
				2.函数名相同
				3.两个基类和派生类的同名函数不构成重写就是重定义
*/

/*
在虚函数的后面写上 = 0 ，则这个函数为纯虚函数。
包含纯虚函数的类叫做抽象类(也叫接口类)，抽象类不能实例化出对象。
派生类继承后也不能实例化出对象，只有重写纯虚函数，派生类才能实例化出对象。
纯虚函数规范了派生类必须重写，另外纯虚函数更体现出了接口继承。
纯虚函数的作用:	1、强制子类去完成重写
				2、表示抽象的类型。抽象就是在现实中没有对应的实体的。
*/
/*class Car
{
public:
	virtual void Drive() = 0;
};
//如果不对纯虚函数进行重写，则继承后还是一个抽象类，也不能实例化对象
class Benz :public Car
{
public:
	virtual void Drive()
	{
		cout << "Benz-舒适" << endl;
	}
};
void main()
{
	//Car c;//不能实例化对象
	Benz b;
}*/

/*
普通函数的继承是一种实现继承，派生类继承了基类函数，可以使用函数，继承的是函数的实现。
虚函数的继承是一种接口继承，派生类继承的是基类虚函数的接口，目的是为了重写，达成多态，继承的是接口。
所以如果不实现多态，不要把函数定义成虚函数。
*/

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Func2()" << endl;
	}
	void Func3()
	{
		cout << "Func3()" << endl;
	}

private:
	int _b = 1;
};
int main()
{
	Base b;
	cout << sizeof(b) << endl;
	//除了_b成员，还多一个 vfptr放在对象的前面(注意有些平台可能会放到对象的最后面，这个跟平台有关)，
	//对象中的这个指针我们叫做虚函数表指针(v代表virtual，f代表function)。
	//一个含有虚函数的类中都至少都有一个虚函数表指针，因为虚函数的地址要被放到虚函数表中，虚函数表也简称虚表，
	//虚函数表其实就是一个指针数组（虚函数指针,规定以空指针为结束标记）
	return 0;
}
*/

/*
class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
	virtual void Func2()
	{
		cout << "Base::Func2()" << endl;
	}
	void Func3()
	{
		cout << "Base::Func3()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
void test1()
{
	Base b2;
	
	Derive d2;
}
void test2()
{
	Base b3;
	Derive d3;
}
int main()
{
	Base b;
	b.Func1();
	Derive d;
	d.Func1();
	//多态如何实现的指向谁就调用谁的虚函数 ?
	//多态是在运行时到指向的对象的虚表中查找要调用的虚函数的地址来进行调用
	test1();
	test2();
	//普通函数和虚函数都会被编译成指令以后存在代码段
	//虚函数表也是存在代码段，同类型的对象共用一个虚表
	return 0;
}
*/

/*
1. 静态绑定又称为前期绑定(早绑定)，在程序编译期间确定了程序的行为，也称为静态多态，
比如：函数重载
2. 动态绑定又称后期绑定(晚绑定)，是在程序运行期间，根据具体拿到的类型确定程序的具体行为，
调用具体的函数，也称为动态多态
*/

/*class Base
{
public:
	virtual void Func1()
	{
		cout << "Base::Func1()" << endl;
	}
private:
	int _b = 1;
};
class Derive : public Base
{
public:
	virtual void Func1()
	{
		cout << "Derive::Func1()" << endl;
	}
private:
	int _d = 2;
};
int main()
{
	//静态绑定  静态的多态 静态：编译期间
	int i = 0;
	double d = 1.1;
	cout << i << endl;
	cout << d << endl;

	//动态绑定	动态的多态 动态：运行时
	Base* p = new Base;
	p->Func1();
	p = new Derive;
	p->Func1();

	return 0;
}*/

//单继承中的虚函数表
/*class Base {
public:
	virtual void func1() { cout << "Base::func1" << endl; }
	virtual void func2() { cout << "Base::func2" << endl; }
private:
	int a;
};
class Derive :public Base {
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
	virtual void func4() { cout << "Derive::func4" << endl; }
private:
	int b;
};

//void(*p)() 定义一个函数指针变量
typedef void(*VFPTR)(); //函数指针类型重定义

//打印虚表
void PrintVTable(VFPTR vTable[])
{
	// 依次取虚表中的虚函数指针打印并调用。调用就可以看出存的是哪个函数
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f(); 
	}
	cout << endl;
}
int main()
{
	Base b;
	Derive d;
	// 思路：取出b、d对象的头4bytes，就是虚表的指针，
	// 前面我们说了虚函数表本质是一个存虚函数指针的指针数组，这个数组最后面放了一个nullptr
	// 1.先取b的地址，强转成一个int*的指针
	// 2.再解引用取值，就取到了b对象头4bytes的值，这个值就是指向虚表的指针
	// 3.再强转成VFPTR*，因为虚表就是一个存VFPTR类型(虚函数指针类型)的数组。
	// 4.虚表指针传递给PrintVTable进行打印虚表
	// 5.需要说明的是这个打印虚表的代码经常会崩溃，因为编译器有时对虚表的处理不干净，虚表最后面没有放nullptr，导致越界，这是编译器的问题。
	// 我们只需要点目录栏的 - 生成 - 清理解决方案，再编译就好了。
	VFPTR* vTableb = (VFPTR*)(*(int*)&b);
	PrintVTable(vTableb);
	VFPTR* vTabled = (VFPTR*)(*(int*)&d);
	PrintVTable(vTabled);
	return 0;
}*/

//多继承中的虚函数表
class Base1{
public:
	virtual void func1() { cout << "Base1::func1" << endl; }
	virtual void func2() { cout << "Base1::func2" << endl; }
private:
	int b1;
};
class Base2{
public:
	virtual void func1() { cout << "Base2::func1" << endl; }
	virtual void func2() { cout << "Base2::func2" << endl; }
private:
	int b2;
};
class Derive : public Base1, public Base2{
public:
	virtual void func1() { cout << "Derive::func1" << endl; }
	virtual void func3() { cout << "Derive::func3" << endl; }
private:
	int d1;
};
typedef void(*VFPTR) ();
void PrintVTable(VFPTR vTable[])
{
	cout << " 虚表地址>" << vTable << endl;
	for (int i = 0; vTable[i] != nullptr; ++i)
	{
		printf(" 第%d个虚函数地址 :0X%x,->", i, vTable[i]);
		VFPTR f = vTable[i];
		f();
	}
	cout << endl;
}
int main()
{
	cout << sizeof(Derive) << endl;
	Derive d;
	VFPTR* vTableb1 = (VFPTR*)(*(int*)&d);
	PrintVTable(vTableb1);
	VFPTR* vTableb2 = (VFPTR*)(*(int*)((char*)&d + sizeof(Base1)));
	PrintVTable(vTableb2);
	return 0;
}


//内联函数没有地址，放不进虚表里。所以不能是虚函数
//虚函数不可以是static函数，static函数没有this指针，不能通过对象去找虚表
