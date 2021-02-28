#define _CRT_SECURE_NO_WARNINGS 1
//柔性数组是结构体最后一个元素，是大小未知的数组，数组的大小是可以调整的
#include<stdio.h>
#include<errno.h>
//struct S
//{
//	int n;
//	int arr[];
//	//int arr[0];
//};
//int main(void)
//{
//	//struct S s;
//	//printf("%d\n", sizeof(s));//计算结构体大小时柔性数组成员不计算在内
//	struct S* ps = malloc(sizeof(struct S) + 5 * sizeof(int)); 
//	if (ps == NULL)
//	{
//		printf("%s\n", strerror(errno));
//	}
//
//	ps->n = 100;
//	int i = 0;
//
//	for (i = 0; i < 5; i++)
//	{
//		ps->arr[i] = i;
//	}
//	//调整大小
//	struct S* ptr = realloc(ps, 44);
//	if (ptr != NULL)
//	{
//		ps = ptr;
//	}
//
//	for (i = 5; i < 10; i++)
//	{
//		ps->arr[i] = i;
//	}
//	for (i = 0; i < 10; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//
//	free(ps);
//	ps = NULL;
//	return 0;
//}

//此法也可达到柔性数组相同功能，数组大小可大可小
//相比较而言，柔性数组的优点：柔性数值只需malloc一次，也只需要free一次，而且产生的内存碎片也更少，内存利用率也更高，开辟的内存空间也是连续的，访问效率也较高
struct S
{
	int n;
	int* arr;
};
int main(void)
{
	struct S* ps = (struct S*)malloc(sizeof(struct S));
	ps->arr = malloc(5 * sizeof(int));

	int i = 0;
	for (i = 0; i < 5; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 5; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//调整大小
	int* ptr = realloc(ps->arr, 10 * sizeof(int));
	if (ptr != NULL)
	{
		ps->arr = ptr;
	}
	for (i = 5; i < 10; i++)
	{
		ps->arr[i] = i;
	}
	for (i = 0; i < 10; i++)
	{
		printf("%d ", ps->arr[i]);
	}
	//释放内存，顺序不可颠倒
	free(ps->arr);
	free(ps);
	return 0;
}