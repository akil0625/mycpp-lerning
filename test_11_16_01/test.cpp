#include <iostream>
using namespace std;
#include <string>

//�̳з�ʽ


class Basic
{
public:
	int m_A;
protected:
	int m_B;
private:
	int m_C;
};
//�����̳�
class Son1:public Basic
{
public:
	void func()
	{
		m_A = 10;//�����еĹ���Ȩ�޳�Ա ����������Ȼ�ǹ���Ȩ��
		m_B = 10;//�����е��ܱ���Ȩ�޳�Ա ����������Ȼ���ܱ���Ȩ��
		//m_C = 10;�����е�˽��Ȩ�޳�Ա�����޷���õ�
	}
};



void test01()
{
	Son1 s1;
	s1.m_A = 100;
	//s1.m_B = 100;����Ȩ���޷����������

}
//�����̳�
class Son2:protected Basic
{
public:
	void func()
	{
		m_A = 20;
		m_B = 20;
		//m_C = 20;�����޷����ʸ����е�˽��Ȩ�޳�Ա
	}



};

//˽�м̳�
void test02()
{
Son2 son2;
//son2.m_A = 200;�����̳е����ཫ�����еĹ���Ȩ�޳�Ա�ı�Ϊ�ܱ�����Ȩ�޳�Ա
//son2.m_B = 200;�����̳е����ཫ�����е��ܱ�����Ȩ�޳�Ա�����̳�Ϊ�ܱ�����Ȩ�޳�Ա
//son2.m_C = 200;���۹����̳С������̳л���˽�м̳ж��޷����ʵ������е�˽��Ȩ�޳�Ա
}
class Son3 :private Basic
{
public:
	void func()
	{
		m_A = 30;
		m_B = 30;
		//m_C = 30;���۹����̳С������̳л���˽�м̳ж��޷����ʵ������е�˽��Ȩ�޳�Ա
	}


};

void test03()
{
	Son3 son3;
	//son3.m_A;
	//son3.m_B;
	//son3.m_C;
	//˽�м̳н��̳е������г�Ա��תΪ˽��Ȩ�޳�Ա���޷��̳еõ������е�˽��Ȩ�޳�Ա��
}


int main()
{
	test01();
	test02();
	system("pause");
	return 0;
}