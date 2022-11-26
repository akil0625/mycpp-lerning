#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//�����ϵ�˽ṹ��
struct Person
{
	string m_Name;
	int m_Sex = 0;
	int m_Age = 0;
	string m_Tele;
	string m_Addr;
};

//���ͨѶ¼�ṹ��
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size = 0;
};

//�˵�����
void showMenu()
{
	cout << "******* 1.�����ϵ�� *******" << endl;
	cout << "******* 2.��ʾ��ϵ�� *******" << endl;
	cout << "******* 3.ɾ����ϵ�� *******" << endl;
	cout << "******* 4.������ϵ�� *******" << endl;
	cout << "******* 5.�޸���ϵ�� *******" << endl;
	cout << "******* 6.������ϵ�� *******" << endl;
	cout << "******* 0.�˳�ͨѶ¼ *******" << endl;
}


enum
{
	�˳���ϵ��,
	�����ϵ��,
	��ʾ��ϵ��,
	ɾ����ϵ��,
	������ϵ��,
	�޸���ϵ��,
	������ϵ��
};
//������ϵ��
int findbyname(const Addressbooks * abs, string name)
{
	for (int i = 0; i < abs->m_Size; i++)
	{
		if (name == abs->personArray[i].m_Name)
		{
			return i;
		}
	}
	return - 1;
}

//1.�����ϵ��
void addPerson(Addressbooks* abs)
{
	if(abs->m_Size==MAX)
	{
		cout << "ͨѶ¼����" << endl;
	}
	else
	{
		//��������
		string name;
		cout << "��������ϵ������>:";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//�����Ա�
		int sex = 0;
		cout << "*** 1---��  2---Ů ***\n";
		cout << "�������Ա�:>";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "������������������\n";
		}
		//��������
		int age = 0;
		cout << "����������:>";
		while (true)
		{
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "������������������\n";
		}
		//�����ֻ���
		string tele;
		cout << "�������ֻ���:>";
		cin >> tele;
		abs->personArray[abs->m_Size].m_Tele = tele;
		//סַ
		string addr;
		cout << "������סַ:>";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "��ӳɹ�\n";
	}
	system("pause");
	system("CLS");
}
//��ʾ��ϵ��
void showPerson(const Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "ͨѶ¼Ϊ��\n";
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "����: " << abs->personArray[i].m_Name << "\t";
			cout << "�Ա�: " << ( abs->personArray[i].m_Sex == 1? "��":"Ů" )<< "\t";
			cout << "����: " << abs->personArray[i].m_Age << "\t";
			cout << "�绰: " << abs->personArray[i].m_Tele << "\t";
			cout << "סַ: " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("CLS");
}
//ɾ����ϵ��
void delPerson(Addressbooks* abs)
{
	string name;
	cout << "������Ҫɾ���˵�����:>";
	cin >> name;
	int site = 0;
	site = findbyname(abs, name);
	if(site ==-1)
	{
		cout << "δ�ҵ�����ϵ��\n";
		system("pause");
		system("CLS");
		return;
	}
	else
	{
		for (int i = site; i < abs->m_Size - 1; i++)
		{
			abs->personArray[i] = abs->personArray[i + 1];
		}
		abs->m_Size--;
	}
	cout << "ɾ���ɹ�\n";
	system("pause");
	system("CLS");
}
//������ϵ��
void searchPerson(const Addressbooks* abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ��:>";
	cin >> name;
	int site = findbyname(abs, name);
	if (site == -1)
	{
		cout << "δ�ҵ�����ϵ��\n";
		system("pause");
		system("CLS");
		return;
	}
	else
	{
		cout << "����: " << abs->personArray[site].m_Name << "\t";
		cout << "�Ա�: " << (abs->personArray[site].m_Sex == 1 ? "��" : "Ů") << "\t";
		cout << "����: " << abs->personArray[site].m_Age << "\t";
		cout << "�绰: " << abs->personArray[site].m_Tele << "\t";
		cout << "סַ: " << abs->personArray[site].m_Addr << endl;
	}
	system("pause");
	system("CLS");
}
//�޸���ϵ��
void modifyPerson(Addressbooks* abs)
{
	string name;
	cout << "������Ҫ���ҵ���ϵ��:>";
	cin >> name;
	int site = findbyname(abs, name);
	if (site == -1)
	{
		cout << "δ�ҵ�����ϵ��\n";
		system("pause");
		system("CLS");
		return;
	}
	else
	{
		//��������
		string name;
		cout << "��������ϵ������>:";
		cin >> name;
		abs->personArray[site].m_Name = name;
		//�����Ա�
		int sex = 0;
		cout << "*** 1---��  2---Ů ***\n";
		cout << "�������Ա�:>";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[site].m_Sex = sex;
				break;
			}
			cout << "������������������\n";
		}
		//��������
		int age = 0;
		cout << "����������:>";
		while (true)
		{
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[site].m_Age = age;
				break;
			}
			cout << "������������������\n";
		}
		//�����ֻ���
		string tele;
		cout << "�������ֻ���:>";
		cin >> tele;
		abs->personArray[site].m_Tele = tele;
		//סַ
		string addr;
		cout << "������סַ:>";
		cin >> addr;
		abs->personArray[site].m_Addr = addr;
	}
	cout << "�޸ĳɹ�\n";
	system("pause");
	system("CLS");
}
//�����ϵ��
void cleanPerson(Addressbooks* abs)
{
	cout << "�Ƿ�ȷ�����?\n";
	cout << "*** 1.ȷ�� 2.ȡ�� ***\n";
	int i = 0;
	while(1)
	{ 
		cin >> i;
		if (i == 1)
			break;
		else if (i == 2)
		{
			cout << "ȡ�����\n";
			system("pause");
			system("CLS");
			return;
		}
		else
			cout << "����������������";
	}


	abs->m_Size = 0;
	cout << "����ɹ�\n";
	system("pause");
	system("CLS");
}
int main()
{
	//����ͨѶ¼�ṹ�����
	Addressbooks abs;


	int input = 0;
	//�˵�����
	do {
		showMenu();
		cout << "��ѡ��:>";
		cin >> input;
		switch (input)
		{
		case �����ϵ��:
			addPerson(&abs);//��ַ����
			break;
		case ��ʾ��ϵ��:
			showPerson(&abs);
			break;
		case ɾ����ϵ��:
			delPerson(&abs);
			break;
		case ������ϵ��:
			searchPerson(&abs);
			break;
		case �޸���ϵ��:
			modifyPerson(&abs);
			break;
		case ������ϵ��:
			cleanPerson(&abs);
			break;
		case �˳���ϵ��:
			cout << "�˳�ͨѶ¼"<<endl;
			break;
		default:
			break;
		}
	} while(input);
	system("pause");
	return 0;
}

