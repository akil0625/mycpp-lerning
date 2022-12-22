#include <stdio.h>
#include <stdlib.h>


//结点的结构体
typedef struct Node//结点
{
	//携带数据
	int val;
	//指向下一个结点
	struct Node* next;
}Node;


//初始化
void initlist(Node** h)
{
	//给头结点分配内存
	*h = (Node*)malloc(sizeof(Node));
	//链表为空
	(*h)->next = NULL;
}

//插入
void insert(Node* h, int po, int elm)
{

	Node* p = h;
	//临时指针
	Node* tmp;

	//长度为I
	int i = 1;

	//
	while (p != NULL && i != po)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return;

	tmp = (Node*)malloc(sizeof(Node));
	tmp->next = p->next;
	tmp->val = elm;
	p->next = tmp;
	tmp = NULL;
	
}


void del(Node* h, int po)
{
	Node* p = h->next;
	//临时指针
	Node* tmp;

	//长度为I
	int i = 0;

	//查找位置
	while (p != NULL && i != po)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return;
	
	tmp = p;
	p = p->next;
	free(tmp);
	tmp = NULL;
	printf("删除成功\n");

}



//按位置
void sreach(Node* h, int po, int* a)
{
	Node* p = h;

	//长度为I
	int i = 1;

	//查找位置
	while (p != NULL && i != po)
	{
		p = p->next;
		i++;
	}
	if (p == NULL)
		return;
	*a = p->next->val;
}





int main()
{
	
	//创建     分配空间当作头点
	Node* L;

	//初始化头指针
	initlist(&L);

	//插入
	insert(L,1,4);

	//删除
	del(L,1);

	//查询
	
	int a;

	//按位置
	sreach(L, 1, &a);


	printf("%d\n", a);

	//按元素
	//search（);





	system("pause");
	return 0;
}