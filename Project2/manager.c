#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include "manager.h"

MANAGERACOUNT *manager_h;
char username[20] = { 0 };

enum {
	exitwithoutsaveing,
	showallinformation,
	addcourse,
	addstudent,
	addstudenttocourse,
	modifyscore,
	deleteinfo,
	saveinfo,
	modifymanager,
	changepassword
};

enum {
	cancle,
	showstudents,
	showcourses,
	showtogerther,
	readytoinputid,
};
enum {
	deletestudent = 4,
	delatecouse,
	delatestudfromcours
};

void menu1()
{
	printf("==========================================================================\n");
	printf("========================  1.showallinformation   =========================\n");
	printf("========================  2.addcourse            =========================\n");
	printf("========================  3.addstudent           =========================\n");
	printf("========================  4.addstudenttocourse   =========================\n");
	printf("========================  5.modifyscore          =========================\n");
	printf("========================  6.deleteinfo           =========================\n");
	printf("========================  7.saveinfo             =========================\n");
	printf("========================  8.modifymanager           =========================\n");
	printf("========================  9.changepassword       =========================\n");
	printf("========================  0.exitwithoutsaveing   =========================\n");
	printf("==========================================================================\n");
	printf(">");

}			
			
void menu2()
{			
	printf("==========================================================================\n");
	printf("========================  1.showstudents         =========================\n");
	printf("========================  2.showcourses          =========================\n");
	printf("========================  3.showtogerther        =========================\n");
	printf("========================  4.readytoinputid       =========================\n");
	printf("========================  0.cancle               =========================\n");
	printf("==========================================================================\n");
	printf(">");
}			
			
void menu3()
{			
	printf("==========================================================================\n");
	printf("========================  1.showstudents         =========================\n");
	printf("========================  2.showcourses          =========================\n");
	printf("========================  3.showtogerther        =========================\n");
	printf("========================  4.deletestudent        =========================\n");
	printf("========================  5.delatecouse          =========================\n");
	printf("========================  6.delatestud from      =========================\n");
	printf("========================        cours            =========================\n");
	printf("========================  0.cancle               =========================\n");
	printf("==========================================================================\n");
	printf(">");

}


