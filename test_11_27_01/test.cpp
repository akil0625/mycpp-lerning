#include <iostream>
using namespace std;


//��ģ���г�Ա�����Ĵ���ʱ��
//��ģ���еĳ�Ա����ֻ���ڵ��õ�ʱ��Żᴴ��


//��ͨ��
class Person1
{
public:
	void showPerson1()
	{
		cout << "����Person1" << endl;

	}
};

//��ͨ��
class Person2
{
public:
	void showPerson2()
	{
		cout << "����Person2" << endl;

	}
};

//��ģ��
template<class T>
class myclass
{
public:

	T obj;

	void function1()
	{
		obj.showPerson1();//���õĶ���δ֪�������þͲ��ᴴ��
	}

	void function2()
	{
		obj.showPerson2();
	}

};


void test()
{
	//ͨ���ı�����б�Ĳ����ɷ��ʲ�ͬ�����г�Ա����
	myclass<Person2>m;
	m.function2();


}


//������
int main()
{
	test();
	system("pause");
	return 0;
}