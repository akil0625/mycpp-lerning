#include <iostream>
using namespace std;

//友元
//访问私有成员
/*
1.全局函数做友元
2.类做友元
3.成员函数做友元
*/


//建筑物类
class Building
{
friend	void GoodGay(Building* building);//GoodGsy是Building的好朋友友元
public:
	Building()
	{
		m_SittingrRoom = "客厅";
		m_BedRoom = "卧室";
	}
public:
	string m_SittingrRoom;

private:
	string m_BedRoom;
};

//全局函数
void GoodGay(Building* building)
{
	cout << "好基友的全局函数 正在访问 : " << building->m_SittingrRoom << endl;
	cout << "好基友的全局函数 正在访问 : " << building->m_BedRoom << endl;
}

void test()
{
	Building build1;
	GoodGay(&build1);

}


int main()
{
	test();

	system("pause");
	return 0;
}