#include <iostream>
#include <string>
using namespace std;

//��ģ����ļ���д���������⼰�������

//��һ�ֽ����ʽ:ֱ�Ӱ���Դ�ļ�
//#include "Person.cpp"

//�ڶ��ֽ����ʽ:��.h�ļ���.cpp�ļ�����д��һ�𣬽���׺����Ϊ.hpp
#include "Person.hpp"

void test1()
{
	Person<string, int>p("akil", 20);
	p.showPerson();
}

int main()
{
	test1();
	system("pause");
	return 0;
}