#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>

//int check_sys()
//{
//	union Un
//	{
//		char c;
//		int i;
//	};
//	union Un u = { .i = 1 };;
//	return u.c;
//}

//int check_sys()
//{
//	int a = 1;
//	/*char* tmp = (char*)&a;
//	return *tmp;*/
//	return *(char*)&a;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (1 == ret)
//		printf("Ð¡¶Ë\n");
//	else
//		printf("´ó¶Ë\n");
//	return 0;
//}

#include <stdio.h>
#include <stdlib.h>

int main()
{
	int* p = malloc(10 * sizeof(int));
	//int* ptr = p;
	if (p == NULL)
	{
		perror("mallocc:");
		return 1;
	}

	for (int i = 0; i < 10; i++)
	{
		*(p + i) = i;
	}

	for (int i = 0; i < 10; i++)
	{
		printf("%d ", *(p + i));
	}

	free(p);
	p = NULL;
	return 0;
}