#include <iostream>
#include <string>
using namespace std;

//���������������
typedef class myinteger
{
friend	ostream& operator<<(ostream& cout, myinteger m);
public:
	myinteger()
	{
		m_int = 0;
	}
	//ǰ�üӼ�
	myinteger& operator++()//���������Ƿ�����ʽ���
	{
		this->m_int++;
		return *this;
	}
	//���üӼ�
	myinteger operator++(int)
	{
		myinteger tmp;
		tmp = *this;
		this->m_int++;
		return tmp;
	}
private:
	int m_int;

}myint;
ostream& operator<<(ostream& cout, myinteger m)
{
	cout << m.m_int;
	return cout;
}


void test()
{
	myint mint;
	cout << ++(++mint) << endl;
	cout << mint << endl;
}



int main()
{
	test();
	system("pause");
	return 0;
}