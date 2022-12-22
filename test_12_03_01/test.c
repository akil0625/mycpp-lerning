//屏蔽警告
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

//结点结构体
typedef struct Node
{

	int val;
	struct Node* next;

}Node;

//添加节点的函数
void add(Node* L)
{
	Node* p = L;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = (Node*)malloc(sizeof(Node));
	p->next->next = NULL;
	scanf("%d", &p->next->val);
}

//---------------------------------------------------------------
  /* 函数区 */

//---------------------------------------------------------------
//主函数
int main()
{
	//创建链表头结点
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	Node* p;

	int lenth = 0;
	printf("请问你要像链表中添加多少个元素\n");
	scanf("%d", &lenth);


	//循环的方式向最后的位置添加元素
	for (int i = 0; i < lenth; i++)
	{
		printf("请输入要添加的第%d个数字\n", i+1);
		add(L);
	}
	printf("添加成功\n");
	//添加完后等待继续
	system("pause");
	//清屏
	system("cls");
	printf("添加成功链表如下\n");
	p = L->next;
	//循环的方式显示每一个元素
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	//-------------------------------------------------------------------------------------------------------------

	/*  操作区，（使用时可删除此注释）    */



	//-------------------------------------------------------------------------------------------------------------
	//显示完成操作后的链表
	p = L->next;
	printf("删除成功\n");
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	system("pause");
	return 0;
}