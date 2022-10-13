#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//#include <stdlib.h>
//
//int main()
//{
//	//int*p = (int*)malloc(INT_MAX + 1);
//	int* p = (int*)calloc(40, sizeof(int));
//	int i = 0;
//	if (p == NULL)
//	{
//		perror("malloc");
//		return 1;
//	}
//	int* ptr = realloc(p, 80);
//	if (ptr != NULL)
//	{
//		p = ptr;
//		ptr = NULL;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		*(p + i) = i;
//	}
//	for (i = 0; i < 20; i++)
//	{
//		printf("%d ", *(p + i));
//	}
//	free(p);
//	p = NULL;
//	return 0;
//}
