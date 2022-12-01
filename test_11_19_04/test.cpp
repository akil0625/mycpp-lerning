#include <iostream>
using namespace std;
#include "WorkerManager.h"

#include "Worker.h"
#include "Employee.h"
#include "Manager.h"
#include "Boss.h"



enum
{
	quit,
	add,
	show,
	del,
	modify,
	search,
	sort,
	delall
};


int main()
{
	WorkerManager wm;
	int input;
	do
	{
		//调用展示菜单成员函数
		wm.Show_Menu();

		cout << "请选择:>";
		cin >> input;

		switch (input)
		{
		case add:
			wm.Add_Emp();
			break;
		case show:
			wm.Show_Emp();
			break;
		case del:
			wm.Del_Emp();
			break;
		case modify:
			wm.Modify_Emp();
			break;
		case search:
			wm.Search_Emp();
			break;
		case sort:
			wm.Sort_Emp();
			break;
		case delall:
			wm.Delall_Emp();
			break;
		case quit:
			wm.ExitSystem();
			break;
		default:
			system("cls");
			break;
		}
	} while (input);
	return 0;
}