void ShowInformation()
{
	//setvbuf(stdout, NULL, _IOFBF, 4096);
	system("cls");
	int sbegin = 1;//�ӵ�sbegin��ѧ����ʾ����sbegin+9��ѧ��//���Ҫ��1��ʼ
	int cbegin = 1;//�ӵ�cbegin���γ���ʾ����cbegin+6���γ�//���Ҫ��1��ʼ
	int input = 0;
	int leftline = 0;
	do
	{
		g_PrintStCr(stcr, sbegin, cbegin);
		leftline = stcr->stu_num - sbegin - 10 + 1 < 0 ? 10 - (stcr->stu_num - sbegin) : 1;
		for (int i = 0; i < leftline*2; i++)
			printf("\n");
		printf("A������  D������  W������  S�����ƶ� 0���˳�");
		//fflush(stdout);
		input = (int)_getch();
		switch (input)
		{
		case 'A':
		case 'a':
			if (cbegin != 1)
				cbegin -= 1;
			break;
		case 'D':
		case 'd':
			if(stcr->co_num - cbegin - 7 + 1 >= 0)
				cbegin += 1;
			break;
		case 'W':
		case 'w':
			if(stcr->stu_num - sbegin - 10 + 1 >= 0)
				sbegin += 1;
			break;
		case 'S':
		case 's':
			if (sbegin != 1)
				sbegin -= 1;
			break;
		case '0':
			input = 0;
			break;
		default:
			break;
		}
		system("cls");
	} while (input);
	//setvbuf(stdout, NULL, _IONBF, 0);
}
void AddStu()
{
	g_AddStudent(stcr);
	printf("��ӳɹ�\n");
	//system("pause");
	system("cls");
}
void AddCo()
{
	g_AddCourse(stcr);
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}
void showstu()
{
	system("cls");
	STUDENTS* p = stcr->g_students->next;

	printf("---------------------------------------------\n");
	printf("%14s   |%8s   |%12s  |\n", "����", "ѧ��", "�ֻ���");
	while (p != NULL)
	{
		printf("%14s   |%8d   |%12s  |\n", p->student.student_name, p->student.student_number, p->student.student_phone);
		p = p->next;
	}
	printf("---------------------------------------------\n\n");

}
void showco(int together)
{
	if(!together)
		system("cls");
	COURSES* q = stcr->g_courses->next;

	printf("---------------------------------------------------------------------------\n");
	printf("%14s   |%8s   |%12s  |%12s  |%12s  |\n", "�γ���", "�γ�id","����","�γ�ѧ��","�γ��ܷ�");
	while (q != NULL)
	{
		printf("%14s   |%8d   |%12d  |%12d  |%12d  |\n", q->course.course_name, q->course.course_number,q->course.course_jidian,q->course.couese_credit,q->course.course_score);
		q = q->next;
	}
	printf("---------------------------------------------------------------------------\n\n");

}
void addsc()
{
	int studentid = 0;
	int courseid = 0;
	int score = 0;
	int tmp = 0;
	printf("������ѡȡ��ѧ��id\n");
	tmp = scanf("%d", &studentid);
	printf("������ѡȡ�Ŀγ�id\n");
	tmp = scanf("%d", &courseid);
	printf("������ɼ�,����-2��ʾ���޳ɼ�\n");
	tmp = scanf("%d", &score);
	AddScore(stcr, studentid, courseid, score);
	printf("��ӳɹ�\n");
	//system("pause");
	system("cls");
}
void AddStutoCo()
{
	system("cls");
	int input = 0;
	int tmp = 0;
	do
	{
		menu2();
		tmp = scanf("%d", &input);
		switch (input)
		{
		case showstudents:
			showstu();
			break;
		case showcourses:
			showco(0);
			break;
		case showtogerther:
			showstu();
			showco(1);
			break;
		case readytoinputid:
			addsc();
			break;
		case cancle:
			break;
		}

	} while (input);
	system("cls");

}
void modstuco()
{
	int tmp = 0;
	int courseid = 0;
	int studentid = 0;
	int score = 0;
	printf("������ѡȡ��ѧ��id\n");
	tmp = scanf("%d", &studentid);
	printf("������ѡȡ�Ŀγ�id\n");
	tmp = scanf("%d", &courseid);
	printf("�������޸ĺ�ĳɼ�\n");
	tmp = scanf("%d", &score);
	ModifyScore(stcr->g_head, studentid, courseid, score);
	printf("�޸ĳɹ�\n");
	system("pause");
	system("cls");
}
void ModStuCo()
{
	system("cls");
	int input = 0;
	int tmp = 0;
	do
	{
		menu2();
		tmp = scanf("%d", &input);
		switch (input)
		{
		case showstudents:
			showstu();
			break;
		case showcourses:
			showco(0);
			break;
		case showtogerther:
			showstu();
			showco(1);
			break;
		case readytoinputid:
			modstuco();
			break;
		case cancle:
			break;
		}

	} while (input);
	system("cls");
}
void delstu()
{
	int tmp = 0;
	int studentid = 0;
	printf("������Ҫɾ����ѧ��id\n");
	tmp = scanf("%d", &studentid);
	g_DeleteStudent(stcr, studentid);
	printf("ɾ���ɹ�\n");
	system("pause");
	system("cls");
}
void delco()
{
	int tmp = 0;
	int courseid = 0;
	printf("������Ҫɾ���Ŀγ�id\n");
	tmp = scanf("%d", &courseid);
	g_DeleteCourse(stcr, courseid);
	printf("ɾ���ɹ�\n");
	system("pause");
	system("cls");
}
void delstuco()
{
	int tmp = 0;
	int studentid = 0;
	int courseid = 0;
	printf("������Ҫɾ����ѧ��id\n");
	tmp = scanf("%d", &studentid);
	printf("������Ҫɾ���Ŀγ�id\n");
	tmp = scanf("%d", &courseid);
	DeleteScore(stcr->g_head, studentid, courseid);
	printf("ɾ���ɹ�\n");
	system("pause");
	system("cls");
}
void DelStuCo()
{
	system("cls");
	int input = 0;
	int tmp = 0;
	do
	{
		menu3();
		tmp = scanf("%d", &input);
		switch (input)
		{
		case showstudents:
			showstu();
			break;
		case showcourses:
			showco(0);
			break;
		case showtogerther:
			showstu();
			showco(1);
			break;
		case deletestudent:
			delstu();
			break;
		case delatecouse:
			delco();
			break;
		case delatestudfromcours:
			delstuco();
			break;
		}
	} while (input);
	system("cls");
}
void SaveFile()
{
	SaveToFile(stcr);
	printf("����ɹ�\n");
	system("pause");
	system("cls");
}


