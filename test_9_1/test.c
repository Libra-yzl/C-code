#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//	int n = 0;
//	scanf("%d", &n);
//	int i = 0;
//	int arr[200] = { 0 };
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//	return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//	int n = 0;
//	int arr[201] = { 0 };
//	scanf("%d", &n);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		scanf("%d", &arr[i]);
//	}
//	qsort(arr, n, sizeof(arr[0]), cmp);
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

#include <stdio.h>

int main()
{
	int n = 0;
	scanf("%d", &n);
	int i = 0;
	int arr[10] = { 0 };
	for (i = 0; i < n; i++)
	{
		scanf("%x", &arr[i]);
	}
	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	return 0;
}