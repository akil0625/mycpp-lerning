#include "WorkerManager.h"

//构造函数
WorkerManager::WorkerManager()
{
	//初始化属性
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		this->m_IsEmpty = true;
		return;
	}
	//文件为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		this->m_EmpNum = 0;
			this->m_EmpArray = NULL;
			ifs.close();
			this->m_IsEmpty = true;
			return;
	}
	//文件中有数据存在
	//统计职工人数
	this->m_EmpNum = this->get_EmpNum();
	//开辟空间
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//读取数据
	this->Init_Emp();
	ifs.close();

}

//析构函数
WorkerManager::~WorkerManager()
{
	int i = 0;
	if(this->m_EmpNum!=0)
	{
		for (i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}

//菜单系统
void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******  欢迎使用职工管理系统  ******" << endl;
	cout << "*********  1.增加职工信息  *********" << endl;
	cout << "*********  2.显示职工信息  *********" << endl;
	cout << "*********  3.删除离职职工  *********" << endl;
	cout << "*********  4.修改职工信息  *********" << endl;
	cout << "*********  5.查找职工信息  *********" << endl;
	cout << "*********  6.按照编号排序  *********" << endl;
	cout << "*********  7.清空所有文档  *********" << endl;
	cout << "*********  0.退出管理系统  *********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

//退出系统
void WorkerManager::ExitSystem()
{
	cout << "退出成功,欢迎下次使用" << endl;
	system("pause");
}

//添加职工
void WorkerManager::Add_Emp()
{
	int input = 0;
	cout << "请输入要添加的职工数量:" << endl;
	cin >> input;
	if (input > 0)
	{
		//添加
		//计算添加后新空间的大小
		int newSize = this->m_EmpNum + input;

		//开辟新空间
		Worker** newSpace = new Worker * [newSize];

		//将原来空间下的数据拷贝至新空间下
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
			//释放原有的空间
			delete[] this->m_EmpArray;
		}

		//更改新空间指向
		this->m_EmpArray = newSpace;

		
		//添加新数据
		for (int i = 0; i < input; i++)
		{
			int id;//员工编号
			string name;//员工姓名
			int dSelect;//部门选择

			cout << "请输入第" << i + 1 << "个员工编号:" << endl;
			while (true)
			{
				cin >> id;
				if (-1 == this->IsExist(id))
				{
					break;
				}
				cout << "已存在该Id员工，请重新输入" << endl;
			}


			cout << "请输入第" << i + 1 << "个员工姓名:" << endl;
			cin >> name;
			Worker* worker = NULL;

		again:
			cout << "请选择该职工岗位" << endl;
			cout << "1.普通员工" << endl;
			cout << "2.经理" << endl;
			cout << "3.老板" << endl;
			cin >> dSelect;


			switch (dSelect)
			{
			case 1:
				worker = new Employee(id, name,1);
				break;
			case 2:
				worker = new Manager(id, name,2);
				break;
			case 3:
				worker = new Boss(id, name,3);
				break;
			default:
				cout << "输入有误，请重新输入:" << endl;
				goto again;
				break;
			}
			newSpace[this->m_EmpNum] = worker;
					//更新职工人数
		this->m_EmpNum++;
		}
		this->save();
		this->m_IsEmpty = false;
		cout << "成功添加" << input << "名员工" << endl;
	}
	else
	{
		cout << "输入数据有误" << endl;
	}
	system("pause");
	system("cls");
}

//显示职工
void WorkerManager::Show_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	system("cls");
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		this->m_EmpArray[i]->showInfo();
	}
	system("pause");
	system("cls");
}

//保存数据
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//写文件

	//将每个人的数据写入至文件中
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptId << endl;
	}

}

//统计文件中人数
int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int did;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		//统计人数
		num++;
	}
	return num;
} 
//初始化读取
void WorkerManager::Init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	
	int id;
	string name;
	int did;
	int i = 0;
	while (ifs >> id && ifs >> name && ifs >> did)
	{
		Worker* worker = NULL;
		if (did == 1)
		{
			worker = new Employee(id, name, did);
		}
		else if (did == 2)
		{
			worker = new Manager(id, name, did);
		}
		else if (did == 3)
		{
			worker = new Boss(id, name, did);
		}
		this->m_EmpArray[i] = worker;
		i++;
	}

	ifs.close();
}