void initmanager()
{
	int tmp = 0;
	manager_h = (MANAGERACOUNT*)malloc(sizeof(MANAGERACOUNT));//Ϊ�˻��鿪�ٿռ�
	if (manager_h == NULL)//�����Ƿ񿪱ٳɹ�
	{
		printf("���ٿռ�ʧ��\n");
		return;
	}
	MANAGERACOUNT *p = manager_h;//����ָ��p�����˺Ŷ�ȡ
	manager_h->next = NULL;
	FILE*file;
	file = fopen("mana.dat", "r");
	char strLine[1024] = { 0 };//������ȡһ��
	char readedstr[20] = { 0 };//������ȡһ�����ַ���
	while (!feof(file))
	{
		fgets(strLine, 1024, file);//��ȡһ��
		sscanf(strLine, "%s", readedstr); //��ȡһ�����ַ���
		if (0 == strcmp("info", readedstr))//���Ƚ�
		{
			p->next = (MANAGERACOUNT*)malloc(sizeof(MANAGERACOUNT));
			if (manager_h == NULL)
			{
				printf("���ٿռ�ʧ��\n");
				return;
			}
			p = p->next;
			tmp = sscanf(strLine, "%s%s%s%d", readedstr, p->username, p->password, &(p->issuperpowerd));
			p->next = NULL;
		}
		else
			break;
	}
	if (manager_h != NULL)
	{
		p = manager_h;
		manager_h = manager_h->next;
		free(p);
	}
	fclose(file);
}

int checkuser(char username[20], char password[20])
{
	MANAGERACOUNT *p = manager_h;
	while (p != NULL)
	{
		if (0 == strcmp(username, p->username) && 0 == strcmp(password, p->password))
		{
			return 0;
		}
		else if (0 == strcmp(username, p->username))
		{
			return 2;//��ʾ���벻��ȷ
		}
		p = p->next;
	}
	return 1;//��ʾδ�ҵ����˻�
}

enum
{
	addmanager = 1,
	deletemanager,
	showmanager
};
managerMenu()
{
	printf("==========================================================================\n");
	printf("========================  1.addmanager         =========================\n");
	printf("========================  2.deletemanager          =========================\n");
	printf("========================  3.showmanager        =========================\n");
	printf("========================  0.cancle               =========================\n");
	printf("==========================================================================\n");
}
void saveManager()
{
	FILE*file;
	file = fopen("mana.dat", "w");
	if (file == NULL)
	{
		printf("����ʧ��\n");
		return;
	}
	MANAGERACOUNT*p = manager_h;
	while (p != NULL)
	{
		fprintf(file,"info %s %s %d\n", p->username, p->password, p->issuperpowerd);
		p = p->next;
	}
	fprintf(file,"eof");
}

