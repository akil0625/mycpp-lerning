//����Ļ������ͷ�ļ�
#include <stdio.h>
//����ռ��ͷ�ļ� �� malloc
#include <stdlib.h>

#define INITSIZE 10

typedef struct{
	int* data;
	int maxsize;
	int lenth;
}SqList;

//����
void init(SqList* p)
{
	(*p).lenth = 0;
	(*p).maxsize = INITSIZE;
	(*p).data = (int*)malloc(sizeof(int) * INITSIZE);

	for (int i = 0; i < INITSIZE; i++)
	{
		(*p).data[i] = 0;
	}

}

//����
void add(SqList* p, int e)
{
	if ((*p).lenth == (*p).maxsize)
	{
		printf("����\n");
		return;
	}
		


	(*p).data[(*p).lenth] = e;
	(*p).lenth++;
}

void insert(SqList* p, int  po, int e)
{
	po--;
	if (po > -1 && po <= (*p).lenth)
	{
		for (int i = (*p).lenth; i > po; i--)
		{
			(*p).data[i] = (*p).data[i-1];
		}
		(*p).data[po] = e;
		(*p).lenth++;
	}
}



//ɾ��
void  del(SqList* p, int po, int* a)
{
	po--;
	if (po<(*p).lenth && po>-1)
	{
		*a = (*p).data[po];
		for (int i = po; i < (*p).lenth - 1; i++)
		{
			(*p).data[i] = (*p).data[i + 1];
		}
		(*p).lenth--;
		return;
	}
	printf("ɾ��ʧ��\n");
}


//����
void search(SqList p, int e, int* po)
{
	for (int i = 0; i < p.lenth; i++)
	{
		if (p.data[i] == e)
		{
			*po = i + 1;
			return;
		}
	}
	printf("δ�ҵ���Ԫ��\n");
}

void searchbypo(SqList p, int po, int* a)
{
	po--;
	if (po < p.lenth && po >= 1)
	{
		*a = p.data[po];
		return;
	}
	printf("������\n");
}




//�������
int main()
{
	//����
	SqList L;


	//��ʼ��
	init(&L);


	//����
	insert(&L, 1, 1);
	insert(&L, 2, 1);
	insert(&L, 3, 5);
	insert(&L, 1, 6);
	insert(&L, 3, 7);



	int a;

	//ɾ��
	//del(&L,2,&a);


	
	//����
	//search(L, 9, &a);

	searchbypo(L, 2, &a);
	printf("a = %d\n", a);







	printf("λ��:\n");
	for (int i = 0; i < INITSIZE; i++)
	{
		printf("%d |", i+1);
	}
	printf("\n");
	printf("���Ա�:\n");
	//������ɺ��ӡ����length������
	for (int i = 0; i < L.lenth; i++)
	{
		printf("%d |", L.data[i]);
	}
	//����
	printf("\n");
	printf("˳���:\n");
	//��ӡ������
	for (int i = 0; i < INITSIZE; i++)
	{
		printf("%d |", L.data[i]);
	}


	//����ִ�е���λ��ֹͣ �����������
	system("pause");
	return 0;
}