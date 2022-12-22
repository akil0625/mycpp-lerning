#include <stdio.h>

typedef struct List
{
	int data[10];
	int lenth;
	int maxsize;
}List;

//删除相同元素

void del(List * L)
{
	int i;
	//i从第一个元素遍历到最后一个元素的前一个元素
	for (i = 0; i < L->lenth-1; i++)
	{
		//j从第二个元素遍历到最后一个元素
		for (int j = i + 1;j<L->lenth; j++)
		{
			//j指到与i指向的元素相同的元素时用覆盖法删除该元素
			if (L->data[i] == L->data[j])
			{
				//令k等于j，再从第k个位置开始向前覆盖
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

	del(&list);//删除重复数字
	
	for(i = 0; i < list.lenth; i++)
	{
		printf("%d", list.data[i]);
	}
	system("pause");
	return 0;
}

