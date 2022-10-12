#define _CRT_SECURE_NO_WARNINGS 1


//#include <stdio.h>
//
//enum Option
//{
//	add = 5,
//	del = 7,
//	search,
//	modify,
//	show,
//	sort
//};
//
//int main()
//{
//	enum Option option = add;
//	printf("%d\n", add);
//	printf("%d\n", del);
//	printf("%d\n", search);
//	return 0;
//}

//#include <stdio.h>
//
//int check_sys()
//{
//	union
//	{
//		char c;
//		int i;
//	}u;
//	u.i = 1;
//	return u.c;
//}
//
//int main()
//{
//	int ret = check_sys();
//	if (0 == ret)
//		printf("大端\n");
//	else
//		printf("小端\n");
//	return 0;
//}

//#include<stdio.h>
//int main()
//{
//    union
//    {
//        short k;
//        char i[2];
//    }*s, a;
//    s = &a;
//    s->i[0] = 0x39;
//    s->i[1] = 0x38;
//    printf("%x\n", a.k);
//    return 0;
//}

//一个数组中只有两个数字是出现一次，其他所有数字都出现了两次。

//编写一个函数找出这两个只出现一次的数字。

//#include <stdio.h>
//#include <string.h>
//#include <stdlib.h>
//#include <errno.h>
//
//int main()
//{
//	int* p = (int*)calloc(INT_MAX+ 1, sizeof(int));
//	if (p == NULL)
//	{
//		printf("%s\n", strerror(errno));
//		return 1;
//	}
//	int i = 0;
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