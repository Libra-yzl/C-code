#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	int a[4] = { 1,2,3,4 };
//	int sz = sizeof(a) / sizeof(a[0]);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		int b = a[3];
//		printf("%d ", a[i]);
//	}
//	return 0;
//}


#include <stdio.h>

//int dominantIndex(int* nums, int numsSize) {
//    if (numsSize == 1)
//        return 0;
//    int index = 0;
//    int max_max = *nums;
//    int max_min = *(nums + 1);
//    if (max_max < max_min)
//    {
//        int tmp = max_max;
//        max_max = max_min;
//        max_min = tmp;
//        index = 1;
//    }
//    int i = 0;
//    for (i = 2; i < numsSize; i++)
//    {
//        if (nums[i] > max_max)
//        {
//            max_max = nums[i];
//            index = i;
//        }
//        if (nums[i] > max_min && nums[i] < max_max)
//        {
//            max_min = nums[i];
//        }
//    }
//    if (max_min == 0 && max_max != 0)
//    {
//        return index;
//    }
//    if (max_max == 2 * max_min)
//    {
//        return index;
//    }
//    else
//        return -1;
//}

//int dominantIndex(int* nums, int numsSize) {
    //if (numsSize == 1) return 0;//�������ֻ��һ��Ԫ�������⴦��
    //int max, sec, idx;
    ////�ȶ����ʹδ����ѡ��ֵ��ע��max��sec�������⸳��ֵ����Ϊ�п����㸳��ĳ�ֵ�������ֵ
    ////���Ҫʹ�������е����ݽ��г�ֵ���衣
    //if (nums[0] > nums[1]) {
    //    max = nums[0];
    //    idx = 0;
    //    sec = nums[1];
    //}
    //else {
    //    max = nums[1];
    //    idx = 1;
    //    sec = nums[0];
    //} 
    //for (int i = 2; i < numsSize; i++) {
    //    if (nums[i] > max) { //��ǰԪ�ش���max������ζ��Ҫ�滻
    //        sec = max; //�Ƚ�ԭ�����ı��浽sec�У��������Ǵδ��
    //        max = nums[i]; //�ٽ����ķŵ�max��
    //        idx = i; //����maxֵ���±�
    //    }
    //    else if (nums[i] > sec) {
    //        //����պ�nums[0]���������������Ϊ���л��������´δ��޷��ж����
    //        sec = nums[i];
    //    }
    //} 
    //if(max >= sec * 2) {
    //    return idx;
    //} 
    //return - 1;
    // 
    // 
    // 
    // 
//    if (numsSize == 1)
//        return 0;
//    int max_max = *nums;
//    int max_min = *(nums + 1);
//    int index = 0; //�±�Ϊ0
//    if (max_max < max_min)
//    {
//        int tmp = max_max;
//        max_max = max_min;
//        max_min = tmp;
//        index = 1; //���������Ԫ�ص��±�Ϊ1
//    }
//    int i = 0;
//    for (i = 2; i < numsSize; i++)
//    {
//        if (nums[i] > max_max)
//        {
//            max_min = max_max; //�ҵ��δ��Ԫ��
//            max_max = nums[i];
//            index = i;
//        }
//        else if (nums[i] > max_min) //��ֹ�±�Ϊ1��0��Ԫ����󣬴Ӷ�����ѭ��
//        {
//            max_min = nums[i];
//        }
//    }
//    if (max_max >= 2 * max_min)
//    {
//        return index;
//    }
//    else
//        return -1;
//}

