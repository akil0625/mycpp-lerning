#include <iostream>
#include <string>
using namespace std;
//对括号进行重载实现仿函数
//仿函数
class Add
{
public:
	int operator()(int l, int r)
	{
		return l + r;
	}


};



void test()
{
	Add add;
	
	cout << add(4, 4) << endl;
	cout << Add()(4, 3) << endl;


}

int main()
{
	test();
	system("pause");
	return 0;
}
