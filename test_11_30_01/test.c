#include <stdio.h>
#include <stdlib.h>


//���Ľṹ��
typedef struct Node//���
{
	//Я������
	int val;
	//ָ����һ�����
	struct Node* next;
}Node;


//��ʼ��
void initlist(Node** h)
{
	//��ͷ�������ڴ�
	*h = (Node*)malloc(sizeof(Node));
	//����Ϊ��
	(*h)->next = NULL;
}

//����
void insert(Node* h, int po, int elm)
{

	Node* p = h;
	//��ʱָ��
	Node* tmp;

	//����ΪI
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
	//��ʱָ��
	Node* tmp;

	//����ΪI
	int i = 0;

	//����λ��
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
	printf("ɾ���ɹ�\n");

}



//��λ��
void sreach(Node* h, int po, int* a)
{
	Node* p = h;

	//����ΪI
	int i = 1;

	//����λ��
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
	
	//����     ����ռ䵱��ͷ��
	Node* L;

	//��ʼ��ͷָ��
	initlist(&L);

	//����
	insert(L,1,4);

	//ɾ��
	del(L,1);

	//��ѯ
	
	int a;

	//��λ��
	sreach(L, 1, &a);


	printf("%d\n", a);

	//��Ԫ��
	//search��);





	system("pause");
	return 0;
}