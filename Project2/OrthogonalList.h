#pragma once

#include <stdio.h>
#include <malloc.h>
#include "sch_struct.h"

//======================================== һϵ�нṹ������ ======================================================

//ѧ����Ϣ
struct STUDENT;
typedef struct STUDENT STUDENT;
//�γ���Ϣ
struct COURSE;
typedef struct COURSE COURSE;
struct O_courses;
struct O_students;
struct OrthogonalList;

//======================================== һϵ�нṹ�嶨�� ======================================================

//ѧ����Ϣ
struct STUDENT
{
	int student_number;           //ѧ��
	char student_name[20];        //ѧ������
	char student_phone[12];        //ѧ���绰
	ID* item_head;
	ID* thesis_head;
	ID* prize_head;
};

//�γ���Ϣ
struct COURSE
{
	int course_number;								    //�γ����
	char course_name[20];								//�γ�����
	int couese_credit;									//�γ�ѧ��
	int course_jidian;									//�γ��ܼ���
	int course_score;									//�ÿγ��ܷ���
};

//ѧ��������Ϣ
struct STUDENTS
{
	STUDENT student;
	struct STUDENTS* next;
};

//�γ�������Ϣ
struct COURSES
{
	COURSE course;
	struct COURSES* next;
};

//ѧ��ID��score����
struct O_students {
	int studentid;
	int score;
	struct O_students* next;
};

//�γ�ID��score����
struct O_courses {
	int courseid;
	int score;
	struct O_courses* next;
};

//ʮ�������洢ѧ���Ϳγ̵Ĺ�ϵ
struct OrthogonalList {//����ṹ��
	int studentid, courseid;
	int score;
	struct OrthogonalList* right;
	struct OrthogonalList* down;
};

//ʮ�������洢ѧ���Ϳγ̵Ĺ�ϵ��������ϸ��ѧ���Ϳγ���Ϣ
struct St_Crs {
	int stu_num;
	int co_num;
	STUDENTS* g_students;
	COURSES* g_courses;
	struct OrthogonalList* g_head;
};
//======================================== �ⲿ��������   ========================================================
extern struct St_Crs* stcr;


//======================================== һϵ�к������� ========================================================

 
//��ʼ��
struct St_Crs* g_initStCr();
 
//���ܵ�ʮ��������ӿγ�
void g_AddCourse(struct St_Crs* stcr);

//���ܵ�ʮ���������ѧ��
void g_AddStudent(struct St_Crs* stcr);

//����ʮ������
struct OrthogonalList* CreateOrthogonalList(int* studentid, int* courseid, int* score, int ns, int nc);

//���ٿγ���Ϣ
void DestroyCos(struct COURSES* h);

//����ѧ����Ϣ
void DestroySts(struct STUDENTS* h);

//�����ܵ�ʮ������
void g_DestroySt_Crs(struct St_Crs* stcr);

//����ʮ������
void DestroyOrthogonalList(struct OrthogonalList* head);

//��ӡ������
void g_PrintStCr(struct St_Crs* stcr, int sbegin, int cbegin);

//��ӡʮ������
void PrintOrthogonalList(struct OrthogonalList* head);

//��ӿγ�
void AddCourse(struct OrthogonalList* head, int courseid);

//���ѧ��
void AddStudent(struct OrthogonalList* head, int studentid);

//���ѧ�����γ� score=-2��ʾ���޳ɼ�
void AddScore(struct St_Crs* stcr, int studentid, int courseid, int score);

//�޸�ѧ���Ŀγ̳ɼ�
void ModifyScore(struct OrthogonalList* head, int studentid, int courseid, int score);

//����һ��ѧ��id�õ�����ѧ����Ϣ
STUDENTS* GetStInfo(struct O_students* ids, struct St_Crs* stcr);

//����һ��γ�id�õ�һ��γ���Ϣ
COURSES* GetCoInfo(struct O_courses* ids, struct St_Crs* stcr);

//�õ���ѧ�������пγ̳ɼ��Ϳγ�id
struct O_courses* GetScoresOfStu(struct OrthogonalList* head, int studentid);

//�õ��ÿγ̵�����ѧ���ɼ���ѧ��id
struct O_students* GetScoresOfCrs(struct OrthogonalList* head, int courseid, int byorder);

//���ܵ�ʮ������ɾ��ѧ��
void g_DeleteStudent(struct St_Crs* stcr, int studentid);

//���ܵ�ʮ������ɾ���γ�
void g_DeleteCourse(struct St_Crs* stcr, int courseid);

//ɾ��ѧ��
void DeleteStudent(struct OrthogonalList* head, int studentid);

//ɾ���γ�
void DeleteCourse(struct OrthogonalList* head, int courseid);

//ɾ��ѧ���ɼ�
void DeleteScore(struct OrthogonalList* head, int studentid, int courseid);

//������Ϣ���ļ�
void SaveToFile(struct St_Crs* stcr);

//���ļ���ȡ��Ϣ
struct St_Crs* ReadFromFile();