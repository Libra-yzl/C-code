#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    *returnSize = 0;
//    int i = 0;
//    int nums[10000] = { 0 };
//    for (i = left; i <= right; i++)
//    {
//        int flag = 1;
//        int tmp = i;
//        do
//        {
//            tmp %= 10;
//            if (i % tmp != 0)
//            {
//                flag = 0;
//                break;
//            }
//        } while (tmp /= 10);
//        if (1 == flag)
//        {
//            nums[*returnSize] = i;
//            returnSize++;
//        }
//    }
//    return nums;
//}
//
//int main()
//{
//
//	return 0;
//}

//#include <stdio.h>
//
//int* selfDividingNumbers(int left, int right, int* returnSize)
//{
//    int* ret = (int*)calloc(1000, sizeof(int));//��̬�����㹻��Ŀռ����ڴ�ŷ��ص��Գ���
//    *returnSize = 0;
//    for (int i = left; i <= right; i++)
//    {
//        int num = i;
//        while (num)
//        {
//            int tmp = num % 10;//��������
//            if (tmp == 0 || (i % tmp) != 0)
//            {//�ж�i����������ȡģ�Ƿ�Ϊ0
//                break;
//            }
//            num /= 10;
//        }
//        //���num==0��ʾͨ����ÿһλ����ȡģ�жϣ���i�����Գ���
//        if (0 == num)
//        {
//            ret[(*returnSize)++] = i;
//        }
//        return ret;
//    }
//}
//
//int main()
//{
//
//	return 0;
//}

//int* selfDividingNumbers(int left, int right, int* returnSize) {
//    *returnSize = 0;
//    int i = 0;
//    int* nums = (int*)calloc(1000, sizeof(int));
//    for (i = left; i <= right; i++)
//    {
//        int flag = 1;
//        int tmp = i;
//        while (tmp)
//        {
//            tmp %= 10;
//            if (tmp == 0 || (i % tmp) != 0)
//            {
//                flag = 0;
//                break;
//            }
//            tmp /= 10;
//        }
//        if (1 == flag)
//        {
//            nums[(*returnSize)++] = i;
//        }
//    }
//    return nums;
//}
//
//#include <stdio.h>
//
//int main()
//{
//    
//    return 0;
//}

int* productExceptSelf(int* nums, int numsSize, int* returnSize) 
{
    int* num = (int*)malloc(numsSize * sizeof(int));//�����ڴ�
    *returnSize = numsSize;
    int left = 1;
    int right = 1;
    int i = 0;    //��һ��ѭ����ÿ��Ԫ����ߵ�ֵ�۳�
    for (i = 0; i < numsSize; i++)
    {
        num[i] = left; //��ÿ���۳˵�left������
        left *= nums[i];
    }
    //�ڶ���ѭ����ÿ��Ԫ���ұߵ�ֵ�۳�
    for (i = numsSize - 1; i >= 0; i--)
    {
        num[i] *= right;//���۳˵�right��left��ˣ��õ�������ĳ˻�
        right *= nums[i];
    }
    return num;
}