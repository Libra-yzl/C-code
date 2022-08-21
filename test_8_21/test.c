#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//
//int compare_str(const void* e1, const void* e2)
//{
//    return *(char*)e1 - *(char*)e2;
//}
//
//int main()
//{
//    //int n = 0;
//    char str[1001] = {0};
//    scanf("%s", str);
//    int len = (int)strlen(str);
//    qsort(str, len, sizeof(char), compare_str);
//    printf("%s\n", str);
//    return 0;
//}


//#include <stdio.h>
//#include <string.h>
//
//int main()
//{
//    char str[1001] = { 0 };
//    scanf("%s", str);
//    int len = (int)strlen(str);
//    int i = 0;
//    for (i = 0; i < len - 1; i++)
//    {
//        int flag = 1;
//        int j = 0;
//        for (j = 0; j < len - 1 - i; j++)
//        {
//            if (str[j] > str[j + 1])
//            {
//                char tmp = str[j];
//                str[j] = str[j + 1];
//                str[j + 1] = tmp;
//                flag = 0;
//            }
//        }
//        if (1 == flag)
//        {
//            break;
//        }
//    }
//    printf("%s", str);
//    return 0;
//}

#include <stdio.h>

int pivotIndex(int* nums, int numsSize) {
	int i, j;
	for (i = 0; i < numsSize; i++) 
	{//�Ӽ������ĵ�Ϊ0��ʼ����ͳ���ж�
		int l_sum = 0;
		int r_sum = 0;//��ʼ�����֮�ͺ��ұ�֮��Ϊ0
		for (j = 0; j < numsSize; j++)
		{
			if (j < i) 
				l_sum += nums[j]; //С��i����Ķ�����ߵ�����
			else if (j > i) 
				r_sum += nums[j];//����i����Ķ����ұߵ�����
		} 
		if(l_sum == r_sum) 
		{//������������i������������
			return i;
		}
	} 
	return - 1;
}

int main()
{
	int nums[6] = { 1,1,-1,1,-1,-1 };
	int numsSize = sizeof(nums) / sizeof(nums[0]);
	int ret = pivotIndex(nums, numsSize);
	printf("ret = %d\n", ret);
	return 0;
}