//int main()
//{
//    int nums[4] = { 0,0,0,1 };
//    int sz = sizeof(nums) / sizeof(nums[0]);
//    int ret = dominantIndex(nums, sz);
//    printf("%d\n", ret);
//	return 0;
//}
//
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    int i = 0;
//    static int arr[10000] = { 0 };
//    for (i = 0; i < nums1Size; i++) {
//        for (j = 0; j < nums2Size; j++) {
//            if (nums2[j] == nums1[i]) break;//�ж�nums1[i] �Ƿ���nums2������
//        }
//        if (j == nums2Size) {// nums1��iλ�õ�������nums2�����в����ڣ���ǽ�������
//            continue;
//        } /
//            /ֻ������һ�������д��ڵ����ݲ������������ж��Ƿ��Ѿ�����ӵ�����������
//            for (j = 0; j < *returnSize; j++) {
//                if (nums1[i] == arr[j]) break;//�ж�nums1[i] �Ƿ��� arr �������������
//            }
//        if (j == *returnSize) {//���ڷ��������У�����ӵ�����������
//            arr[*returnSize] = nums1[i];
//            *returnSize += 1;
//        }
//    }
//    return arr;
//}

//#include <stdio.h>
//
//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
//    int i = 0;
//    int j = 0;
//    static int arr[10000] = { 0 };
//    for (i = 0; i < nums1Size; i++)
//    {
//        for (j = 0; j < nums2Size; j++)
//        {
//            if (nums2[j] == nums1[i])
//                break;//�ж�nums1[i] �Ƿ���nums2������
//        }
//        if (j == nums2Size)
//        {// nums1��iλ�õ�������nums2�����в����ڣ���ǽ�������
//            continue;
//        }
//        //ֻ������һ�������д��ڵ����ݲ������������ж��Ƿ��Ѿ�����ӵ�����������
//        for (j = 0; j < *returnSize; j++)
//        {
//            if (nums1[i] == arr[j])
//                break;//�ж�nums1[i] �Ƿ��� arr �������������
//        }
//        if (j == *returnSize)
//        {//���ڷ��������У�����ӵ�����������
//            arr[*returnSize] = nums1[i];
//            *returnSize += 1;
//        }
//    }
//    return arr;
//}
//
//int main()
//{
//
//    return 0;
//}

#include <stdio.h>

//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    int i = 0;
//    int j = 0;
//    static arr[1000];
//    for (i = 0; i < nums1Size; i++)
//    {
//        for (j = 0; j < nums2Size; j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                //�ҵ���ͬ��Ԫ��
//                break;
//            }
//        }
//        //���j == nums2Sizeʱ����û����ͬ��Ԫ�أ���������ѭ��
//        if (j == nums2Size)
//        {
//            continue;
//        }
//        //�ж��ҵ�����ͬ��Ԫ���Ƿ��ظ�
//        for (j = 0; j < *returnSize; j++)
//        {
//            if (nums1[i] == arr[i])
//            {
//                break;
//            }
//        }
//        if (j == *returnSize)
//        {
//            arr[*returnSize] = nums1[i];
//            (* returnSize)++;
//        }
//    }
//    return arr;
//}

//int* intersection(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
//{
//    *returnSize = 0;  //��Ԫ�ظ�����Ϊ0���ɹ��ҵ�һ��Ԫ�ؼ�1
//    int i = 0;
//    int j = 0;
//    static int arr[1000];
//    for (i = 0; i < nums1Size; i++)
//    {
//        for (j = 0; j < nums2Size; j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                //�ҵ���ͬ��Ԫ��
//                break;
//            }
//        }
//        //���j == nums2Sizeʱ��û���ҵ���ͬ��Ԫ�أ�ֹͣ����ѭ�������������������ж�
//        if (j == nums2Size)
//        {
//            continue;
//        }
//        //�ж��ҵ�����ͬ��Ԫ���Ƿ��ظ�
//        for (j = 0; j < *returnSize; j++)
//        {
//            if (nums1[i] == arr[j])
//            {
//                break;
//            }
//        }
//        if (j == *returnSize)
//        {
//            arr[*returnSize] = nums1[i];
//            (*returnSize)++;
//        }
//    }
//    return arr;
//}
//
//int main()
//{
//    return 0;
//}