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
//����д��Ա����
Building::Building()
{
	m_SettingRoom = "����";
	m_BedRoom = "����";
}
GoodGay::GoodGay()
{
	//����һ��������Ķ���
	building = new Building;
}
void GoodGay::visit()
{
	cout << "�û��������ڷ���:" << building->m_SettingRoom << endl;
	cout << "�û��������ڷ���:" << building->m_BedRoom << endl;

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