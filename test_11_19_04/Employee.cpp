#include "Employee.h"


//���캯��
Employee::Employee(int id,string name ,int did)
{
	this->m_Id = id;
	this->m_Name = name;
	this->DeptId = did;
}

//��ʾ������Ϣ
void Employee::showInfo()
{
	cout << "ְ�����:" << this->m_Id
		<< "\tְ������:" << this->m_Name
		<< "\t��λ:" << this->getDeptName()
		<< "\t��λְ��:��ɾ�����������" << endl;
}

//��ȡ��λ����
string Employee::getDeptName()
{
	return string("Ա��");
}