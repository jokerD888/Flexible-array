#define _CRT_SECURE_NO_WARNINGS 1
//���������ǽṹ�����һ��Ԫ�أ��Ǵ�Сδ֪�����飬����Ĵ�С�ǿ��Ե�����
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
//	//printf("%d\n", sizeof(s));//����ṹ���Сʱ���������Ա����������
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
//	//������С
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

//�˷�Ҳ�ɴﵽ����������ͬ���ܣ������С�ɴ��С
//��Ƚ϶��ԣ�����������ŵ㣺������ֵֻ��mallocһ�Σ�Ҳֻ��Ҫfreeһ�Σ����Ҳ������ڴ���ƬҲ���٣��ڴ�������Ҳ���ߣ����ٵ��ڴ�ռ�Ҳ�������ģ�����Ч��Ҳ�ϸ�
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
	//������С
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
	//�ͷ��ڴ棬˳�򲻿ɵߵ�
	free(ps->arr);
	free(ps);
	return 0;
}