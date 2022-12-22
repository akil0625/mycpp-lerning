#include<stdio.h>
#include<stdlib.h>

//结构体
typedef struct Node
{
	int val;
	struct Node * next;
}Node;

//得到指针
//判断下一个元素是否为x
//如果是x，删除便自己传进去
//如果不是x，就把下一个指针传进去
//如果下一个指针为NULL则返回

void funcdelx(Node* L,int x)
{
	if (L->next == NULL)
		return;
	Node* tmp;
	if (L->next->val == x)
	{

		L->next = L->next->next;

		funcdelx(L, x);
	}
	else
	{
		funcdelx(L->next, x);
	}
}

void add(Node* L)
{





}

int main()
{
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = (Node*)malloc(sizeof(Node));
	L->next->val = 1;
	L->next->next = (Node*)malloc(sizeof(Node));
	L->next->next->val = 3;
	L->next->next->next = (Node*)malloc(sizeof(Node));
	L->next->next->next->val = 3;
	L->next->next->next->next = (Node*)malloc(sizeof(Node));
	L->next->next->next->next->val = 4;
	L->next->next->next->next->next = (Node*)malloc(sizeof(Node));
	L->next->next->next->next->next->val = 5;
	L->next->next->next->next->next->next = NULL;

	funcdelx(L, 3);

	Node* p = L->next;
	while (p != NULL)
	{
		printf("%d\n", p->val);
		p = p->next;
	}
	system("pause");
	return 0;
}