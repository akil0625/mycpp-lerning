#include <iostream>
#include <string>
using namespace std;
//ģ��
template<typename T>//typename�����滻Ϊclass
void mswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

void test()
{
	int a = 10;
	int b = 20;
	cout << a <<" " << b << endl;
	//�Զ��Ƶ���������
	mswap(a, b);
	cout << a <<" " << b << endl;
	//�ֶ�ȷ����������
	mswap<int>(a, b);
	cout << a << " " << b << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}