#include <iostream>
#include <string>
using namespace std;

//���麯����д��
class Base
{
public:
	virtual void func() = 0;
};

//ֻҪ����һ�����⺯������ô�������Ǵ��麯��
class Son:public Base
{
public:

	//���麯����Ҫ����������д
	virtual void func()
	{
		cout << "������д���麯��" << endl;
	}
};

//����
void test()
{
	//Son s;
	//s.func();
	Base* b = new Son;
	b->func();
}

//������
int main()
{
	test();
	system("pause");
	return 0;
}