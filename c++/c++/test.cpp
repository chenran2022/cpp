#include<iostream>
using namespace std;

//��������
//1:������ͬһ������
//2:�����ĸ�����ͬ�����Ͳ�ͬ��˳��ͬ
//3:����ֵ��������Ϊ���ص�����

//void test()
//{
//	cout<<"wo"<<endl;
//}
//void test(int a)
//{
//	cout << a << endl;
//}
//
////void test(int a=10, int)//Ĭ�ϲ��������ұ��붼��
////{
////	cout << "ռλ����" << a<<endl;
////}
//
//void test(int, int b = 10)
//{
//	b = 100;
//	cout << "ռλ����" << b << endl;
//}
//int main()
//{
//	int a = 10;
//	int& b = a;//���ã�����.�����ʼ������ʼ������������������ 
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


//���ô��Σ��޸�Ŀ��ֵ

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


//������Ϊ�������ص�����

//void test(int& a)//int &a=10;�������ñ���ָ��һ��Ϸ��Ŀռ䣬��10�ǳ���
//{
//	cout << "int &a" << endl;
//}
//void test(const int& a)//const int &a�����������Ż���int tmp=10;const int &a=tmp;tmpռ��һ��Ϸ��Ŀռ䣬���Ի�ִ�гɹ�
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

//�������ز�����Ĭ�ϲ���
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
//	test(10);//��������������ִ�У����Իᱨ�������ԣ�
//	system("pause");
//	return 0;
//}

//��Ͷ���
//��װ���̳С���̬

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

//class �ķ���Ȩ��
//1������Ȩ�� public	��Ա�����ڿ��Է��ʣ�������Է���
//2������Ȩ�� protected	��Ա�����ڿ��Է���	���ⲻ�ɷ���	���ӿ��Է��ʸ����еı�������
//3��˽��Ȩ�� private	��Ա�����ڿ��Է���	���ⲻ�ɷ���	���Ӳ��ɷ��ʸ����е�˽������

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
//		car = "�ذ峵";
//		password = 54188;
//		cout << name << "  " << car << "  " << password << endl;
//	}//���ڿ��Է���
//};
//int main()
//{
//	Person ps;
//	ps.name = "zhangsan";
//	/*ps.car = "����";
//	ps.password = 123456;*/
//	//���ⲻ�ɷ���
//	ps.set();
//	return 0;
//}


//struct��class������
//��C++��Ψһ���������Ĭ��Ȩ�޲�ͬ
//structĬ��Ȩ���ǹ���Ȩ�ޣ�classĬ��Ȩ����˽��Ȩ��

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
//	//c.a;//���ɷ���
//	S1 s;
//	s.b = 10;//�ɷ���
//	system("pause");
//	return 0;
//}


//��Ա��������Ϊ˽��
//�ŵ�1�������Լ����ƶ�дȨ��
//�ŵ�2������дȨ�ޣ����Լ�����ݵ���Ч��

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
//		}//������ݵ���Ч��
//		age = a;
//	}
//	
//	string GetLover()
//	{
//		lover = "she";
//		return lover;
//	}
//private:
//	string name;//�ɶ���д
//	int age;//ֻд
//	string lover;//ֻ��
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
//		cout << "���" << endl;
//	else
//		cout << "�����" << endl;
//	return 0;
//}


int main()
{

	return 0;
}