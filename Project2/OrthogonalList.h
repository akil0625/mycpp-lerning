#pragma once

#include <stdio.h>
#include <malloc.h>
#include "sch_struct.h"

//======================================== 一系列结构体声明 ======================================================

//学生信息
struct STUDENT;
typedef struct STUDENT STUDENT;
//课程信息
struct COURSE;
typedef struct COURSE COURSE;
struct O_courses;
struct O_students;
struct OrthogonalList;

//======================================== 一系列结构体定义 ======================================================

//学生信息
struct STUDENT
{
	int student_number;           //学号
	char student_name[20];        //学生姓名
	char student_phone[12];        //学生电话
	ID* item_head;
	ID* thesis_head;
	ID* prize_head;
};

//课程信息
struct COURSE
{
	int course_number;								    //课程序号
	char course_name[20];								//课程名称
	int couese_credit;									//课程学分
	int course_jidian;									//课程总绩点
	int course_score;									//该课程总分数
};

//学生链表信息
struct STUDENTS
{
	STUDENT student;
	struct STUDENTS* next;
};

//课程链表信息
struct COURSES
{
	COURSE course;
	struct COURSES* next;
};

//学生ID和score链表
struct O_students {
	int studentid;
	int score;
	struct O_students* next;
};

//课程ID和score链表
struct O_courses {
	int courseid;
	int score;
	struct O_courses* next;
};

//十字链表，存储学生和课程的关系
struct OrthogonalList {//定义结构体
	int studentid, courseid;
	int score;
	struct OrthogonalList* right;
	struct OrthogonalList* down;
};

//十字链表，存储学生和课程的关系，包含详细的学生和课程信息
struct St_Crs {
	int stu_num;
	int co_num;
	STUDENTS* g_students;
	COURSES* g_courses;
	struct OrthogonalList* g_head;
};
//======================================== 外部变量声明   ========================================================
extern struct St_Crs* stcr;


//======================================== 一系列函数声明 ========================================================

 
//初始化
struct St_Crs* g_initStCr();
 
//向总的十字链表添加课程
void g_AddCourse(struct St_Crs* stcr);

//向总的十字链表添加学生
void g_AddStudent(struct St_Crs* stcr);

//创建十字链表
struct OrthogonalList* CreateOrthogonalList(int* studentid, int* courseid, int* score, int ns, int nc);

//销毁课程信息
void DestroyCos(struct COURSES* h);

//销毁学生信息
void DestroySts(struct STUDENTS* h);

//销毁总的十字链表
void g_DestroySt_Crs(struct St_Crs* stcr);

//销毁十字链表
void DestroyOrthogonalList(struct OrthogonalList* head);

//打印总链表
void g_PrintStCr(struct St_Crs* stcr, int sbegin, int cbegin);

//打印十字链表
void PrintOrthogonalList(struct OrthogonalList* head);

//添加课程
void AddCourse(struct OrthogonalList* head, int courseid);

//添加学生
void AddStudent(struct OrthogonalList* head, int studentid);

//添加学生到课程 score=-2表示暂无成绩
void AddScore(struct St_Crs* stcr, int studentid, int courseid, int score);

//修改学生的课程成绩
void ModifyScore(struct OrthogonalList* head, int studentid, int courseid, int score);

//根据一组学生id得到依序学生信息
STUDENTS* GetStInfo(struct O_students* ids, struct St_Crs* stcr);

//根据一组课程id得到一组课程信息
COURSES* GetCoInfo(struct O_courses* ids, struct St_Crs* stcr);

//得到该学生的所有课程成绩和课程id
struct O_courses* GetScoresOfStu(struct OrthogonalList* head, int studentid);

//得到该课程的所有学生成绩和学生id
struct O_students* GetScoresOfCrs(struct OrthogonalList* head, int courseid, int byorder);

//从总的十字链条删除学生
void g_DeleteStudent(struct St_Crs* stcr, int studentid);

//从总的十字链条删除课程
void g_DeleteCourse(struct St_Crs* stcr, int courseid);

//删除学生
void DeleteStudent(struct OrthogonalList* head, int studentid);

//删除课程
void DeleteCourse(struct OrthogonalList* head, int courseid);

//删除学生成绩
void DeleteScore(struct OrthogonalList* head, int studentid, int courseid);

//保存信息到文件
void SaveToFile(struct St_Crs* stcr);

//从文件读取信息
struct St_Crs* ReadFromFile();