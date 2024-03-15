#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "OrthogonalList.h"

//初始化
struct St_Crs* g_initStCr()
{
	struct St_Crs* stcr = (struct St_Crs*)malloc(sizeof(struct St_Crs));//创建头结点
	if (stcr == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	stcr->co_num = 0;
	stcr->stu_num = 0;
	stcr->g_courses = (COURSES*)malloc(sizeof(COURSES));//创建课程结点
	if (stcr->g_courses == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	stcr->g_courses->next = NULL;
	stcr->g_courses->course.course_number = -1;
	stcr->g_students = (STUDENTS*)malloc(sizeof(STUDENTS));//创建学生结点
	if (stcr->g_students == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	stcr->g_students->next = NULL;
	stcr->g_students->student.student_number = -1;
	stcr->g_head = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));//创建头结点
	if (stcr->g_head == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	stcr->g_head->right = NULL;
	stcr->g_head->down = NULL;
	stcr->g_head->studentid = -1;
	stcr->g_head->courseid = -1;
	stcr->g_head->score = -1;
	return stcr;
}

//创建十字链表
struct OrthogonalList* CreateOrthogonalList(int* studentid, int* courseid, int* score, int ns,int nc)
{
	struct OrthogonalList *head, *p, *q;
	int i;
	head = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//创建头结点
	if (head == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	head->right = NULL;
	head->down = NULL;
	head->studentid = -1;
	head->courseid = -1;
	head->score = -1;
	p = head;//p指向头结点
	for (i = 0; i < nc; i++) {//创建所有课程结点
		q = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//创建课程结点
		if (q == NULL)
		{
			printf("内存分配失败\n");
			return NULL;
		}
		q->studentid = -1;//学生编号
		q->courseid = courseid[i];//课程编号
		q->score = -1;//成绩
		q->right = NULL;//右指针
		q->down = NULL;//下指针
		p->right = q;//头结点的右指针指向课程结点
		p = q;//p指向课程结点
	}
	p = head;//p指向头结点
	for (i = 0; i < ns; i++) {//创建所有学生结点并且创建所有成绩结点
		struct OrthogonalList* tmpup = head;//tmpup指向课程结点，负责向下连接成绩节点
		q = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//创建学生结点
		if (q == NULL)
		{
			printf("内存分配失败\n");
			return NULL;
		}
		q->right = NULL;//右指针
		q->down = NULL;//下指针
		q->courseid = -1;//课程编号
		q->studentid = studentid[i];//学生编号
		q->score = -1;//成绩
		p->down = q;//p指向下一个学生结点
		for (int j = 0; j < nc; j++) {//创建所有成绩结点
			if(tmpup->right!=NULL)
				tmpup = tmpup->right;
			else
			{
				printf("课程数据出错！\n");
				return NULL;
			}
			if (score[i * nc + j] != -1)
			{
				q->right = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//创建成绩结点
				if (q->right == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				q = q->right;//q指向成绩结点
				q->right = NULL;//右指针
				q->down = NULL;//下指针
				q->studentid = studentid[i];//学生编号
				q->courseid = courseid[j];//课程编号
				q->score = score[i * nc + j];//成绩
				struct OrthogonalList* tmpup2 = tmpup;//tmpup指向课程结点，负责向下连接成绩节点
				for (int k = 0; k <= nc; k++)
				{
					if (tmpup2->down == NULL)
						break;
					tmpup2 = tmpup2->down;
				}
				tmpup2->down = q;

			}
		}
		tmpup = head;
		p = p->down;//p指向下一个学生结点
	}
	return head;
}

//销毁课程信息
void DestroyCos(struct COURSES* h)
{
	struct COURSES* p, * tmpp;
	p = h;
	while (p != NULL)
	{
		tmpp = p;
		p = p->next;
		free(tmpp);
	}
}

//销毁学生信息
void DestroySts(struct STUDENTS* h)
{
	struct STUDENTS* q, * tmpq;
	q = h;
	while (q != NULL)
	{
		tmpq = q;
		q = q->next;
		free(tmpq);
	}
}

//销毁总的十字链表
void g_DestroySt_Crs(struct St_Crs* stcr)
{
	DestroyCos(stcr->g_courses);
	DestroySts(stcr->g_students);
	DestroyOrthogonalList(stcr->g_head);
	free(stcr);
}

//销毁十字链表
void DestroyOrthogonalList(struct OrthogonalList* head)
{
	struct OrthogonalList* p, * q;
	struct OrthogonalList* tmp;
	p = head;
	while (p != NULL)//p一直往下移动，直到p为空
	{
		q = p;//不为空时，q指向p
		p = p->down;//p指向下边的结点
		while (q != NULL)//q一直往右移动，直到q为空
		{
			tmp = q;
			q = q->right;//q指向右边的结点
			free(tmp);//释放q
		}
	}
}

//打印总链表
void g_PrintStCr(struct St_Crs* stcr, int sbegin, int cbegin)
{
	int width = 7;
	int height = 10;
	int rwidth = stcr->co_num - cbegin - width + 1 < 0 ? stcr->co_num - cbegin + 2 : width + 1;
	int si = 0;
	int ci = 0;
	struct OrthogonalList* p, * q;
	STUDENTS* sp = stcr->g_students;
	COURSES* cp = stcr->g_courses;
	p = stcr->g_head;
	for (int i = 0; i < rwidth; i++)
	{
		printf("--------------");
	}
	printf("\n");
	while (p != NULL)
	{
		q = p;
		ci = 0;
		struct OrthogonalList* pco = stcr->g_head;
		if (p->studentid == -1 || (si >= sbegin && si < sbegin + height))//这是课程或是在打印范围内的学生
		while (q != NULL)
		{
			if (q->studentid != -1 && q->courseid != -1)//这是成绩
			{
				if (q->courseid != pco->courseid)//没有对其上时表示读课程的指针跑的比读成绩的指针跑慢了
				{
					while (pco != NULL && pco->courseid != q->courseid)//在没有跑到头之前追回来
					{
						if (ci >= cbegin && ci < cbegin + width)
						printf("%11s  |", " ");//q越过的部分代表没有关联，打印空格
						pco = pco->right;
						ci++;
					}
				}
				if (ci >= cbegin && ci < cbegin + width)
				if (q->score != -2)//追上来后补上成绩
					printf("%9d分  |", q->score);
				else
					printf("%11s  |", "暂无成绩");

			}
			else if (q->studentid == -1 && q->courseid != -1)//代表遇上了课程，需要该课程在打印范围内
			{
				if (ci >= cbegin && ci < cbegin + width)
				printf("%11s  |", cp->course.course_name);
			}
			else if (q->studentid != -1 && q->courseid == -1)//代表遇上了学生，无条件放行
			{
				printf("%11s  |", sp->student.student_name);
			}
			else//代表遇上了表头
			{
				printf("%11s  |", "学生\\课程");///表头
			}
			q = q->right;
			if (p->studentid == -1)
				cp = cp->next;
			if (pco != NULL)
			{
				pco = pco->right;
				ci++;
			}
		}
		if (p->studentid == -1 || (si >= sbegin && si < sbegin + 10))
		{
			while (pco != NULL)//pco没走到头的部分
			{
				if (ci >= cbegin && ci < cbegin + width)
				printf("%11s  |", " ");
				pco = pco->right;
				ci++;
			}
			printf("\n");
			for (int i = 0; i < rwidth; i++)
			{
				printf("--------------");
			}
			printf("\n");
		}
		p = p->down;
		sp = sp->next;
		si++;
		

	}
}

//打印十字链表
void PrintOrthogonalList(struct OrthogonalList* head)
{
	struct OrthogonalList* p, * q;
	p = head;

	while (p != NULL)
	{
		q = p;
		struct OrthogonalList* pco = head;
		while (q != NULL)
		{
			if (q->studentid != -1 && q->courseid != -1)
			{		
				if (q->courseid != pco->courseid)
				{
					while (pco!=NULL&&pco->courseid != q->courseid)
					{
						pco = pco->right;
						printf("               ");
					}
				}
				if (q->score != -2)
					printf("%10d分   ", q->score);
				else
					printf("      暂无成绩 ");

			}
			else if (q->studentid == -1&&q->courseid!=-1)
			{
				printf("%10d课   ", q->courseid);
			}
			else if (q->studentid != -1 && q->courseid == -1)
			{
				printf("%10d同学   ", q->studentid);
			}
			else
			{
				printf("                ");
			}	
			q = q->right;
			if(pco!=NULL)
				pco = pco->right;;
		}
		printf("\n");
		p = p->down;
	}
}

//添加课程
void AddCourse(struct OrthogonalList* head, int courseid)
{
	struct OrthogonalList* p;
	p = head;
	while (p->right != NULL)//找到最后一个课程结点
	{
		if(p->right->courseid==courseid)//如果课程已经存在
			return;
		p = p->right;
	}
	p->right = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
	if (p->right == NULL)
	{
		printf("内存分配失败\n");
		return;
	}
	p->right->courseid = courseid;
	p->right->studentid = -1;
	p->right->score = -1;
	p->right->down = NULL;
	p->right->right = NULL;
	
}

//添加学生
void AddStudent(struct OrthogonalList* head, int studentid)
{
	struct OrthogonalList* p;
	p = head;
	while (p->down != NULL)//找到最后一个学生结点
	{
		if (p->down->studentid == studentid)//如果学生已经存在
			return;
		p = p->down;
	}
	p->down = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
	if (p->down == NULL)
	{
		printf("内存分配失败\n");
		return;
	}
	p->down->studentid = studentid;
	p->down->courseid = -1;
	p->down->score = -1;
	p->down->right = NULL;
	p->down->down = NULL;
}

void bubblesort(int* nums, int size)
{
	for (int j = 1; j < size; j++)
	{
		for (int i = 0; i < size - j; i++)
		{
			if (nums[i] > nums[i + 1])
			{
				int tmp = nums[i];
				nums[i] = nums[i + 1];
				nums[i + 1] = tmp;
			}
		}
	}
}
//向总的十字链表添加课程
void g_AddCourse(struct St_Crs* stcr)
{
	COURSES* p = stcr->g_courses;
	if (p == NULL)
		return;
	int* ids = (int*)malloc(sizeof(int) * stcr->co_num);
	if (ids == NULL)
		return;
	int i = 0;
	int idnum = -1;
	while (p->next != NULL)
	{
		ids[i] = p->next->course.course_number;
		p = p->next;
		i++;
	}
	bubblesort(ids, stcr->co_num);
	for (int i = 0; i < stcr->co_num - 1; i++)
	{
		if (ids[i + 1] - ids[i] > 1)
		{
			idnum = ids[i] + 1;
			break;
		}
	}
	free(ids);
	p->next = (COURSES*)malloc(sizeof(COURSES));
	if (p->next == NULL)
	{
		printf("开辟空间失败\n");
		return;
	}
	p = p->next;
	p->next = NULL;
	printf("请输入课程名：\n");
	int tmp = scanf("%s", p->course.course_name);//课程名
	printf("请输入绩点：\n");
	tmp = scanf("%d", &(p->course.course_jidian));//绩点
	printf("请输入课程学分\n");
	tmp = scanf("%d", &(p->course.couese_credit));//课程学分
	printf("请输入课程总分：\n");
	tmp = scanf("%d", &(p->course.course_score));//课程总分
	p->course.course_number = idnum == -1 ? stcr->co_num : idnum;//课程id
	AddCourse(stcr->g_head, idnum == -1 ? stcr->co_num : idnum);
	stcr->co_num++;
}

//向总的十字链表添加学生
void g_AddStudent(struct St_Crs* stcr)
{
	STUDENTS* p = stcr->g_students;
	if (p == NULL)
		return;
	int* ids = (int*)malloc(sizeof(int) * stcr->stu_num);
	if (ids == NULL)
		return;
	int i = 0;
	int idnum = -1;
	while (p->next != NULL)
	{
		ids[i] = p->next->student.student_number;
		i++;
		p = p->next;
	}
	bubblesort(ids, stcr->stu_num);
	for (int i = 0; i < stcr->stu_num-1; i++)
	{
		if (ids[i + 1] - ids[i] > 1)
		{
			idnum = ids[i] + 1;
			break;
		}
	}
	free(ids);

	p->next = (STUDENTS*)malloc(sizeof(STUDENTS));
	if (p->next == NULL)
	{
		printf("开辟空间失败\n");
		return;
	}
	p = p->next;
	p->next = NULL;
	p->student.item_head = (ID*)malloc(sizeof(ID));//项目信息
	if (p->student.item_head == NULL)
		return;
	p->student.item_head->id = -1;
	p->student.item_head->next = NULL;

	p->student.prize_head = (ID*)malloc(sizeof(ID));//奖品信息
	if (p->student.prize_head == NULL)
		return;
	p->student.prize_head->id = -1;
	p->student.prize_head->next = NULL;

	p->student.thesis_head = (ID*)malloc(sizeof(ID));//论文信息
	if (p->student.thesis_head == NULL)
		return;
	p->student.thesis_head->id = -1;
	p->student.thesis_head->next = NULL;

	printf("请输入姓名：\n");
	int tmp = scanf("%s", p->student.student_name);//姓名
	printf("请输入电话：\n");
	tmp = scanf("%s", p->student.student_phone);//电话
	p->student.student_number = idnum==-1?stcr->stu_num: idnum;//学生id
	AddStudent(stcr->g_head, idnum == -1 ? stcr->stu_num : idnum);
	stcr->stu_num++;
}

int inleft(int* nums, int size, int num)
{
	for (int i = 0; i < size; i++)
	{
		if (nums[i] == num)
			return 1;
	}
	return 0;
}

//添加学生到课程 score=-2表示暂无成绩
void AddScore(struct St_Crs *stcr, int studentid, int courseid, int score)
{
	struct OrthogonalList* head = stcr->g_head;
	if (head == NULL)
	{
		printf("表为空\n");
		return;
	}
	struct OrthogonalList* ps, * pc;

	//================处理学生链表部分
	ps = head;
	int* sids = (int*)malloc(sizeof(int) * stcr->stu_num);//构造左边集合，如果当前指向的id在左边集合，而其下一个指向的id不在左边集合，说明此位置可以插入id对应的值
	int sidssize = 0;//左边集合的大小，包含多余集合，但不影响
	if (sids == NULL)
		return;
	int i = 0;
	while (ps != NULL && ps->studentid != studentid)
	{
		sids[i] = ps->studentid;
		ps = ps->down;
		i++;
	}
	sidssize = i;
	if (ps == NULL)
	{
		printf("没有该学生\n");
		return;
	}

	//================处理课程链表部分
	pc = head;
	int* cids = (int*)malloc(sizeof(int) * stcr->co_num);
	int cidssize = 0;
	if (cids == NULL)
		return;
	i = 0;
	while (pc != NULL && pc->courseid != courseid)
	{
		cids[i] = pc->courseid;
		pc = pc->right;
		i++;
	}
	cidssize = i;
	if (pc == NULL)
	{
		printf("没有该课程\n");
		return;
	}
	while (ps->right != NULL && inleft(cids,cidssize,ps->right->courseid))//找到该学生的课程节点
	{
		ps = ps->right;
	}
	if (ps->right != NULL && ps->right->courseid == courseid)//如果该学生的课程节点存在
	{
		return;
	}
	else
	{
		struct OrthogonalList* p = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
		if (p == NULL)
		{
			printf("内存分配失败\n");
			return;
		}
		p->courseid = courseid;
		p->studentid = studentid;
		p->score = score;
		p->right = ps->right;
		ps->right = p;
	}
	while (pc->down != NULL && inleft(sids, sidssize, pc->down->studentid))
	{
		pc = pc->down;
	}
	if (pc->down != NULL && pc->down->studentid == studentid)
	{
		return;
	}
	else
	{
		struct OrthogonalList* p = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
		if (p == NULL)
		{
			printf("内存分配失败\n");
			return;
		}
		p->courseid = courseid;
		p->studentid = studentid;
		p->score = score;
		p->down = pc->down;
		pc->down = p;
	}
	free(cids);
	free(sids);
}

//修改学生的课程成绩
void ModifyScore(struct OrthogonalList* head, int studentid, int courseid, int score)
{
	struct OrthogonalList* ps, * pc;

	ps = head;
	while (ps != NULL && ps->studentid != studentid)
	{
		ps = ps->down;
	}
	if (ps == NULL)
	{
		printf("没有该学生\n");
		return;
	}

	pc = head;
	while (pc != NULL && pc->courseid != courseid)
	{
		pc = pc->right;
	}
	if (pc == NULL)
	{
		printf("没有该课程\n");
		return;
	}

	while (ps->right != NULL && ps->right->courseid < courseid)
	{
		ps = ps->right;
	}
	if (ps->right != NULL && ps->right->courseid == courseid)
	{
		ps->right->score = score;
	}
	else
	{
		printf("没有该学生的该课程\n");
		return;
	}

	while (pc->down != NULL && pc->down->studentid < studentid)
	{
		pc = pc->down;
	}
	if (pc->down != NULL && pc->down->studentid == studentid)
	{
		pc->down->score = score;
	}
	else
	{
		printf("没有该学生的该课程\n");
		return;
	}
}

//根据一组学生id得到依序学生信息
STUDENTS* GetStInfo(struct O_students* ids, struct St_Crs* stcr)
{
	STUDENTS* sth = stcr->g_students->next;
	
	struct O_students* idh = ids;

	STUDENTS* ans = (STUDENTS*)malloc(sizeof(STUDENTS));
	if (ans == NULL)
	{
		printf("空间开辟失败");
		return;//空间开辟失败
	}
	STUDENTS* p = ans;
	while (idh != NULL)
	{
		STUDENTS* stp = sth;
		while (stp != NULL && stp->student.student_number != idh->studentid)
		{
			stp = stp->next;
		}
		p->next = (STUDENTS*)malloc(sizeof(STUDENTS));
		if (p->next == NULL)
		{
			printf("空间开辟失败");
			return;//空间开辟失败
		}
		p = p->next;
		if (stp == NULL)//没找到该学生信息
		{
			p->student.student_number = -1;
		}
		else //找到了
		{
			p->student.item_head = stp->student.item_head;
			p->student.prize_head = stp->student.prize_head;
			p->student.thesis_head = stp->student.thesis_head;
			p->student.student_number = stp->student.student_number;
			for (int i = 0; i < 20; i++)
			{
				p->student.student_name[i] = stp->student.student_name[i];
			}
			for (int i = 0; i < 12; i++)
			{
				p->student.student_phone[i] = stp->student.student_phone[i];
			}
		}
		idh = idh->next;
	}
	p->next = NULL;
	p = ans;
	ans = ans->next;
	free(p);
	return ans;
}

//根据一组课程id得到一组课程信息
COURSES* GetCoInfo(struct O_courses* ids, struct St_Crs* stcr)
{
	COURSES* coh = stcr->g_courses->next;

	struct O_courses* idh = ids;

	COURSES* ans = (COURSES*)malloc(sizeof(COURSES));
	if (ans == NULL)
	{
		printf("空间开辟失败");
		return;//空间开辟失败
	}
	COURSES* p = ans;
	while (idh != NULL)
	{
		COURSES* cop = coh;
		while (cop != NULL && cop->course.course_number != idh->courseid)
		{
			cop = cop->next;
		}
		p->next = (COURSES*)malloc(sizeof(COURSES));
		if (p->next == NULL)
		{
			printf("空间开辟失败");
			return;//空间开辟失败
		}
		p = p->next;
		if (cop == NULL)//没找到该学生信息
		{
			p->course.course_number = -1;
		}
		else //找到了
		{
			p->course.couese_credit = cop->course.couese_credit;
			p->course.course_jidian = cop->course.course_jidian;
			p->course.course_number = cop->course.course_number;
			p->course.course_score = cop->course.course_score;
			for (int i = 0; i < 20; i++)
			{
				p->course.course_name[i] = cop->course.course_name[i];
			}
		}
		idh = idh->next;
	}
	p->next = NULL;
	p = ans;
	ans = ans->next;
	free(p);
	return ans;
}

//得到学生的课程成绩
struct O_courses * GetScoresOfStu(struct OrthogonalList* head, int studentid)
{
	if(head==NULL)
	{
		printf("表为空\n");
		return NULL;
	}
	struct OrthogonalList* p;
	p = head;
	while (p != NULL && p->studentid != studentid)//找到该学生
	{
		p = p->down;
	}
	if (p == NULL)
	{
		printf("没有该学生\n");
		return NULL;
	}
	struct O_courses* ans = (struct O_courses*)malloc(sizeof(struct O_courses));
	struct O_courses* pc = ans;
	if (pc == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	while (p->right != NULL)
	{
		pc->courseid = p->right->courseid;
		pc->score = p->right->score;
		if (p->right->right != NULL)
		{
			pc->next = (struct O_courses*)malloc(sizeof(struct O_courses));
		}
		else
		{
			pc->next = NULL;
			break;
		}
		pc = pc->next;
		if (pc == NULL)
		{
			printf("内存分配失败\n");
			return NULL;
		}
		pc->next = NULL;
		p = p->right;
	}
	return ans;
}

//对成绩进行排序
void Sort(struct O_students* indexes)
{
	int size = 0;
	struct O_students* idx = indexes;
	while (idx != NULL)
	{
		size++;
		idx = idx->next;
	}
	for (int i = 1; i < size - 1; i++)
	{
		idx = indexes;
		for (int j = 0; j < size - i; j++)
		{
			if (idx->score < idx->next->score)
			{
				//交换成绩
				int tmp = idx->score;
				idx->score = idx->next->score;
				idx->next->score = tmp;
				//交换索引
				tmp = idx->studentid;
				idx->studentid = idx->next->studentid;
				idx->next->studentid = tmp;
			}
			idx = idx->next;
		}
	}

}

//得到课程的学生成绩
struct O_students* GetScoresOfCrs(struct OrthogonalList* head, int courseid,int byorder)
{
	if (head == NULL)
	{
		printf("表为空\n");
		return NULL;
	}
	struct OrthogonalList* p;
	p = head;
	while (p != NULL && p->courseid != courseid)//找到该课程
	{
		p = p->right;
	}
	if (p == NULL)
	{
		printf("没有该课程\n");
		return NULL;
	}
	struct O_students* ans = (struct O_students*)malloc(sizeof(struct O_students));
	struct O_students* ps = ans;
	if (ps == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	while (p->down != NULL)
	{
		ps->studentid = p->down->studentid;
		ps->score = p->down->score;
		if (p->down->down != NULL)
		{
			ps->next = (struct O_students*)malloc(sizeof(struct O_students));
		}
		else
		{
			ps->next = NULL;
			break;
		}
		ps = ps->next;
		if (ps == NULL)
		{
			printf("内存分配失败\n");
			return NULL;
		}
		ps->next = NULL;
		p = p->down;
	}
	if (byorder)
		Sort(ans);
	return ans;
}



//删除学生
void DeleteStudent(struct OrthogonalList* head, int studentid)
{
	struct OrthogonalList* check;
	check = head;
	int flag = 1;
	while (check != NULL)
	{
		if (check->studentid == studentid)
		{
			flag = 0;
		}
		check = check->down;
	}
	if(flag)
	{
		printf("没有该学生\n");
		return;
	}
	struct OrthogonalList* pc;
	pc = head;
	while (pc != NULL)
	{
		struct OrthogonalList* ps = pc;
		pc = pc->right;
		while (ps->down != NULL)//删除这一课程里的学生
		{
			if(ps->down->studentid==studentid)//下下一个是学生
			{
				struct OrthogonalList* tmp = ps->down;//tmp指向学生结点,负责释放
				ps->down = ps->down->down;
				free(tmp);
				break;
			}
			else 
			{
				ps = ps->down;
			}

		}
	}
}

//从总的十字链条删除学生
void g_DeleteStudent(struct St_Crs* stcr, int studentid)
{
	STUDENTS* sp = stcr->g_students;
	while (sp->next != NULL)
	{
		if (sp->next->student.student_number == studentid)
		{
			STUDENTS* tmp = sp->next;
			sp->next = sp->next->next;
			free(tmp);
			stcr->stu_num--;
			break;
		}
		sp = sp->next;
	}
	DeleteStudent(stcr->g_head, studentid);
}

//从总的十字链条删除课程
void g_DeleteCourse(struct St_Crs* stcr, int courseid)
{
	COURSES* cp = stcr->g_courses;
	while (cp->next != NULL)
	{
		if (cp->next->course.course_number == courseid)
		{
			COURSE* tmp = cp->next;
			cp->next = cp->next->next;
			free(tmp);
			stcr->co_num--;
			break;
		}
		cp = cp->next;
	}
	DeleteCourse(stcr->g_head, courseid);
}

//删除课程
void DeleteCourse(struct OrthogonalList* head, int courseid)
{
	struct OrthogonalList* ps;
	ps = head;
	while (ps != NULL)
	{
		struct OrthogonalList* pc = ps;
		ps = ps->down;
		while (pc->right != NULL)//删除这一学生的课程
		{
			if (pc->right->courseid == courseid)//下下一个是课程
			{
				struct OrthogonalList* tmp = pc->right;//tmp指向课程结点,负责释放
				pc->right = pc->right->right;
				free(tmp);
				break;
			}
			else
			{
				pc = pc->right;
			}

		}
	}
}

//删除学生的课程
void DeleteScore(struct OrthogonalList* head, int studentid, int courseid)
{
	struct OrthogonalList* ps, * pc;
	ps = head;
	while (ps != NULL && ps->studentid != studentid)
	{
		ps = ps->down;
	}
	if (ps == NULL)
	{
		printf("没有该学生\n");
		return;
	}
	pc = head;
	while (pc != NULL && pc->courseid != courseid)
	{
		pc = pc->right;
	}
	if (pc == NULL)
	{
		printf("没有该课程\n");
		return;
	}
	while (ps->right != NULL && ps->right->courseid != courseid)
	{
		ps = ps->right;
	}
	if (ps->right == NULL)
	{
		printf("没有该学生的该课程\n");
		return;
	}
	while (pc->down != NULL && pc->down->studentid != studentid)
	{
		pc = pc->down;
	}
	if (pc->down == NULL)
	{
		printf("没有该学生的该课程\n");
		return;
	}
	struct OrthogonalList* down, * right;
	down = pc->down;
	right = ps->right;
	pc->down = pc->down->down;
	ps->right = ps->right->right;
	free(down);
}

//保存信息到文件
void SaveToFile(struct St_Crs* stcr)
{
	struct OrthogonalList* head = stcr->g_head;
	STUDENTS* h_students = stcr->g_students;
	COURSES* h_courses = stcr->g_courses;
	FILE* fp;
	fp = fopen("st_co.dat", "w");
	if (fp == NULL)
	{
		printf("文件打开失败\n");
		return;
	}
	//保存学生信息
	STUDENTS* stup = h_students->next;
	fprintf(fp, "students %d\n",stcr->stu_num);//标志着开始写入学生信息
	while (stup != NULL)
	{
		//首先带第一行保存由空格分开的 学号 姓名 电话号
		fprintf(fp, "s %d %s %s \n",
			stup->student.student_number, 
			stup->student.student_name,
			stup->student.student_phone);

		//再在下一行保存项目id
		ID* q = stup->student.item_head;
		while (q != NULL)
		{
			fprintf(fp, "i %d \n", q->id);
			q = q->next;
		}

		//再在下下一行保存论文id
		q = stup->student.thesis_head;
		while (q != NULL)
		{
			fprintf(fp, "t %d \n", q->id);
			q = q->next;
		}

		//再在下下下一行保存得奖id
		q = stup->student.prize_head;
		while (q != NULL)
		{
			fprintf(fp, "p %d \n", q->id);
			q = q->next;
		}
		stup = stup->next;
	}

	fprintf(fp, "courses %d\n",stcr->co_num);//标志着开始写入学生信息
	//保存科目信息
	COURSES* cop = h_courses->next;
	while (cop != NULL)
	{
		//首先带第一行保存由空格分开的 学号 姓名 电话号
		fprintf(fp, "c %d %s %d %d %d \n",
			cop->course.course_number,
			cop->course.course_name,
			cop->course.course_jidian,
			cop->course.couese_credit,
			cop->course.course_score);
			cop = cop->next;
	}
	//----------------------------------------------
	//保存学生的课程成绩
	struct OrthogonalList* p, * q;
	p = head;
	fprintf(fp, "scores\n");//标志着开始写入学生信息
	while (p != NULL)//p指向学生节点，一直往下移动
	{
		q = p;
		struct OrthogonalList* pco = head;
		while (q != NULL)//q从p指向的学生节点开始，一直往右移动
		{
			if (q->studentid != -1 && q->courseid != -1)
			{
				if (q->courseid != pco->courseid)//如果课程编码不相等，说明q走过了不存在的节点，此处写入-1表示不存在节点
				{
					while (pco != NULL && pco->courseid != q->courseid)
					{
						pco = pco->right;
						fprintf(fp, "-1 \n");
					}
				}
				//如果成绩不是-2，说明存在成绩，无论存不存在成绩，都要写入
				fprintf(fp, "%d \n", q->score);

			}
			else if (q->studentid == -1 && q->courseid != -1) {}//此种情况表示，此点不是成绩节点，不需要写入
			else if (q->studentid != -1 && q->courseid == -1) {}//此种情况表示，此点不是成绩节点，不需要写入
			else {}//此种情况表示，此点不是成绩节点，不需要写入
			q = q->right;
			if (pco != NULL)
				pco = pco->right;;
		}
		while (pco != NULL)
		{
			fprintf(fp, "-1 \n");
			pco = pco->right;
		}
		p = p->down;
	}


	fprintf(fp, "eof\n");


	fclose(fp);
}

struct St_Crs* ReadFromFile()
{
	FILE* fp;
	char strLine[1024];								//读取缓冲区
	if ((fp = fopen("st_co.dat", "r")) == NULL)		//判断文件是否存在及可读
	{
		printf("Open Falied!");
		return NULL;
	}
	int tmp = 0;

	char readedstr[20];
	int readedint = 0;

	struct St_Crs* ans = g_initStCr();
	STUDENTS* sp = ans->g_students;
	COURSES* cp = ans->g_courses;

	while (!feof(fp))						 			//循环读取每一行，直到文件尾
	{
		fgets(strLine, 1024, fp);					    //将fp所指向的文件一行内容读到strLine缓冲区
		//将strLine转换为输入流
		tmp = sscanf(strLine, "%s", readedstr);					//输出所读到的内容
		
		if (0 == strcmp(readedstr, "s"))
		{
			sp->next = (STUDENTS*)malloc(sizeof(STUDENTS));
			if(sp->next==NULL)
			{
				printf("内存分配失败\n");
				return NULL;
			}
			sp = sp->next;
			tmp = sscanf(strLine, "%s%d%s%s", readedstr, &(sp->student.student_number), sp->student.student_name, sp->student.student_phone);
			sp->next = NULL;
		}
		if(0==strcmp(readedstr,"i"))
		{
			tmp = sscanf(strLine, "%s%d", readedstr, &readedint);
			if (readedint = !- 1)
			{
				sp->student.item_head->next = (ID*)malloc(sizeof(ID));
				if (sp->student.item_head->next == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.item_head = sp->student.item_head->next;
				tmp = sscanf(strLine, "%s%d", readedstr, &(sp->student.item_head->id));
				sp->student.item_head->next = NULL;
			}
			else
			{
				sp->student.item_head = (ID*)malloc(sizeof(ID));
				if (sp->student.item_head == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.item_head->id = -1;
				sp->student.item_head->next = NULL;
			}
		}

		if (0 == strcmp(readedstr, "t"))
		{
			tmp = sscanf(strLine, "%s%d", readedstr, &readedint);
			if (readedint = !- 1)
			{
				sp->student.thesis_head->next = (ID*)malloc(sizeof(ID));
				if (sp->student.thesis_head->next == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.thesis_head = sp->student.thesis_head->next;
				tmp = sscanf(strLine, "%s%d", readedstr, &(sp->student.thesis_head->id));
				sp->student.thesis_head->next = NULL;
			}
			else
			{
				sp->student.thesis_head = (ID*)malloc(sizeof(ID));
				if (sp->student.thesis_head == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.thesis_head->id = -1;
				sp->student.thesis_head->next = NULL;
			}
		}

		if(0==strcmp(readedstr,"p"))
		{
			tmp = sscanf(strLine, "%s%d", readedstr, &readedint);
			if (readedint = !- 1)
			{
				sp->student.prize_head->next = (ID*)malloc(sizeof(ID));
				if (sp->student.prize_head->next == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.prize_head = sp->student.prize_head->next;
				tmp = sscanf(strLine, "%s%d", readedstr, &(sp->student.prize_head->id));
				sp->student.prize_head->next = NULL;
			}
			else
			{
				sp->student.prize_head = (ID*)malloc(sizeof(ID));
				if (sp->student.prize_head == NULL)
				{
					printf("内存分配失败\n");
					return NULL;
				}
				sp->student.prize_head->id = -1;
				sp->student.prize_head->next = NULL;
			}
		}


		if (0 == strcmp(readedstr, "students"))
		{
			tmp = sscanf(strLine, "%s%d", readedstr, &readedint);
			ans->stu_num = readedint;
		}
		if (0 == strcmp(readedstr, "courses"))
		{
			tmp = sscanf(strLine, "%s%d", readedstr, &readedint);
			ans->co_num = readedint;
			break;
		}
	}

	while (!feof(fp))									//循环读取每一行，直到文件尾
	{
		fgets(strLine, 1024, fp);					    //将fp所指向的文件一行内容读到strLine缓冲区
		//将strLine转换为输入流
		tmp = sscanf(strLine, "%s", readedstr);					//输出所读到的内容

		if (0 == strcmp(readedstr, "c"))
		{
			cp->next = (COURSES*)malloc(sizeof(COURSES));
			if (cp->next == NULL)
			{
				printf("内存分配失败\n");
				return NULL;
			}
			cp = cp->next;
			tmp = sscanf(strLine, "%s%d%s%d%d%d", readedstr,
				&(cp->course.course_number),
				cp->course.course_name,
				&(cp->course.course_jidian),
				&(cp->course.couese_credit),
				&(cp->course.course_score));
			cp->next = NULL;
		}
		if (0 == strcmp(readedstr, "scores"))
		{
			break;
		}
	}
	int * scores = (int*)malloc(sizeof(int) * ans->stu_num * ans->co_num);
	if (scores == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	int i = 0;
	while (!feof(fp))									//循环读取每一行，直到文件尾
	{
		fgets(strLine, 1024, fp);
		tmp = sscanf(strLine, "%s", readedstr);
		if (strcmp(readedstr, "eof") == 0)
			break;
		tmp = sscanf(strLine, "%d", scores + i);
		i++;
	}
	int * studentid = (int*)malloc(sizeof(int) * ans->stu_num);
	if (studentid == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	sp = ans->g_students->next;
	for (int i = 0; i < ans->stu_num; i++)
	{
		studentid[i] = sp->student.student_number;
		sp = sp->next;
	}
	int * courseid = (int*)malloc(sizeof(int) * ans->co_num);
	if (courseid == NULL)
	{
		printf("内存分配失败\n");
		return NULL;
	}
	cp = ans->g_courses->next;
	for (int i = 0; i < ans->co_num; i++)
	{
		courseid[i] = cp->course.course_number;
		cp = cp->next;
	}
	ans->g_head = CreateOrthogonalList( studentid, courseid, scores, ans->stu_num, ans->co_num);
	free(scores);
	free(studentid);
	free(courseid);

	fclose(fp);											//关闭文件
	return ans;
}

