#include "WorkerManager.h"

//���캯��
WorkerManager::WorkerManager()
{
	//��ʼ������
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open())
	{
		this->m_EmpNum = 0;
		this->m_EmpArray = NULL;
		ifs.close();
		this->m_IsEmpty = true;
		return;
	}
	//�ļ�Ϊ��
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
	//�ļ��������ݴ���
	//ͳ��ְ������
	this->m_EmpNum = this->get_EmpNum();
	//���ٿռ�
	this->m_EmpArray = new Worker * [this->m_EmpNum];
	//��ȡ����
	this->Init_Emp();
	ifs.close();

}

//��������
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

//�˵�ϵͳ
void WorkerManager::Show_Menu()
{
	cout << "************************************" << endl;
	cout << "******  ��ӭʹ��ְ������ϵͳ  ******" << endl;
	cout << "*********  1.����ְ����Ϣ  *********" << endl;
	cout << "*********  2.��ʾְ����Ϣ  *********" << endl;
	cout << "*********  3.ɾ����ְְ��  *********" << endl;
	cout << "*********  4.�޸�ְ����Ϣ  *********" << endl;
	cout << "*********  5.����ְ����Ϣ  *********" << endl;
	cout << "*********  6.���ձ������  *********" << endl;
	cout << "*********  7.��������ĵ�  *********" << endl;
	cout << "*********  0.�˳�����ϵͳ  *********" << endl;
	cout << "************************************" << endl;
	cout << endl;
}

//�˳�ϵͳ
void WorkerManager::ExitSystem()
{
	cout << "�˳��ɹ�,��ӭ�´�ʹ��" << endl;
	system("pause");
}

//���ְ��
void WorkerManager::Add_Emp()
{
	int input = 0;
	cout << "������Ҫ��ӵ�ְ������:" << endl;
	cin >> input;
	if (input > 0)
	{
		//���
		//������Ӻ��¿ռ�Ĵ�С
		int newSize = this->m_EmpNum + input;

		//�����¿ռ�
		Worker** newSpace = new Worker * [newSize];

		//��ԭ���ռ��µ����ݿ������¿ռ���
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				newSpace[i] = this->m_EmpArray[i];
			}
			//�ͷ�ԭ�еĿռ�
			delete[] this->m_EmpArray;
		}

		//�����¿ռ�ָ��
		this->m_EmpArray = newSpace;

		
		//���������
		for (int i = 0; i < input; i++)
		{
			int id;//Ա�����
			string name;//Ա������
			int dSelect;//����ѡ��

			cout << "�������" << i + 1 << "��Ա�����:" << endl;
			while (true)
			{
				cin >> id;
				if (-1 == this->IsExist(id))
				{
					break;
				}
				cout << "�Ѵ��ڸ�IdԱ��������������" << endl;
			}


			cout << "�������" << i + 1 << "��Ա������:" << endl;
			cin >> name;
			Worker* worker = NULL;

		again:
			cout << "��ѡ���ְ����λ" << endl;
			cout << "1.��ͨԱ��" << endl;
			cout << "2.����" << endl;
			cout << "3.�ϰ�" << endl;
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
				cout << "������������������:" << endl;
				goto again;
				break;
			}
			newSpace[this->m_EmpNum] = worker;
					//����ְ������
		this->m_EmpNum++;
		}
		this->save();
		this->m_IsEmpty = false;
		cout << "�ɹ����" << input << "��Ա��" << endl;
	}
	else
	{
		cout << "������������" << endl;
	}
	system("pause");
	system("cls");
}

//��ʾְ��
void WorkerManager::Show_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
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

//��������
void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME, ios::out);//д�ļ�

	//��ÿ���˵�����д�����ļ���
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->DeptId << endl;
	}

}

//ͳ���ļ�������
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
		//ͳ������
		num++;
	}
	return num;
} 
//��ʼ����ȡ
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

