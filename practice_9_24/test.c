#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//struct A
//{
//	int a;
//	short b;
//	int c;
//	char d;
//};
//struct B
//{
//	int a;
//	short b;
//	char c;
//	int d;
//};
//
//int main()
//{
//	/*struct A s1;
//	struct B s2;*/
//	printf("%zu %zu", sizeof(struct A), sizeof(struct B));
//	return 0;
//}

//#pragma pack(4)/*编译选项，表示4字节对齐 平台：VS2013。语言：C语言*/
//#include <stdio.h>
//
//int main(int argc, char* argv[])
//{
//    struct tagTest1
//    {
//        short a;
//        char d;
//        long b;
//        long c;
//    };
//    struct tagTest2
//    {
//        long b;
//        short c;
//        char d;
//        long a;
//    };
//    struct tagTest3
//    {
//        short c;
//        long b;
//        char d;
//        long a;
//    };
//    struct tagTest1 stT1;
//    struct tagTest2 stT2;
//    struct tagTest3 stT3;
//
//    printf("%zd %zd %zd", sizeof(stT1), sizeof(stT2), sizeof(stT3));
//    return 0;
//}
//#pragma pack()

//#include <stdio.h>
//
//typedef struct {
//	int a;
//	char b;
//	short c;
//	short d;
//}AA_t;
//
//int main()
//{
//	printf("%zu\n", sizeof(AA_t));
//	return 0;
//}

//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[10] = {0};
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    qsort(arr, n, sizeof(arr[0]), cmp);
//    for (i = 1; i < n; i++)
//    {
//        if (arr[i - 1] == arr[i])
//        {
//            continue;
//        }
//        printf("%d ", arr[i - 1]);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    while (scanf("%d", &n) != EOF)
//    {
//        int i = 0;
//        for (i = 0; i < n; i++)
//        {
//            //打印空格
//            int j = 0;
//            for (j = 0; j < n - i - 1; j++)
//            {
//                printf("  ");
//            }
//            //打印*
//            for (j = 0; j <= i; j++)
//            {
//                printf("* ");
//            }
//            printf("\n");
//        }
//    }
//    return 0;
//}