//删除职工
void WorkerManager::Del_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = -1;
	int input = 0;
	cout << "请问您要按照什么查找并删除该员工信息" << endl;
	cout << "1.Id号码  2.姓名" << endl;
	cin >> input;
	if (input == 1)
	{
	useiddel:
		cout << "请输入要删除的员工Id" << endl;
		cin >> input;
		index = this->IsExist(input);
	}
	else if (input == 2)
	{
		string name;
		cout << "请输入要删除的员工姓名" << endl;
		cin >> name;
		int num = 0;//记录此姓名人数
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				this->m_EmpArray[i]->showInfo();
				num++;
			}
		}
		if (num > 1)
		{
			cout << "以上是姓名为" << name << "的员工，请输入要删除的员工Id" << endl;
			while (true)
			{
				cin >> input;
				index = this->IsExist(input);
				if (index == -1)
				{
					cout << "您输入的员工Id不存在" << endl;
					continue;
				}
				if (this->m_EmpArray[index]->m_Name != name)
				{
					cout << "请在以上范围内输入员工Id" << endl;
					continue;
				}
				break;
			}
		}
		else
		{
			index = this->IsExist(name);
		}
	}
	else
	{
		cout << "输入有误，默认以Id号码查找" << endl;
		goto useiddel;
	}
	if (index == -1)
	{
		cout << "您要删除的员工信息不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		this->m_EmpArray[index]->showInfo();
		cout << "确定要删除该员工的信息吗?" << endl;
		cout << "1.确定  0.取消" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "取消删除" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (input != 1)
		{
			cout << "输入错误，取消删除" << endl;
			system("pause");
			system("cls");
			return;
		}
		delete this->m_EmpArray[index];
		for (; index < this->m_EmpNum - 1; index++)
		{
			this->m_EmpArray[index] = this->m_EmpArray[index + 1];
		}
		this->m_EmpNum--;
		this->save();
		cout << "删除成功" << endl;
		system("pause");
		system("cls");
	}
}

//判断该id员工是否存在，并返回所在位置
int WorkerManager::IsExist(int id)
{
	int i = 0;
	for (i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Id == id)
			return i;
	}
	return -1;
}

//判断该姓名员工是否存在，并返回所在位置
int WorkerManager::IsExist(string name)
{
	int i = 0;
	for (i = 0; i < this->m_EmpNum; i++)
	{
		if (this->m_EmpArray[i]->m_Name == name)
			return i;
	}
	return -1;
}

//修改员工信息
void WorkerManager::Modify_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = -1;
	int input = 0;
	cout << "请问您要按照什么查找并修改该员工信息" << endl;
	cout << "1.Id号码  2.姓名" << endl;
	cin >> input;
	if (input == 1)
	{
	useiddel:
		cout << "请输入要修改的员工Id" << endl;
		cin >> input;
		index = this->IsExist(input);
	}
	else if (input == 2)
	{
		string name;
		cout << "请输入要修改的员工姓名" << endl;
		cin >> name;
		int num = 0;//记录此姓名人数
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (name == this->m_EmpArray[i]->m_Name)
			{
				this->m_EmpArray[i]->showInfo();
				num++;
			}
		}
		if (num > 1)
		{
			cout << "以上是姓名为" << name << "的员工，请输入要修改的员工Id" << endl;
			while(true)
			{
				cin >> input;
				index = this->IsExist(input);
				if (index == -1)
				{
					cout << "您输入的员工Id不存在" << endl;
					continue;
				}
				if (this->m_EmpArray[index]->m_Name != name)
				{
					cout << "请在以上范围内输入员工Id" << endl;
					continue;
				}
				break;
			}
		}
		else
		{
			index = this->IsExist(name);
		}
	}
	else
	{
		cout << "输入有误，默认以Id号码查找" << endl;
		goto useiddel;
	}
	if (index == -1)
	{
		cout << "您要修改的员工信息不存在" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		this->m_EmpArray[index]->showInfo();
		cout << "确定要修改该员工的信息吗?" << endl;
		cout << "1.确定  0.取消" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "取消修改" << endl;
			system("pause");
			system("cls");
			return;
		}
		//删除原有信息
		delete this->m_EmpArray[index];

		//添加新信息
		int id;//员工编号
		string name;//员工姓名
		int dSelect;//部门选择

		cout << "请输入员工编号:" << endl;
		while (true)
		{
			cin >> id;
			if (-1 == this->IsExist(id))
			{
				break;
			}
			cout << "已存在该Id员工,请重新输入" << endl;
		}

		cout << "请输入员工姓名:" << endl;
		cin >> name;
		Worker* worker = NULL;

	again1:
		cout << "请选择该职工岗位" << endl;
		cout << "1.普通员工" << endl;
		cout << "2.经理" << endl;
		cout << "3.老板" << endl;
		cin >> dSelect;


		switch (dSelect)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			cout << "输入有误，请重新输入:" << endl;
			goto again1;
			break;
		}
		this->m_EmpArray[index] = worker;

		this->save();
		cout << "修改成功" << endl;
		system("pause");
		system("cls");
	}
}

