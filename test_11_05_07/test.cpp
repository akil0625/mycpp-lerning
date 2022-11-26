#include <iostream>
#include <string>
using namespace std;
class Building;
class GoodGay
{
public:
	GoodGay();

	void visit();
	Building* building;

};

class Building
{
	friend class GoodGay;
public:
	Building();
public:
	string m_SettingRoom;

private:
	string m_BedRoom;

};
//类外写成员函数
Building::Building()
{
	m_SettingRoom = "客厅";
	m_BedRoom = "卧室";
}
GoodGay::GoodGay()
{
	//创建一个建筑物的对象
	building = new Building;
}
void GoodGay::visit()
{
	cout << "好基友类正在访问:" << building->m_SettingRoom << endl;
	cout << "好基友类正在访问:" << building->m_BedRoom << endl;

}

void test()
{
	GoodGay gg;
	gg.visit();

}

int main()
{
	test();
	system("pause");
	return 0;
}