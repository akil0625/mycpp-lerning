#include <iostream>
using namespace std;
//const ���γ�Ա����Ϊ������
//���������޷��޸ĳ�Ա����
//���Ϲؼ���mutable��ɶԳ�Ա���������޸�


class Person
{
public:
	void ShowPerson() const//�����const��thisָ��Ķ����Ϊ�����޸ģ�����ָ�룩
	{
		cout << this->m_A << endl;
		cout << this->m_B << endl;
		this->m_A = 100;//this Ϊָ�볣�� �޷��޸�ָ��Ķ���
		//this->m_B = 100;//<-�����޸�
	}
	void ShowB()
	{
		cout << m_B << endl;
	}

	mutable int m_A = 100;
	int m_B = 100;

};


 
void test()
{

}

void test1()
{
	const Person p;
	//������ֻ�ܹ����ó�����
	//p.ShowB();
	//����mutable���Ӧ��ֵ�ڳ�������Ҳ���޸�
	p.ShowPerson();
	p.m_A = 200;

}


int main()
{
	test1();
	system("pause");
	return 0;
}