void addManager()
{
	char username[20] = { 0 };
	char password[20] = { 0 };
	int input = 0;
	do
	{
		system("cls");
		printf("������Ҫ��ӵ��˻���:\n");
		scanf("%s", username);
		input = checkuser(username, "@@@");
		if (input != 1)
			printf("���û��Ѵ���!\n");
		if (strlen(username) < 4)
			printf("�û�����С����Ϊ4\n");
		if (input != 1 || strlen(username) < 4)
			system("pause");
	} while (input!=1);//һֱ�����˻�����ֱ���ҵ�û��ʹ�ù����˺�
	do
	{
		system("cls");
		printf("������������:\n");
		scanf("%s", password);
		if (strlen(password) < 8)
			printf("���볤�Ȳ���С��8\n");
		if (0==strcmp("@@@", password))
			printf("�벻Ҫ����3��@������\n");
		if(strlen(password) < 8|| 0 == strcmp("@@@", password))
			system("pause");
	} while (0==strcmp("@@@", password)|| strlen(password) < 8);
	MANAGERACOUNT*tmp = (MANAGERACOUNT*)malloc(sizeof(MANAGERACOUNT));
	if (tmp == NULL)
	{
		printf("�ռ俪��ʧ��\n");
		return;
	}
	tmp->next = manager_h->next;
	manager_h->next = tmp;
	for (int i = 0; i < 20; i++)
	{
		tmp->username[i] = username[i];
		tmp->password[i] = password[i];
	}
	printf("�Ƿ�����������ԱȨ��?������yes/no\n");
	scanf("%s", username);
	if (strcmp(username, "yes") == 0)
		tmp->issuperpowerd = 1;
	else
		tmp->issuperpowerd = 0;
	saveManager();
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}
void showManager()
{
	MANAGERACOUNT*p = manager_h;
	while (p != NULL)
	{
		printf("%s\n", p->username);
		p = p->next;
	}
}
void deleteManager()
{
	char targetname[20] = { 0 };
	do
	{
		system("cls");
		showManager();
		printf("\n��������Ҫɾ�����û���,����quit�˳�\n");
		scanf("%s", targetname);
		if (0 == strcmp("root", targetname))
		{
			printf("������ɾ��root�û�\n");
			system("pause");
			continue;
		}
		if (0 == strcmp(targetname, "quit"))
			break;
		if (checkuser(targetname, "@@@") != 1)
		{
			MANAGERACOUNT*p = manager_h;
			if (manager_h != NULL && !strcmp(manager_h->username, targetname))
			{
				p = manager_h;
				manager_h = manager_h->next;
				free(p); 
				continue;
			}
			else
			{
				while (p->next != NULL)
				{
					if (0==strcmp(p->next->username, targetname))
					{
						MANAGERACOUNT*tmp = p->next;
						p->next = p->next->next;
						free(tmp);
						break;
					}
					p = p->next;
				}
			}
			
		}
	} while (1);
	saveManager();
	printf("��ӳɹ�\n");
	system("pause");
	system("cls");
}
void modifyManager()
{
	
	int input = 0;
	do
	{
		system("cls");
		managerMenu();
		scanf("%d", &input);
		switch (input)
		{
		case addmanager:
			addManager();
			break;
		case deletemanager:
			deleteManager();
			break;
		case showmanager:
			showManager();
			system("pause");
			break;
		case cancle:
			break;
		default:
			printf("����ԱҲ��Ƥ��\n");
			system("pause");
			break;
		}

	} while (input);

	//modifaymedu();
}

int managerlogin()
{
	initmanager();
	int input = 0;
	char password[20] = { 0 };
	do
	{
		printf("�������û���:>\n");
		scanf("%s", username);
		printf("�������û�����:>\n");
		scanf("%s", password);
		input = checkuser(username, password);
		if (input == 2)
			printf("�������벻��ȷ\n");
		else if (input == 1)
			printf("�����ڴ��˺�\n");
		else
			printf("��¼�ɹ�\n");
		system("pause");
		system("cls");

	} while (input);

	do
	{
		menu1();
		int tmp = scanf("%d", &input);
		switch (input)
		{
		case showallinformation:
			ShowInformation();
			break;
		case addcourse:
			AddCo();
			break;
		case addstudent:
			AddStu();
			break;
		case addstudenttocourse:
			AddStutoCo();
			break;
		case modifyscore:
			ModStuCo();
			break;
		case deleteinfo:
			DelStuCo();
			break;
		case saveinfo:
			SaveFile();
			break;
		case exitwithoutsaveing:
			break;
		case modifymanager:
			modifyManager();
			break;
		case 	changepassword:
			break;
		default:
			printf("�ٺ٣�����Ὺ��Ц\n");
			system("pause");
		}
		system("cls");
	} while (input);
}