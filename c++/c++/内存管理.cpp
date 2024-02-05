#include <iostream>
using namespace std;
//
//
//int main()
//{
//	//C  函数
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//	
//	free(p1);
//	free(p3);
//	
//	//C++ 操作符
//	int* p2 = new int;//随机值
//	//int* p2 = new int(10);  //申请一个int4个字节的空间，初始化为10
//	int* p4 = new int[10];    //申请10个int的40个字节的空间
//
//	delete p2;
//	delete[] p4;
//	return 0;
//}



//既然已经有了malloc和free，new和delete的意义何在

//1. 对于内置类型，效果一样
//2. 对于自定义类型，效果就不一样了。malloc只申请空间，new申请空间+构造函数初始化
//		free只释放空间，delete析构函数+释放空间
// class MyClass
// {
// public:
// 	MyClass()
// 	{
// 		_a = 10;
// 		cout << "MyClass" << endl;
// 	}
// 	~MyClass()
// 	{
// 		cout << "~MyClass" << endl;
// 	}
// 	void test()
// 	{
// 		cout << "test" << endl;
// 	}

// private:
// 	int _a;
// };
// int main()
// {
// 	int* p1 = new int;
// 	int* p2 = (int*)malloc(sizeof(int));
// 	//对于内置类型int，p1和p2效果一样


// 	// 自定义类型
// 	MyClass* p4 = (MyClass*)malloc(sizeof(MyClass));//申请空间
// 	MyClass* p3 = new MyClass;	//申请空间+构造函数初始化
// 	free(p4);		//释放空间
// 	delete p3;		//析构函数+释放空间
// 	return 0;
// }
