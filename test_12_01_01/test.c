#include <stdio.h>

typedef struct List
{
	int data[10];
	int lenth;
	int maxsize;
}List;

//ɾ����ͬԪ��

void del(List * L)
{
	int i;
	//i�ӵ�һ��Ԫ�ر��������һ��Ԫ�ص�ǰһ��Ԫ��
	for (i = 0; i < L->lenth-1; i++)
	{
		//j�ӵڶ���Ԫ�ر��������һ��Ԫ��
		for (int j = i + 1;j<L->lenth; j++)
		{
			//jָ����iָ���Ԫ����ͬ��Ԫ��ʱ�ø��Ƿ�ɾ����Ԫ��
			if (L->data[i] == L->data[j])
			{
				//��k����j���ٴӵ�k��λ�ÿ�ʼ��ǰ����
				for (int k = j; k < L->lenth-1; k++)
				{
					L->data[k] = L->data[k + 1];
				}
				L->lenth--;
				j--;
			}
		}
	}
};
int main()
{


	int i;

	int x = 7;


	List list;
	list.lenth = 8;
	list.data[0] = 7;
	list.data[1] = 2;
	list.data[2] = 3;
	list.data[3] = 5;
	list.data[4] = 2;
	list.data[5] = 7;
	list.data[6] = 5;
	list.data[7] = 9;

	del(&list);//ɾ���ظ�����
	
	for(i = 0; i < list.lenth; i++)
	{
		printf("%d", list.data[i]);
	}
	system("pause");
	return 0;
}

