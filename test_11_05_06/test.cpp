#include <iostream>
using namespace std;

//��Ԫ
//����˽�г�Ա
/*
1.ȫ�ֺ�������Ԫ
2.������Ԫ
3.��Ա��������Ԫ
*/


//��������
class Building
{
friend	void GoodGay(Building* building);//GoodGsy��Building�ĺ�������Ԫ
public:
	Building()
	{
		m_SittingrRoom = "����";
		m_BedRoom = "����";
	}
public:
	string m_SittingrRoom;

private:
	string m_BedRoom;
};

//ȫ�ֺ���
void GoodGay(Building* building)
{
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��� : " << building->m_SittingrRoom << endl;
	cout << "�û��ѵ�ȫ�ֺ��� ���ڷ��� : " << building->m_BedRoom << endl;
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