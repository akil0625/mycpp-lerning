#include <iostream>
#include <string>
using namespace std;
//�����Ž�������ʵ�ַº���
//�º���
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
