#pragma once//防止头文件重复包含
#include <iostream>//包含输入输入输出流头文件
#include <string> 
#include "Worker.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;
//管理系统类
class WorkerManager
{
public:
	//构造函数
	WorkerManager();

	//展示菜单
	void Show_Menu();

	//退出系统
	void ExitSystem();

	//记录职工人数
	int m_EmpNum;

	//职工数组指针
	Worker** m_EmpArray;

	//添加职工
	void Add_Emp();

	//保存数据
	void save();

	//判断文件是否为空
	bool m_IsEmpty;

	//统计文件中人数
	int get_EmpNum();

	//删除职工
	void Del_Emp();

	//判断该id员工是否存在，并返回所在位置
	int IsExist(int id);

	//判断该姓名员工是否存在，并返回所在位置
	int IsExist(string name);

	//修改员工信息
	void Modify_Emp();

	//查找员工信息
	void Search_Emp();

	//排序员工信息
	void Sort_Emp();

	//清空员工信息
	void Delall_Emp();

	//初始化员工
	void Init_Emp();

	//显示职工
	void Show_Emp();

	//析构函数
	~WorkerManager();

};



