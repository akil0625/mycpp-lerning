#include <iostream>
#include <string>
using namespace std;
//模板
template<typename T>//typename可以替换为class
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
	//自动推导参数类型
	mswap(a, b);
	cout << a <<" " << b << endl;
	//手动确定参数类型
	mswap<int>(a, b);
	cout << a << " " << b << endl;
}


int main()
{
	test();
	system("pause");
	return 0;
}