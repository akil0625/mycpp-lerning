#include <iostream>
#include <string>
using namespace std;
class Building;
class GoodGay
{
public:

	GoodGay();

	void visit();//���Է���Building˽�г�Ա
	void visit2();//���ܷ���Building˽�г�Ա

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
	m_BedRoom = "����";
	m_SettingRoom = "����";
}

GoodGay::GoodGay()
{
	building = new Building;
}
void GoodGay::visit()
{
	cout << "visit���ڷ���" << building->m_SettingRoom << endl; 
		cout << "visit���ڷ���" << building->m_BedRoom << endl;
}
void GoodGay::visit2()
{
	cout << "visit2���ڷ���" << building->m_SettingRoom << endl;
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