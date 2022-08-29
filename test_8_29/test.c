#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int fun(int a[], int n)
//{
//	int i, j;
//	j = 0;
//	for (i = 0; i < n; i++)
//	{
//		if (a[i] % 2 == 1)
//		{
//			a[j] = a[i];
//			j++;
//		}
//	}
//	return j;
//}
//
//int main()
//{
//	int a[] = { 4,10,9,3,8,5,4,1,7,6 };
//	int n = sizeof(a) / sizeof(a[0]);
//	int ret = fun(a, n);
//	printf("ret = %d\n", ret);
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[5];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < n; i++)
//    {
//        int count = 1;
//        int j = 0;
//        for (j = i + 1; j < n; j++)
//        {
//            if (arr[i] == arr[j])
//                count++;
//        }
//        if (count % 2 == 1)
//        {
//            printf("%d", count);
//        }
//    }
//    return 0;
//}


//#include <stdio.h>
//#include <stdlib.h>
//
//int cmp(const void* e1, const void* e2)
//{
//    return *(int*)e1 - *(int*)e2;
//}
//
//int main()
//{
//    int n = 0;
//    scanf("%d", &n);
//    int i = 0;
//    int arr[5];
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    qsort(arr, n, sizeof(arr[0]), cmp);
//    for (i = 0; i < n; i++)
//    {
//        int count = 0;
//        int j = 0;
//        //int flag = 1;
//        for (j = i + 1; j < n; j++)
//        {
//            if (arr[i] == arr[j])
//            {
//                //flag = 0;
//                count++;
//            }
//            /*if (arr[i] < arr[j])
//                continue;*/
//        }
//        if (count % 2 == 0)
//        {
//            printf("%d", arr[i]);
//        }
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//	int a = 2;
//	int b = 3;
//	printf("%d", a ^ b);
//	return 0;
//}

