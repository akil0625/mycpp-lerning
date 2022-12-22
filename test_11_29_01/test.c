//与屏幕交互的头文件
#include <stdio.h>
//管理空间的头文件 如 malloc
#include <stdlib.h>

#define INITSIZE 10

typedef struct{
	int* data;
	int maxsize;
	int lenth;
}SqList;

//定义
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

//定义
void add(SqList* p, int e)
{
	if ((*p).lenth == (*p).maxsize)
	{
		printf("满了\n");
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



//删除
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
	printf("删除失败\n");
}


//查找
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
	printf("未找到该元素\n");
}

void searchbypo(SqList p, int po, int* a)
{
	po--;
	if (po < p.lenth && po >= 1)
	{
		*a = p.data[po];
		return;
	}
	printf("不存在\n");
}




//程序入口
int main()
{
	//创建
	SqList L;


	//初始化
	init(&L);


	//插入
	insert(&L, 1, 1);
	insert(&L, 2, 1);
	insert(&L, 3, 5);
	insert(&L, 1, 6);
	insert(&L, 3, 7);



	int a;

	//删除
	//del(&L,2,&a);


	
	//查找
	//search(L, 9, &a);

	searchbypo(L, 2, &a);
	printf("a = %d\n", a);







	printf("位序:\n");
	for (int i = 0; i < INITSIZE; i++)
	{
		printf("%d |", i+1);
	}
	printf("\n");
	printf("线性表:\n");
	//操作完成后打印到第length个数据
	for (int i = 0; i < L.lenth; i++)
	{
		printf("%d |", L.data[i]);
	}
	//换行
	printf("\n");
	printf("顺序表:\n");
	//打印整个表
	for (int i = 0; i < INITSIZE; i++)
	{
		printf("%d |", L.data[i]);
	}


	//程序执行到此位置停止 按任意键继续
	system("pause");
	return 0;
}