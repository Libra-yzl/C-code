#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//	char* str[] = { "abc", "abcdef" };
//	int i = 0;
//	char* tmp = str[0];
//	char ret = str[1][2];
//	printf("%c\n", ret);
//	printf("%s\n", tmp);
//	int sz = sizeof(str) / sizeof(str[0]);
//	printf("%d\n", sz);
//	printf("%s\n", str[i + 1]);
//	printf("%c\n", str[1][3]);
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%s\n", str[i]);
//	}*/
//	/*tmp = strstr(str[1], str[0]);
//	printf("%s\n", tmp);*/
//	return 0;
//}

#include <stdio.h>
#include <string.h>

int main()
{
	char* str[4] = { "flow", "flower", "flight", "dog"};
	int sz = sizeof(str) / sizeof(str[0]);
	printf("%d\n", sz);
	int i = 0;
	int flag = 0;
	int len = (int)strlen(str[0]);
	char tmp[5] = { 0 };
	int tmp_sz = len;
	int count = 0;
	int n = 0;
	for (i = 0; i < len; i++)
	{
		int j = 0;
		count++;
		for (j = 1; j < sz; j++)
		{
			if (str[0][i] != str[j][i])
			{
				flag = 1;
				//printf("%s\n%c\n",str[0], str[0][i]);
				break;
			}
		}
		if (0 == flag)
		{
			if (tmp_sz)
			{
				tmp[n] = str[0][i];
				n++;
				tmp_sz--;
			}
		}
	}
	if (1 == flag)
	{
		//int i = 0;
		for (i = 0; i < count; i++)
		{
			printf("%c", tmp[i]);
		}
	}
	return 0;
}