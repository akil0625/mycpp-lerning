#include <iostream>
using namespace std;

//��ģ��ļ̳�

//1.������̳е�����ģ��ʱ����Ҫ��������ʱ��ָ������ģ����T������
//2.�����ָ������������޷�����������ڴ�
//3.��������ָ��������ģ����T�����ͣ�����Ҳ��Ҫ��Ϊ��ģ��

template<class T>
class Base
{
public:
	Base()
	{
		cout << "Base��T������Ϊ:" << typeid(T).name() << endl;
	}
	T m;
};

//��ģ������
class Son1:public Base<int>//ָ��������T������
{
};

//ģ������
template<class T1,class T2>
class Son2 :public Base<T1>//ָ��������T������
{
public:
	Son2()
	{
		cout << "Son2��T1������" << typeid(T1).name() << endl << "Son2��T2������" << typeid(T2).name() << endl;
	}
	T2 obj;
};

void test1()
{
	Son1 p;//ȷ��T�����ͺ�Ͷ�����T������
	p.m = 1;
	cout << p.m << endl;
}

void test2()
{
	Son2<string, int>p;//��ģ��̳���ģ��������
	p.m = "haha";
	p.obj = 2;
	cout << p.m << endl << p.obj << endl;
}

//������
int main()
{
	test1();
	test2();
	system("pause");
	return 0;
}