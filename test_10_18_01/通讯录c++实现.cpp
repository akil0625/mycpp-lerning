#include <iostream>
using namespace std;
#include <string>
#define MAX 1000

//设计联系人结构体
struct Person
{
	string m_Name;
	int m_Sex = 0;
	int m_Age = 0;
	string m_Tele;
	string m_Addr;
};

//设计通讯录结构体
struct Addressbooks
{
	struct Person personArray[MAX];
	int m_Size = 0;
};

//菜单界面
void showMenu()
{
	cout << "******* 1.添加联系人 *******" << endl;
	cout << "******* 2.显示联系人 *******" << endl;
	cout << "******* 3.删除联系人 *******" << endl;
	cout << "******* 4.查找联系人 *******" << endl;
	cout << "******* 5.修改联系人 *******" << endl;
	cout << "******* 6.清零联系人 *******" << endl;
	cout << "******* 0.退出通讯录 *******" << endl;
}


enum
{
	退出联系人,
	添加联系人,
	显示联系人,
	删除联系人,
	查找联系人,
	修改联系人,
	清零联系人
};
//查找联系人
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

//1.添加联系人
void addPerson(Addressbooks* abs)
{
	if(abs->m_Size==MAX)
	{
		cout << "通讯录已满" << endl;
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入联系人姓名>:";
		cin >> name;
		abs->personArray[abs->m_Size].m_Name = name;
		//输入性别
		int sex = 0;
		cout << "*** 1---男  2---女 ***\n";
		cout << "请输入性别:>";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[abs->m_Size].m_Sex = sex;
				break;
			}
			cout << "输入有误请重新输入\n";
		}
		//输入年龄
		int age = 0;
		cout << "请输入年龄:>";
		while (true)
		{
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[abs->m_Size].m_Age = age;
				break;
			}
			cout << "输入有误请重新输入\n";
		}
		//输入手机号
		string tele;
		cout << "请输入手机号:>";
		cin >> tele;
		abs->personArray[abs->m_Size].m_Tele = tele;
		//住址
		string addr;
		cout << "请输入住址:>";
		cin >> addr;
		abs->personArray[abs->m_Size].m_Addr = addr;
		abs->m_Size++;
		cout << "添加成功\n";
	}
	system("pause");
	system("CLS");
}
//显示联系人
void showPerson(const Addressbooks* abs)
{
	if (abs->m_Size == 0)
	{
		cout << "通讯录为空\n";
	}
	else
	{
		for (int i = 0; i < abs->m_Size; i++)
		{
			cout << "姓名: " << abs->personArray[i].m_Name << "\t";
			cout << "性别: " << ( abs->personArray[i].m_Sex == 1? "男":"女" )<< "\t";
			cout << "年龄: " << abs->personArray[i].m_Age << "\t";
			cout << "电话: " << abs->personArray[i].m_Tele << "\t";
			cout << "住址: " << abs->personArray[i].m_Addr << endl;
		}
	}
	system("pause");
	system("CLS");
}
//删除联系人
void delPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入要删除人的姓名:>";
	cin >> name;
	int site = 0;
	site = findbyname(abs, name);
	if(site ==-1)
	{
		cout << "未找到该联系人\n";
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
	cout << "删除成功\n";
	system("pause");
	system("CLS");
}
//查找联系人
void searchPerson(const Addressbooks* abs)
{
	string name;
	cout << "请输入要查找的联系人:>";
	cin >> name;
	int site = findbyname(abs, name);
	if (site == -1)
	{
		cout << "未找到该联系人\n";
		system("pause");
		system("CLS");
		return;
	}
	else
	{
		cout << "姓名: " << abs->personArray[site].m_Name << "\t";
		cout << "性别: " << (abs->personArray[site].m_Sex == 1 ? "男" : "女") << "\t";
		cout << "年龄: " << abs->personArray[site].m_Age << "\t";
		cout << "电话: " << abs->personArray[site].m_Tele << "\t";
		cout << "住址: " << abs->personArray[site].m_Addr << endl;
	}
	system("pause");
	system("CLS");
}
//修改联系人
void modifyPerson(Addressbooks* abs)
{
	string name;
	cout << "请输入要查找的联系人:>";
	cin >> name;
	int site = findbyname(abs, name);
	if (site == -1)
	{
		cout << "未找到该联系人\n";
		system("pause");
		system("CLS");
		return;
	}
	else
	{
		//输入姓名
		string name;
		cout << "请输入联系人姓名>:";
		cin >> name;
		abs->personArray[site].m_Name = name;
		//输入性别
		int sex = 0;
		cout << "*** 1---男  2---女 ***\n";
		cout << "请输入性别:>";
		while (true)
		{
			cin >> sex;
			if (sex == 1 || sex == 2)
			{
				abs->personArray[site].m_Sex = sex;
				break;
			}
			cout << "输入有误请重新输入\n";
		}
		//输入年龄
		int age = 0;
		cout << "请输入年龄:>";
		while (true)
		{
			cin >> age;
			if (age > 0 && age <= 150)
			{
				abs->personArray[site].m_Age = age;
				break;
			}
			cout << "输入有误请重新输入\n";
		}
		//输入手机号
		string tele;
		cout << "请输入手机号:>";
		cin >> tele;
		abs->personArray[site].m_Tele = tele;
		//住址
		string addr;
		cout << "请输入住址:>";
		cin >> addr;
		abs->personArray[site].m_Addr = addr;
	}
	cout << "修改成功\n";
	system("pause");
	system("CLS");
}
//清除联系人
void cleanPerson(Addressbooks* abs)
{
	cout << "是否确定清空?\n";
	cout << "*** 1.确定 2.取消 ***\n";
	int i = 0;
	while(1)
	{ 
		cin >> i;
		if (i == 1)
			break;
		else if (i == 2)
		{
			cout << "取消清空\n";
			system("pause");
			system("CLS");
			return;
		}
		else
			cout << "输入有误重新输入";
	}


	abs->m_Size = 0;
	cout << "清除成功\n";
	system("pause");
	system("CLS");
}
int main()
{
	//创建通讯录结构体变量
	Addressbooks abs;


	int input = 0;
	//菜单调用
	do {
		showMenu();
		cout << "请选择:>";
		cin >> input;
		switch (input)
		{
		case 添加联系人:
			addPerson(&abs);//传址调用
			break;
		case 显示联系人:
			showPerson(&abs);
			break;
		case 删除联系人:
			delPerson(&abs);
			break;
		case 查找联系人:
			searchPerson(&abs);
			break;
		case 修改联系人:
			modifyPerson(&abs);
			break;
		case 清零联系人:
			cleanPerson(&abs);
			break;
		case 退出联系人:
			cout << "退出通讯录"<<endl;
			break;
		default:
			break;
		}
	} while(input);
	system("pause");
	return 0;
}

