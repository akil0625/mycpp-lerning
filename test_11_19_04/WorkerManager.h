#pragma once//��ֹͷ�ļ��ظ�����
#include <iostream>//�����������������ͷ�ļ�
#include <string> 
#include "Worker.h"
#include "Boss.h"
#include "Employee.h"
#include "Manager.h"
#include <fstream>
#define FILENAME "empFile.txt"

using namespace std;
//����ϵͳ��
class WorkerManager
{
public:
	//���캯��
	WorkerManager();

	//չʾ�˵�
	void Show_Menu();

	//�˳�ϵͳ
	void ExitSystem();

	//��¼ְ������
	int m_EmpNum;

	//ְ������ָ��
	Worker** m_EmpArray;

	//���ְ��
	void Add_Emp();

	//��������
	void save();

	//�ж��ļ��Ƿ�Ϊ��
	bool m_IsEmpty;

	//ͳ���ļ�������
	int get_EmpNum();

	//ɾ��ְ��
	void Del_Emp();

	//�жϸ�idԱ���Ƿ���ڣ�����������λ��
	int IsExist(int id);

	//�жϸ�����Ա���Ƿ���ڣ�����������λ��
	int IsExist(string name);

	//�޸�Ա����Ϣ
	void Modify_Emp();

	//����Ա����Ϣ
	void Search_Emp();

	//����Ա����Ϣ
	void Sort_Emp();

	//���Ա����Ϣ
	void Delall_Emp();

	//��ʼ��Ա��
	void Init_Emp();

	//��ʾְ��
	void Show_Emp();

	//��������
	~WorkerManager();

};



