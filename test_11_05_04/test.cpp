#include <iostream>
using namespace std;

//��ָ����ʳ�Ա����
//���Է��ʣ�����Ҫ�䱸

class Person
{
public:
	//��Ա����

	void ShowClassName()
	{
		cout << "this is Person class" <<endl;
	}
	void ShowClassAge()
	{
		if (this == NULL)
		{
			return;
		}
		cout << "age = " << this->m_Age << endl;
	}

	//��Ա����
	int m_Age;

};


void test()
{
	Person* p = NULL;
	p->ShowClassName();
	//�ܷ��ʳ�Ա�����������ܷ��ʳ�Ա����
	//p->ShowClassAge();
}


int main()
{
	test();
	system("pause");
	return 0;
}