//ɾ��ְ��
void WorkerManager::Del_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = -1;
	int input = 0;
	cout << "������Ҫ����ʲô���Ҳ�ɾ����Ա����Ϣ" << endl;
	cout << "1.Id����  2.����" << endl;
	cin >> input;
	if (input == 1)
	{
	useiddel:
		cout << "������Ҫɾ����Ա��Id" << endl;
		cin >> input;
		index = this->IsExist(input);
	}
	else if (input == 2)
	{
		string name;
		cout << "������Ҫɾ����Ա������" << endl;
		cin >> name;
		int num = 0;//��¼����������
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
			cout << "����������Ϊ" << name << "��Ա����������Ҫɾ����Ա��Id" << endl;
			while (true)
			{
				cin >> input;
				index = this->IsExist(input);
				if (index == -1)
				{
					cout << "�������Ա��Id������" << endl;
					continue;
				}
				if (this->m_EmpArray[index]->m_Name != name)
				{
					cout << "�������Ϸ�Χ������Ա��Id" << endl;
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
		cout << "��������Ĭ����Id�������" << endl;
		goto useiddel;
	}
	if (index == -1)
	{
		cout << "��Ҫɾ����Ա����Ϣ������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		this->m_EmpArray[index]->showInfo();
		cout << "ȷ��Ҫɾ����Ա������Ϣ��?" << endl;
		cout << "1.ȷ��  0.ȡ��" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "ȡ��ɾ��" << endl;
			system("pause");
			system("cls");
			return;
		}
		if (input != 1)
		{
			cout << "�������ȡ��ɾ��" << endl;
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
		cout << "ɾ���ɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//�жϸ�idԱ���Ƿ���ڣ�����������λ��
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

//�жϸ�����Ա���Ƿ���ڣ�����������λ��
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

//�޸�Ա����Ϣ
void WorkerManager::Modify_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
		system("pause");
		system("cls");
		return;
	}
	int index = -1;
	int input = 0;
	cout << "������Ҫ����ʲô���Ҳ��޸ĸ�Ա����Ϣ" << endl;
	cout << "1.Id����  2.����" << endl;
	cin >> input;
	if (input == 1)
	{
	useiddel:
		cout << "������Ҫ�޸ĵ�Ա��Id" << endl;
		cin >> input;
		index = this->IsExist(input);
	}
	else if (input == 2)
	{
		string name;
		cout << "������Ҫ�޸ĵ�Ա������" << endl;
		cin >> name;
		int num = 0;//��¼����������
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
			cout << "����������Ϊ" << name << "��Ա����������Ҫ�޸ĵ�Ա��Id" << endl;
			while(true)
			{
				cin >> input;
				index = this->IsExist(input);
				if (index == -1)
				{
					cout << "�������Ա��Id������" << endl;
					continue;
				}
				if (this->m_EmpArray[index]->m_Name != name)
				{
					cout << "�������Ϸ�Χ������Ա��Id" << endl;
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
		cout << "��������Ĭ����Id�������" << endl;
		goto useiddel;
	}
	if (index == -1)
	{
		cout << "��Ҫ�޸ĵ�Ա����Ϣ������" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		this->m_EmpArray[index]->showInfo();
		cout << "ȷ��Ҫ�޸ĸ�Ա������Ϣ��?" << endl;
		cout << "1.ȷ��  0.ȡ��" << endl;
		cin >> input;
		if (input == 0)
		{
			cout << "ȡ���޸�" << endl;
			system("pause");
			system("cls");
			return;
		}
		//ɾ��ԭ����Ϣ
		delete this->m_EmpArray[index];

		//�������Ϣ
		int id;//Ա�����
		string name;//Ա������
		int dSelect;//����ѡ��

		cout << "������Ա�����:" << endl;
		while (true)
		{
			cin >> id;
			if (-1 == this->IsExist(id))
			{
				break;
			}
			cout << "�Ѵ��ڸ�IdԱ��,����������" << endl;
		}

		cout << "������Ա������:" << endl;
		cin >> name;
		Worker* worker = NULL;

	again1:
		cout << "��ѡ���ְ����λ" << endl;
		cout << "1.��ͨԱ��" << endl;
		cout << "2.����" << endl;
		cout << "3.�ϰ�" << endl;
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
			cout << "������������������:" << endl;
			goto again1;
			break;
		}
		this->m_EmpArray[index] = worker;

		this->save();
		cout << "�޸ĳɹ�" << endl;
		system("pause");
		system("cls");
	}
}

//����Ա����Ϣ
void WorkerManager::Search_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
		system("pause");
		system("cls");
		return;
	}
	int input = 0;
	cout << "������Ҫ����ʲô���Ҹ�Ա����Ϣ"<<endl;
	cout << "1.Id����  2.����" << endl;
	cin >> input;
	if (input == 1)
	{
	useid:
		cout << "������Ҫ���ҵ�Ա��Id" << endl;
		cin >> input;
		int index = this->IsExist(input);

		if (index == -1)
		{
			cout << "��Ҫ���ҵ�Ա����Ϣ������" << endl;
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
		cout << "������Ҫ���ҵ�Ա������" << endl;
		cin >> name;
		int index = this->IsExist(name);

		if (index == -1)
		{
			cout << "��Ҫ���ҵ�Ա����Ϣ������" << endl;
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
		cout << "��������Ĭ����Id�������" << endl;
		goto useid;
	}
}

//����Ա����Ϣ
void WorkerManager::Sort_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
		system("pause");
		system("cls");
		return;
	}
	int i = 0;
	int j = 0;
	int times = 0;
	Worker* tmpworker = NULL;
	int input = 0;
	cout << "��������ʲô��ʽ��������?" << endl;
	cout << "1.����  2.����" << endl;
	cin >> input;
	if (input == 2)
	{
		goto down;
	}
	//��������
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
			cout << "����ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	this->save();
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
	return;
	//��������
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
			cout << "����ɹ�" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
	this->save();
	cout << "����ɹ�" << endl;
	system("pause");
	system("cls");
	return;
}

//���Ա����Ϣ
void WorkerManager::Delall_Emp()
{
	if (this->m_EmpNum == 0)
	{
		system("cls");
		cout << "��Ա������" << endl;
		system("pause");
		system("cls");
		return;
	}
	int input = 0;
	cout << "ȷ��Ҫɾ������Ա������Ϣ��?" << endl;
	cout << "1.ȷ��  0.ȡ��" << endl;
	cin >> input;
	if (input == 0)
	{
		cout << "ȡ��ɾ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	if (input != 1)
	{
		cout << "�������ȡ��ɾ��" << endl;
		system("pause");
		system("cls");
		return;
	}
	//�ͷſռ�
	int i = 0;
	if (this->m_EmpNum != 0)
	{
		for (i = 0; i < this->m_EmpNum; i++)
		{
			delete this->m_EmpArray[i];
		}
		delete[] this->m_EmpArray;
		//�����
		this->m_EmpArray = NULL;
		//��������Ϊ��
		this->m_EmpNum = 0;
	}
	//������Ϣ
	this->save();
	cout << "ɾ���ɹ�" << endl;
	system("pause");
	system("cls");
}
