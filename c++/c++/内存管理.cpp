#include <iostream>
using namespace std;
//
//
//int main()
//{
//	//C  ����
//	int* p1 = (int*)malloc(sizeof(int));
//	int* p3 = (int*)malloc(sizeof(int) * 10);
//	
//	free(p1);
//	free(p3);
//	
//	//C++ ������
//	int* p2 = new int;//���ֵ
//	//int* p2 = new int(10);  //����һ��int4���ֽڵĿռ䣬��ʼ��Ϊ10
//	int* p4 = new int[10];    //����10��int��40���ֽڵĿռ�
//
//	delete p2;
//	delete[] p4;
//	return 0;
//}



//��Ȼ�Ѿ�����malloc��free��new��delete���������

//1. �����������ͣ�Ч��һ��
//2. �����Զ������ͣ�Ч���Ͳ�һ���ˡ�mallocֻ����ռ䣬new����ռ�+���캯����ʼ��
//		freeֻ�ͷſռ䣬delete��������+�ͷſռ�
class MyClass
{
public:
	MyClass()
	{
		_a = 10;
		cout << "MyClass" << endl;
	}
	~MyClass()
	{
		cout << "~MyClass" << endl;
	}
	void test()
	{
		cout << "test" << endl;
	}

private:
	int _a;
};
int main()
{
	int* p1 = new int;
	int* p2 = (int*)malloc(sizeof(int));
	//������������int��p1��p2Ч��һ��


	// �Զ�������
	MyClass* p4 = (MyClass*)malloc(sizeof(MyClass));//����ռ�
	MyClass* p3 = new MyClass;	//����ռ�+���캯����ʼ��
	free(p4);		//�ͷſռ�
	delete p3;		//��������+�ͷſռ�
	return 0;
}