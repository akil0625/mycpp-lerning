//���ξ���
#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <windows.h>

//���ṹ��
typedef struct Node
{

	int val;
	struct Node* next;

}Node;

//��ӽڵ�ĺ���
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
  /* ������ */

//---------------------------------------------------------------
//������
int main()
{
	//��������ͷ���
	Node* L = (Node*)malloc(sizeof(Node));
	L->next = NULL;
	Node* p;

	int lenth = 0;
	printf("������Ҫ����������Ӷ��ٸ�Ԫ��\n");
	scanf("%d", &lenth);


	//ѭ���ķ�ʽ������λ�����Ԫ��
	for (int i = 0; i < lenth; i++)
	{
		printf("������Ҫ��ӵĵ�%d������\n", i+1);
		add(L);
	}
	printf("��ӳɹ�\n");
	//������ȴ�����
	system("pause");
	//����
	system("cls");
	printf("��ӳɹ���������\n");
	p = L->next;
	//ѭ���ķ�ʽ��ʾÿһ��Ԫ��
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	//-------------------------------------------------------------------------------------------------------------

	/*  ����������ʹ��ʱ��ɾ����ע�ͣ�    */



	//-------------------------------------------------------------------------------------------------------------
	//��ʾ��ɲ����������
	p = L->next;
	printf("ɾ���ɹ�\n");
	while (p != NULL)
	{
		printf("%d ", p->val);
		p = p->next;
	}
	printf("\n");
	system("pause");
	return 0;
}