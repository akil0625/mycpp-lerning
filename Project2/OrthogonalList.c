#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include "OrthogonalList.h"

//��ʼ��
struct St_Crs* g_initStCr()
{
	struct St_Crs* stcr = (struct St_Crs*)malloc(sizeof(struct St_Crs));//����ͷ���
	if (stcr == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	stcr->co_num = 0;
	stcr->stu_num = 0;
	stcr->g_courses = (COURSES*)malloc(sizeof(COURSES));//�����γ̽��
	if (stcr->g_courses == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	stcr->g_courses->next = NULL;
	stcr->g_courses->course.course_number = -1;
	stcr->g_students = (STUDENTS*)malloc(sizeof(STUDENTS));//����ѧ�����
	if (stcr->g_students == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	stcr->g_students->next = NULL;
	stcr->g_students->student.student_number = -1;
	stcr->g_head = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));//����ͷ���
	if (stcr->g_head == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	stcr->g_head->right = NULL;
	stcr->g_head->down = NULL;
	stcr->g_head->studentid = -1;
	stcr->g_head->courseid = -1;
	stcr->g_head->score = -1;
	return stcr;
}

//����ʮ������
struct OrthogonalList* CreateOrthogonalList(int* studentid, int* courseid, int* score, int ns,int nc)
{
	struct OrthogonalList *head, *p, *q;
	int i;
	head = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//����ͷ���
	if (head == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	head->right = NULL;
	head->down = NULL;
	head->studentid = -1;
	head->courseid = -1;
	head->score = -1;
	p = head;//pָ��ͷ���
	for (i = 0; i < nc; i++) {//�������пγ̽��
		q = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//�����γ̽��
		if (q == NULL)
		{
			printf("�ڴ����ʧ��\n");
			return NULL;
		}
		q->studentid = -1;//ѧ�����
		q->courseid = courseid[i];//�γ̱��
		q->score = -1;//�ɼ�
		q->right = NULL;//��ָ��
		q->down = NULL;//��ָ��
		p->right = q;//ͷ������ָ��ָ��γ̽��
		p = q;//pָ��γ̽��
	}
	p = head;//pָ��ͷ���
	for (i = 0; i < ns; i++) {//��������ѧ����㲢�Ҵ������гɼ����
		struct OrthogonalList* tmpup = head;//tmpupָ��γ̽�㣬�����������ӳɼ��ڵ�
		q = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//����ѧ�����
		if (q == NULL)
		{
			printf("�ڴ����ʧ��\n");
			return NULL;
		}
		q->right = NULL;//��ָ��
		q->down = NULL;//��ָ��
		q->courseid = -1;//�γ̱��
		q->studentid = studentid[i];//ѧ�����
		q->score = -1;//�ɼ�
		p->down = q;//pָ����һ��ѧ�����
		for (int j = 0; j < nc; j++) {//�������гɼ����
			if(tmpup->right!=NULL)
				tmpup = tmpup->right;
			else
			{
				printf("�γ����ݳ���\n");
				return NULL;
			}
			if (score[i * nc + j] != -1)
			{
				q->right = (struct OrthogonalList *)malloc(sizeof(struct OrthogonalList));//�����ɼ����
				if (q->right == NULL)
				{
					printf("�ڴ����ʧ��\n");
					return NULL;
				}
				q = q->right;//qָ��ɼ����
				q->right = NULL;//��ָ��
				q->down = NULL;//��ָ��
				q->studentid = studentid[i];//ѧ�����
				q->courseid = courseid[j];//�γ̱��
				q->score = score[i * nc + j];//�ɼ�
				struct OrthogonalList* tmpup2 = tmpup;//tmpupָ��γ̽�㣬�����������ӳɼ��ڵ�
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
		p = p->down;//pָ����һ��ѧ�����
	}
	return head;
}

//���ٿγ���Ϣ
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

//����ѧ����Ϣ
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

//�����ܵ�ʮ������
void g_DestroySt_Crs(struct St_Crs* stcr)
{
	DestroyCos(stcr->g_courses);
	DestroySts(stcr->g_students);
	DestroyOrthogonalList(stcr->g_head);
	free(stcr);
}

//����ʮ������
void DestroyOrthogonalList(struct OrthogonalList* head)
{
	struct OrthogonalList* p, * q;
	struct OrthogonalList* tmp;
	p = head;
	while (p != NULL)//pһֱ�����ƶ���ֱ��pΪ��
	{
		q = p;//��Ϊ��ʱ��qָ��p
		p = p->down;//pָ���±ߵĽ��
		while (q != NULL)//qһֱ�����ƶ���ֱ��qΪ��
		{
			tmp = q;
			q = q->right;//qָ���ұߵĽ��
			free(tmp);//�ͷ�q
		}
	}
}

//��ӡ������
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
		if (p->studentid == -1 || (si >= sbegin && si < sbegin + height))//���ǿγ̻����ڴ�ӡ��Χ�ڵ�ѧ��
		while (q != NULL)
		{
			if (q->studentid != -1 && q->courseid != -1)//���ǳɼ�
			{
				if (q->courseid != pco->courseid)//û�ж�����ʱ��ʾ���γ̵�ָ���ܵıȶ��ɼ���ָ��������
				{
					while (pco != NULL && pco->courseid != q->courseid)//��û���ܵ�ͷ֮ǰ׷����
					{
						if (ci >= cbegin && ci < cbegin + width)
						printf("%11s  |", " ");//qԽ���Ĳ��ִ���û�й�������ӡ�ո�
						pco = pco->right;
						ci++;
					}
				}
				if (ci >= cbegin && ci < cbegin + width)
				if (q->score != -2)//׷�������ϳɼ�
					printf("%9d��  |", q->score);
				else
					printf("%11s  |", "���޳ɼ�");

			}
			else if (q->studentid == -1 && q->courseid != -1)//���������˿γ̣���Ҫ�ÿγ��ڴ�ӡ��Χ��
			{
				if (ci >= cbegin && ci < cbegin + width)
				printf("%11s  |", cp->course.course_name);
			}
			else if (q->studentid != -1 && q->courseid == -1)//����������ѧ��������������
			{
				printf("%11s  |", sp->student.student_name);
			}
			else//���������˱�ͷ
			{
				printf("%11s  |", "ѧ��\\�γ�");///��ͷ
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
			while (pco != NULL)//pcoû�ߵ�ͷ�Ĳ���
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

//��ӡʮ������
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
					printf("%10d��   ", q->score);
				else
					printf("      ���޳ɼ� ");

			}
			else if (q->studentid == -1&&q->courseid!=-1)
			{
				printf("%10d��   ", q->courseid);
			}
			else if (q->studentid != -1 && q->courseid == -1)
			{
				printf("%10dͬѧ   ", q->studentid);
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

//��ӿγ�
void AddCourse(struct OrthogonalList* head, int courseid)
{
	struct OrthogonalList* p;
	p = head;
	while (p->right != NULL)//�ҵ����һ���γ̽��
	{
		if(p->right->courseid==courseid)//����γ��Ѿ�����
			return;
		p = p->right;
	}
	p->right = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
	if (p->right == NULL)
	{
		printf("�ڴ����ʧ��\n");
		return;
	}
	p->right->courseid = courseid;
	p->right->studentid = -1;
	p->right->score = -1;
	p->right->down = NULL;
	p->right->right = NULL;
	
}

//���ѧ��
void AddStudent(struct OrthogonalList* head, int studentid)
{
	struct OrthogonalList* p;
	p = head;
	while (p->down != NULL)//�ҵ����һ��ѧ�����
	{
		if (p->down->studentid == studentid)//���ѧ���Ѿ�����
			return;
		p = p->down;
	}
	p->down = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
	if (p->down == NULL)
	{
		printf("�ڴ����ʧ��\n");
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
//���ܵ�ʮ��������ӿγ�
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
		printf("���ٿռ�ʧ��\n");
		return;
	}
	p = p->next;
	p->next = NULL;
	printf("������γ�����\n");
	int tmp = scanf("%s", p->course.course_name);//�γ���
	printf("�����뼨�㣺\n");
	tmp = scanf("%d", &(p->course.course_jidian));//����
	printf("������γ�ѧ��\n");
	tmp = scanf("%d", &(p->course.couese_credit));//�γ�ѧ��
	printf("������γ��ܷ֣�\n");
	tmp = scanf("%d", &(p->course.course_score));//�γ��ܷ�
	p->course.course_number = idnum == -1 ? stcr->co_num : idnum;//�γ�id
	AddCourse(stcr->g_head, idnum == -1 ? stcr->co_num : idnum);
	stcr->co_num++;
}

//���ܵ�ʮ���������ѧ��
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
		printf("���ٿռ�ʧ��\n");
		return;
	}
	p = p->next;
	p->next = NULL;
	p->student.item_head = (ID*)malloc(sizeof(ID));//��Ŀ��Ϣ
	if (p->student.item_head == NULL)
		return;
	p->student.item_head->id = -1;
	p->student.item_head->next = NULL;

	p->student.prize_head = (ID*)malloc(sizeof(ID));//��Ʒ��Ϣ
	if (p->student.prize_head == NULL)
		return;
	p->student.prize_head->id = -1;
	p->student.prize_head->next = NULL;

	p->student.thesis_head = (ID*)malloc(sizeof(ID));//������Ϣ
	if (p->student.thesis_head == NULL)
		return;
	p->student.thesis_head->id = -1;
	p->student.thesis_head->next = NULL;

	printf("������������\n");
	int tmp = scanf("%s", p->student.student_name);//����
	printf("������绰��\n");
	tmp = scanf("%s", p->student.student_phone);//�绰
	p->student.student_number = idnum==-1?stcr->stu_num: idnum;//ѧ��id
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

//���ѧ�����γ� score=-2��ʾ���޳ɼ�
void AddScore(struct St_Crs *stcr, int studentid, int courseid, int score)
{
	struct OrthogonalList* head = stcr->g_head;
	if (head == NULL)
	{
		printf("��Ϊ��\n");
		return;
	}
	struct OrthogonalList* ps, * pc;

	//================����ѧ��������
	ps = head;
	int* sids = (int*)malloc(sizeof(int) * stcr->stu_num);//������߼��ϣ������ǰָ���id����߼��ϣ�������һ��ָ���id������߼��ϣ�˵����λ�ÿ��Բ���id��Ӧ��ֵ
	int sidssize = 0;//��߼��ϵĴ�С���������༯�ϣ�����Ӱ��
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
		printf("û�и�ѧ��\n");
		return;
	}

	//================����γ�������
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
		printf("û�иÿγ�\n");
		return;
	}
	while (ps->right != NULL && inleft(cids,cidssize,ps->right->courseid))//�ҵ���ѧ���Ŀγ̽ڵ�
	{
		ps = ps->right;
	}
	if (ps->right != NULL && ps->right->courseid == courseid)//�����ѧ���Ŀγ̽ڵ����
	{
		return;
	}
	else
	{
		struct OrthogonalList* p = (struct OrthogonalList*)malloc(sizeof(struct OrthogonalList));
		if (p == NULL)
		{
			printf("�ڴ����ʧ��\n");
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
			printf("�ڴ����ʧ��\n");
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

//�޸�ѧ���Ŀγ̳ɼ�
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
		printf("û�и�ѧ��\n");
		return;
	}

	pc = head;
	while (pc != NULL && pc->courseid != courseid)
	{
		pc = pc->right;
	}
	if (pc == NULL)
	{
		printf("û�иÿγ�\n");
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
		printf("û�и�ѧ���ĸÿγ�\n");
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
		printf("û�и�ѧ���ĸÿγ�\n");
		return;
	}
}

//����һ��ѧ��id�õ�����ѧ����Ϣ
STUDENTS* GetStInfo(struct O_students* ids, struct St_Crs* stcr)
{
	STUDENTS* sth = stcr->g_students->next;
	
	struct O_students* idh = ids;

	STUDENTS* ans = (STUDENTS*)malloc(sizeof(STUDENTS));
	if (ans == NULL)
	{
		printf("�ռ俪��ʧ��");
		return;//�ռ俪��ʧ��
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
			printf("�ռ俪��ʧ��");
			return;//�ռ俪��ʧ��
		}
		p = p->next;
		if (stp == NULL)//û�ҵ���ѧ����Ϣ
		{
			p->student.student_number = -1;
		}
		else //�ҵ���
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

//����һ��γ�id�õ�һ��γ���Ϣ
COURSES* GetCoInfo(struct O_courses* ids, struct St_Crs* stcr)
{
	COURSES* coh = stcr->g_courses->next;

	struct O_courses* idh = ids;

	COURSES* ans = (COURSES*)malloc(sizeof(COURSES));
	if (ans == NULL)
	{
		printf("�ռ俪��ʧ��");
		return;//�ռ俪��ʧ��
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
			printf("�ռ俪��ʧ��");
			return;//�ռ俪��ʧ��
		}
		p = p->next;
		if (cop == NULL)//û�ҵ���ѧ����Ϣ
		{
			p->course.course_number = -1;
		}
		else //�ҵ���
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

//�õ�ѧ���Ŀγ̳ɼ�
struct O_courses * GetScoresOfStu(struct OrthogonalList* head, int studentid)
{
	if(head==NULL)
	{
		printf("��Ϊ��\n");
		return NULL;
	}
	struct OrthogonalList* p;
	p = head;
	while (p != NULL && p->studentid != studentid)//�ҵ���ѧ��
	{
		p = p->down;
	}
	if (p == NULL)
	{
		printf("û�и�ѧ��\n");
		return NULL;
	}
	struct O_courses* ans = (struct O_courses*)malloc(sizeof(struct O_courses));
	struct O_courses* pc = ans;
	if (pc == NULL)
	{
		printf("�ڴ����ʧ��\n");
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
			printf("�ڴ����ʧ��\n");
			return NULL;
		}
		pc->next = NULL;
		p = p->right;
	}
	return ans;
}

//�Գɼ���������
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
				//�����ɼ�
				int tmp = idx->score;
				idx->score = idx->next->score;
				idx->next->score = tmp;
				//��������
				tmp = idx->studentid;
				idx->studentid = idx->next->studentid;
				idx->next->studentid = tmp;
			}
			idx = idx->next;
		}
	}

}

//�õ��γ̵�ѧ���ɼ�
struct O_students* GetScoresOfCrs(struct OrthogonalList* head, int courseid,int byorder)
{
	if (head == NULL)
	{
		printf("��Ϊ��\n");
		return NULL;
	}
	struct OrthogonalList* p;
	p = head;
	while (p != NULL && p->courseid != courseid)//�ҵ��ÿγ�
	{
		p = p->right;
	}
	if (p == NULL)
	{
		printf("û�иÿγ�\n");
		return NULL;
	}
	struct O_students* ans = (struct O_students*)malloc(sizeof(struct O_students));
	struct O_students* ps = ans;
	if (ps == NULL)
	{
		printf("�ڴ����ʧ��\n");
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
			printf("�ڴ����ʧ��\n");
			return NULL;
		}
		ps->next = NULL;
		p = p->down;
	}
	if (byorder)
		Sort(ans);
	return ans;
}



//ɾ��ѧ��
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
		printf("û�и�ѧ��\n");
		return;
	}
	struct OrthogonalList* pc;
	pc = head;
	while (pc != NULL)
	{
		struct OrthogonalList* ps = pc;
		pc = pc->right;
		while (ps->down != NULL)//ɾ����һ�γ����ѧ��
		{
			if(ps->down->studentid==studentid)//����һ����ѧ��
			{
				struct OrthogonalList* tmp = ps->down;//tmpָ��ѧ�����,�����ͷ�
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

//���ܵ�ʮ������ɾ��ѧ��
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

//���ܵ�ʮ������ɾ���γ�
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

//ɾ���γ�
void DeleteCourse(struct OrthogonalList* head, int courseid)
{
	struct OrthogonalList* ps;
	ps = head;
	while (ps != NULL)
	{
		struct OrthogonalList* pc = ps;
		ps = ps->down;
		while (pc->right != NULL)//ɾ����һѧ���Ŀγ�
		{
			if (pc->right->courseid == courseid)//����һ���ǿγ�
			{
				struct OrthogonalList* tmp = pc->right;//tmpָ��γ̽��,�����ͷ�
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

//ɾ��ѧ���Ŀγ�
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
		printf("û�и�ѧ��\n");
		return;
	}
	pc = head;
	while (pc != NULL && pc->courseid != courseid)
	{
		pc = pc->right;
	}
	if (pc == NULL)
	{
		printf("û�иÿγ�\n");
		return;
	}
	while (ps->right != NULL && ps->right->courseid != courseid)
	{
		ps = ps->right;
	}
	if (ps->right == NULL)
	{
		printf("û�и�ѧ���ĸÿγ�\n");
		return;
	}
	while (pc->down != NULL && pc->down->studentid != studentid)
	{
		pc = pc->down;
	}
	if (pc->down == NULL)
	{
		printf("û�и�ѧ���ĸÿγ�\n");
		return;
	}
	struct OrthogonalList* down, * right;
	down = pc->down;
	right = ps->right;
	pc->down = pc->down->down;
	ps->right = ps->right->right;
	free(down);
}

//������Ϣ���ļ�
void SaveToFile(struct St_Crs* stcr)
{
	struct OrthogonalList* head = stcr->g_head;
	STUDENTS* h_students = stcr->g_students;
	COURSES* h_courses = stcr->g_courses;
	FILE* fp;
	fp = fopen("st_co.dat", "w");
	if (fp == NULL)
	{
		printf("�ļ���ʧ��\n");
		return;
	}
	//����ѧ����Ϣ
	STUDENTS* stup = h_students->next;
	fprintf(fp, "students %d\n",stcr->stu_num);//��־�ſ�ʼд��ѧ����Ϣ
	while (stup != NULL)
	{
		//���ȴ���һ�б����ɿո�ֿ��� ѧ�� ���� �绰��
		fprintf(fp, "s %d %s %s \n",
			stup->student.student_number, 
			stup->student.student_name,
			stup->student.student_phone);

		//������һ�б�����Ŀid
		ID* q = stup->student.item_head;
		while (q != NULL)
		{
			fprintf(fp, "i %d \n", q->id);
			q = q->next;
		}

		//��������һ�б�������id
		q = stup->student.thesis_head;
		while (q != NULL)
		{
			fprintf(fp, "t %d \n", q->id);
			q = q->next;
		}

		//����������һ�б���ý�id
		q = stup->student.prize_head;
		while (q != NULL)
		{
			fprintf(fp, "p %d \n", q->id);
			q = q->next;
		}
		stup = stup->next;
	}

	fprintf(fp, "courses %d\n",stcr->co_num);//��־�ſ�ʼд��ѧ����Ϣ
	//�����Ŀ��Ϣ
	COURSES* cop = h_courses->next;
	while (cop != NULL)
	{
		//���ȴ���һ�б����ɿո�ֿ��� ѧ�� ���� �绰��
		fprintf(fp, "c %d %s %d %d %d \n",
			cop->course.course_number,
			cop->course.course_name,
			cop->course.course_jidian,
			cop->course.couese_credit,
			cop->course.course_score);
			cop = cop->next;
	}
	//----------------------------------------------
	//����ѧ���Ŀγ̳ɼ�
	struct OrthogonalList* p, * q;
	p = head;
	fprintf(fp, "scores\n");//��־�ſ�ʼд��ѧ����Ϣ
	while (p != NULL)//pָ��ѧ���ڵ㣬һֱ�����ƶ�
	{
		q = p;
		struct OrthogonalList* pco = head;
		while (q != NULL)//q��pָ���ѧ���ڵ㿪ʼ��һֱ�����ƶ�
		{
			if (q->studentid != -1 && q->courseid != -1)
			{
				if (q->courseid != pco->courseid)//����γ̱��벻��ȣ�˵��q�߹��˲����ڵĽڵ㣬�˴�д��-1��ʾ�����ڽڵ�
				{
					while (pco != NULL && pco->courseid != q->courseid)
					{
						pco = pco->right;
						fprintf(fp, "-1 \n");
					}
				}
				//����ɼ�����-2��˵�����ڳɼ������۴治���ڳɼ�����Ҫд��
				fprintf(fp, "%d \n", q->score);

			}
			else if (q->studentid == -1 && q->courseid != -1) {}//���������ʾ���˵㲻�ǳɼ��ڵ㣬����Ҫд��
			else if (q->studentid != -1 && q->courseid == -1) {}//���������ʾ���˵㲻�ǳɼ��ڵ㣬����Ҫд��
			else {}//���������ʾ���˵㲻�ǳɼ��ڵ㣬����Ҫд��
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
	char strLine[1024];								//��ȡ������
	if ((fp = fopen("st_co.dat", "r")) == NULL)		//�ж��ļ��Ƿ���ڼ��ɶ�
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

	while (!feof(fp))						 			//ѭ����ȡÿһ�У�ֱ���ļ�β
	{
		fgets(strLine, 1024, fp);					    //��fp��ָ����ļ�һ�����ݶ���strLine������
		//��strLineת��Ϊ������
		tmp = sscanf(strLine, "%s", readedstr);					//���������������
		
		if (0 == strcmp(readedstr, "s"))
		{
			sp->next = (STUDENTS*)malloc(sizeof(STUDENTS));
			if(sp->next==NULL)
			{
				printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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
					printf("�ڴ����ʧ��\n");
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

	while (!feof(fp))									//ѭ����ȡÿһ�У�ֱ���ļ�β
	{
		fgets(strLine, 1024, fp);					    //��fp��ָ����ļ�һ�����ݶ���strLine������
		//��strLineת��Ϊ������
		tmp = sscanf(strLine, "%s", readedstr);					//���������������

		if (0 == strcmp(readedstr, "c"))
		{
			cp->next = (COURSES*)malloc(sizeof(COURSES));
			if (cp->next == NULL)
			{
				printf("�ڴ����ʧ��\n");
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
		printf("�ڴ����ʧ��\n");
		return NULL;
	}
	int i = 0;
	while (!feof(fp))									//ѭ����ȡÿһ�У�ֱ���ļ�β
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
		printf("�ڴ����ʧ��\n");
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
		printf("�ڴ����ʧ��\n");
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

	fclose(fp);											//�ر��ļ�
	return ans;
}

