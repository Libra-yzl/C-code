#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <math.h>
//
//int is_prime(int n)
//{
//	int j = 0;
//	for (j = 2; j <= sqrt(n); j++)
//	{
//		if (n % j == 0)
//		{
//			return 0;
//		}
//	}
//	return 1;
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		if (is_prime(i) == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 100; i <= 200; i++)
//	{
//		int j = 0;
//		int flag = 1;
//		for (j = 2; j <= sqrt(i); j++)
//		{
//			if (i % j == 0)
//			{
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//int is_leap(int n)
//{
//	return ((n % 4 == 0) && (n % 100 != 0) || (n % 400) == 0);
//}
//
//int main()
//{
//	int i = 0;
//	int count = 0;
//	for (i = 1000; i <= 2000; i++)
//	{
//		if (is_leap(i) == 1)
//		{
//			count++;
//			printf("%d ", i);
//		}
//	}
//	printf("\ncount = %d\n", count);
//	return 0;
//}

//#include <stdio.h>
//
//int binary_search(int arr[], int k, int sz)
//{
//	int left = 0;
//	int right = sz - 1;
//	while (left <= right)
//	{
//		int mid = left + (right - left) / 2;
//		if (k > arr[mid])
//		{
//			left = mid + 1;
//		}
//		else if (k < arr[mid])
//		{
//			right = mid - 1;
//		}
//		else
//			return mid;
//	}
//	return -1;
//}
//
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	int k = 0;
//	scanf("%d", &k);
//	int ret = binary_search(arr, k, sz);
//	if (-1 == ret)
//	{
//		printf("找不到\n");
//	}
//	else
//	{
//		printf("找到了，下标是%d\n", ret);
//	}
//	return 0;
//}

//#include <stdio.h>
//
//void Add(int* p)
//{
//	(*p)++;
//}
//
//int main()
//{
//	int num = 0;
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	Add(&num);
//	printf("%d\n", num);
//	return 0;
//}

//int GetNumberOfK(int* data, int dataLen, int k) {
//    // write code here
//    int* left = data;
//    int* right = data + dataLen - 1;
//    int count = 0;
//    while (left <= right)
//    {
//        if ((left == right) && ((*left) == (*right)) && ((*left) == k))
//        {
//            count++;
//            break;
//        }
//        if (*left == k)
//        {
//            count++;
//        }
//        if (*right == k)
//        {
//            count++;
//        }
//        left++;
//        right--;
//    }
//    return count;
//}

//int GetNumberOfK(int* data, int dataLen, int k) {
//    // write code here
//    if (dataLen == 0)
//        return dataLen;
//    int l = 0, r = dataLen - 1, m = (l + r) / 2;
//YYY:
//    m = (l + r) / 2;
//    if (data[m] == k)
//        goto ZZZ;
//    data[m] > k ? (r = m - 1) : (l = m + 1);
//    if (l < r)
//        goto YYY;
//ZZZ:
//    if (l >= r && dataLen != 1)
//        return 0;
//    l = 0, r = m - 1;
//VVV:
//    if (data[m] == k)
//        l += 1;
//    else
//        goto A;
//    m++;
//    goto VVV;
//A:
//C:
//    if (data[r] == k)
//        l += 1;
//    else
//        goto B;
//    r -= 1;
//    goto C;
//B:
//    return l;
//}

//int convertInteger(int A, int B) {
//    int i = 0;
//    long flag = 1;
//    int count = 0;
//    for (i = 0; i < 32; i++)
//    {
//        if ((A & flag) != (B & flag))
//        {
//            count++;
//        }
//        flag = flag << 1;
//    }
//    return count;
//}

