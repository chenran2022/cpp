//STL  ��׼ģ���

#include <iostream>
#include<string>
using namespace std;



//int main()
//{
//	string s1;
//	string s2("hfdsjak");
//	string s3(s2);
//	string s4 = "dfsa";	//���������Ż���������s2
//	string s6 = s4;
//
//	string s5(10, 'a'); //��ʼ��Ϊn���ַ����ַ���
//	string s7("fsafasf", 4);//��ʼ��Ϊ�ַ�����ǰn���ַ�
//	string s8(s2, 1, 4);//��string�ַ�����ĳ��λ����ָ�����ȿ�����ʼ��
//	string s9(s2, 1);
//	string s10(s2, 1, string::npos);
//	//9��10һ����9�и�ȱʡĬ��ֵnpos,���ַ�����β
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
//	//s.push_back('6');//push_backֻ��β��һ���ַ�
//	//cout << s << endl;
//	//s.append("789");//append����β���ַ���
//	//cout << s << endl;
//
//	////+=�ȿ���β��һ���ַ���Ҳ����β���ַ���
//	//s += '1';
//	//cout << s << endl;
//	//s += "12345";
//	//cout << s << endl;
//
//
//	//�������ַ���ת������
//	string s("123412");
//	int tmp = 0;
//	for (size_t i = 0; i < s.size(); ++i)
//	{
//		tmp *= 10;
//		tmp += (s[i]-'0');//�ַ�����תΪ����
//	}
//	cout << tmp;
//
//	return 0;
//}




//��������һ����ָ�룬��ָ��һ���Ķ���
//��������Ϊ���֣�
//			��������ͷ���
//			���ԣ���ͨ��const
//
//int str2int(const string& str)
//{
//	//str��const���Σ�str.begin���ص���const_inerator
//	//string::iterator it = str.begin();
//	string::const_iterator it = str.begin();
//	//const_ineratorֻ�ܶ�������д
//	int num = 0;
//	while (it != str.end())
//	{
//		//*it = 1;//����д
//		num *= 10;
//		num += (*it-'0');
//		++it;
//	}
//
//	//����const������
//	//auto ri = str.rbegin();
//	string::const_reverse_iterator ri = str.rbegin();
//	int num2 = 0;
//	while (ri != str.rend())
//	{
//		//*ri = 1;//����д
//		num2 *= 10;
//		num2 += (*ri - '0');
//		++ri;
//	}
//	return num2;
//}
//int main()
//{
//	string s("hello");
//	//[]+�±� 
//	//д
//	size_t i = 0;
//	for (; i < s.size(); ++i)
//	{
//		s[i] += 1;
//	}
//	//��
//	for (i = 0; i < s.size(); ++i)
//	{
//		cout << s[i] << " ";
//	}
//	cout << endl;
//
//
//	//������
//	//д
//	string::iterator it = s.begin();
//	while (it != s.end())
//	{
//		*it -= 1;
//		++it;
//	}
//
//	//��
//	it = s.begin();
//	while (it != s.end())
//	{
//		cout << *it << " " ;
//		++it;
//	}
//	cout << endl;
//	//��Χfor  
//	//C++11  ԭ��-�����滻�ɵ�����
//	for (auto au : s)
//	{
//		cout  << au << " ";
//	}
//	cout << endl;
//
//	//���������,�������
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
//	cout << s.max_size() << endl;//ûʲô����
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
//	//s.reserve(100);//�޸�capacity,�����޸�size
//	//cout << "size" << s.size() << endl;
//
//	//s.resize(100);//�޸�size,capacity����Ҳ������capacity
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
//	//��ָ��λ�ò���
//	s.insert(s.begin(), '0');
//	cout << s << endl;
//	s.insert(2, "wht");
//	cout << s << endl;
//
//	/*s.erase(5);
//	cout << s << endl;*/
//	s.erase(2, 3);//�ӵڶ���λ��ɾ�������ַ�
//	cout << s << endl;
//	s.erase();
//	cout << s << endl;
//
//	return 0;
//}


