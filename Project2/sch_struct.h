#pragma once




//ѧԺ��Ϣ
struct ACADEMY;
typedef struct ACADEMY ACADEMY;

//��ʦ��Ϣ
struct TEACHER;
typedef struct TEACHER TEACHER;

//ID����
struct ID;
typedef struct ID ID;

//�༶��Ϣ
struct studentCLASS;
typedef struct studentCLASS studentCLASS;

//�༶����
struct CLASSLINK;
typedef struct CLASSLINK CLASSLINK;

//��Ŀ����
struct item_link;
typedef struct item_link item_link;

//��������
struct thesis_link;
typedef struct thesis_link thesis_link;

//������
struct prize_link;
typedef struct prize_link prize_link;

//ѧ����Ϣ����
struct STUDENTS;
typedef struct STUDENTS STUDENTS;

//�γ���Ϣ����
struct COURSES;
typedef struct COURSES COURSES;



//ID����
struct ID
{
	int id;										//ѧ��id
	struct id* next;
};



//ѧԺ��Ϣ
struct ACADEMY
{
	int acadmy_number;						//ѧԺ��
	char acadmy_name[20];					//ѧԺ��
	ID* teacher_head;
	ID* class_head;
};

//��ʦ��Ϣ
struct TEACHER
{
	int teacher_number[6];						//��ʦ�Ľ�ʦ��
	int teacher_year;							//��ʦ����
	char teacher_name[20];						//��ʦ����
	int teacher_phone[11];						//��ʦ�绰
};


//�༶��Ϣ
struct studentCLASS
{
	int class_number;							//�༶��
	ID* students_head;
};
//�༶����
struct CLASSLINK
{
	studentCLASS class1;
	struct CLASSLIKE* next;
};

//��Ŀ����
struct item_link
{
	int item_number;
	char itme_name[20];           //ѧ���μӵ���Ŀ����
	int itme_number[4];           //ѧ���μӵ���Ŀ���
	int itme_begin[3];            //ѧ���μӵ���Ŀ������ʱ��
	int  itme_end[3];             //ѧ���μӵ���Ŀ�Ľ���ʱ��

	struct studentite_link* next;
};

//��������
struct thesis_link
{
	int thesis_number;
	char thesis_name[20];				//���ĵ�����
	char thesis_periodical[20];			//���ķ�����ڿ�
	int thesis_pubish[3];				//���ķ����ʱ�� �� �� ��
	int thesis_grade;					//���ļ���
	struct thesis_link* next;
};

//������
struct prize_link
{
	int prize_number;
	char prize_name[20];          //����Ŀ
	char prize_auspice[20];       //�����췽
	int  prize_grade;             //�񽱵ȼ���У�����м���ʡ�������������缶
	int prize_time[3];            //��ʱ�� �꣬�£���
	struct prize_link* next;
};





