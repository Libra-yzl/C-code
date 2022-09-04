#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//    int i = 0;
//    int flag = 1;
//    int nums[23] = { 0 };
//    int left = 0;
//    int right = 0;
//    int j = 0;
//    scanf("%d %d", &left, &right);
//    for (i = left; i <= right; i++)
//    {
//        int tmp = i;
//        while (1)
//        {
//            tmp %= 10;
//            if (tmp == 0)
//            {
//                flag = 2;
//                break;
//            }
//            else
//                break;
//        }
//        if (2 == flag)
//        {
//            flag = 1;
//            continue;
//        }
//        tmp = i;
//        while (tmp % 10 != 0)
//        {
//            if (i % (tmp%10) != 0)
//            {
//                flag = 0;
//                break;
//            }
//            tmp /= 10;
//            if (tmp == 0)
//                break;
//        }
//        if (0 == flag)
//            nums[j++] = i;
//
//    }
//    for (i = 0; i < right - left; i++)
//    {
//        printf("%d ", nums[i]);
//    }
//	return 0;
//}  

//err