//查找员工信息
void WorkerManager::Search_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	int input = 0;
	cout << "请问您要按照什么查找该员工信息"<<endl;
	cout << "1.Id号码  2.姓名" << endl;
	cin >> input;
	if (input == 1)
	{
	useid:
		cout << "请输入要查找的员工Id" << endl;
		cin >> input;
		int index = this->IsExist(input);

		if (index == -1)
		{
			cout << "您要查找的员工信息不存在" << endl;
			system("pause");
			system("cls");
			return;
		}

		this->m_EmpArray[index]->showInfo();
		system("pause");
		system("cls");
	}
	else if (input == 2)
	{
		string name;
		cout << "请输入要查找的员工姓名" << endl;
		cin >> name;
		int index = this->IsExist(name);

		if (index == -1)
		{
			cout << "您要查找的员工信息不存在" << endl;
			system("pause");
			system("cls");
			return;
		}

		this->m_EmpArray[index]->showInfo();
		system("pause");
		system("cls");
	}
	else
	{
		cout << "输入有误，默认以Id号码查找" << endl;
		goto useid;
	}
}

//排序员工信息
void WorkerManager::Sort_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i = 0;
	int j = 0;
	int times = 0;
	Worker* tmpworker = NULL;
	int input = 0;
	cout << "请问您以什么方式进行排序?" << endl;
	cout << "1.升序  2.降序" << endl;
	cin >> input;
	if (input == 2)
	{
		goto down;
	}
	//升序排序
	for (i = this->m_EmpNum;i>1;i--)
	{
		times = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (this->m_EmpArray[j]->m_Id > this->m_EmpArray[j + 1]->m_Id)
			{
				tmpworker = m_EmpArray[j];
				m_EmpArray[j] = m_EmpArray[j + 1];
				m_EmpArray[j + 1] = tmpworker;
				times++;
			}
		}
		if (times == 0)
		{
			cout << "排序成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	this->save();
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
	return;
	//降序排序
	down:
	for (i = this->m_EmpNum; i > 1; i--)
	{
		times = 0;
		for (j = 0; j < i - 1; j++)
		{
			if (this->m_EmpArray[j]->m_Id < this->m_EmpArray[j + 1]->m_Id)
			{
				tmpworker = m_EmpArray[j];
				m_EmpArray[j] = m_EmpArray[j + 1];
				m_EmpArray[j + 1] = tmpworker;
				times++;
			}
		}
		if (times == 0)
		{
			cout << "排序成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	this->save();
	cout << "排序成功" << endl;
	system("pause");
	system("cls");
	return;
}

//清空员工信息
void WorkerManager::Delall_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "无员工数据" << endl;
		system("pause");
		system("cls");
		return;
	}
	int input = 0;
	cout << "确定要删除所有员工的信息吗?" << endl;
	cout << "1.确定  0.取消" << endl;
	cin >> input;
	if (input == 0)
	{
		cout << "取消删除" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (input != 1)
	{
		cout << "输入错误，取消删除" << endl;
		system("pause");
		system("cls");
		return;
	}
	//释放空间
	int i = 0;
	if (this->m_EmpNum != 0)
	{
		for (i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
		}
		delete[] this->m_EmpArray;
		//解除绑定
		this->m_EmpArray = NULL;
		//数据总数为零
		this->m_EmpNum = 0;
	}
	//保存信息
	this->save();
	cout << "删除成功" << endl;
	system("pause");
	system("cls");
}
