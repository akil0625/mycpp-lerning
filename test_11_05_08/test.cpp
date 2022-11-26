#include <iostream>
#include <string>
using namespace std;
class Building;
class GoodGay
{
public:

	GoodGay();

	void visit();//可以访问Building私有成员
	void visit2();//不能访问Building私有成员

	Building* building;


};


class Building
{
	friend void GoodGay::visit();

public:
	Building();
	string  m_SettingRoom;


private:
	string m_BedRoom;

};
Building::Building()
{
	m_BedRoom = "卧室";
	m_SettingRoom = "客厅";
}

GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::visit()
{
	cout << "visit正在访问" << building->m_SettingRoom << endl; 
		cout << "visit正在访问" << building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit2正在访问" << building->m_SettingRoom << endl;
}





void test()
{
	GoodGay gg;
	gg.visit();
	gg.visit2();

}


int main()
{
	test();


	system("pause");
	return 0;
}