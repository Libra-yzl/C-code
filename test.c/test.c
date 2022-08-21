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
    //if (numsSize == 1) return 0;//特殊情况只有一个元素则特殊处理
    //int max, sec, idx;
    ////先对最大和次大进行选择赋值，注意max和sec不能随意赋初值，因为有可能你赋予的初值就是最大值
    ////因此要使用数组中的数据进行初值赋予。
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
    //    if (nums[i] > max) { //当前元素大于max，则意味着要替换
    //        sec = max; //先将原先最大的保存到sec中，则他就是次大的
    //        max = nums[i]; //再将最大的放到max中
    //        idx = i; //保存max值的下标
    //    }
    //    else if (nums[i] > sec) {
    //        //避免刚好nums[0]就是最大的情况，因为不切换最大而导致次大无法判断情况
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
//    int index = 0; //下标为0
//    if (max_max < max_min)
//    {
//        int tmp = max_max;
//        max_max = max_min;
//        max_min = tmp;
//        index = 1; //交换后最大元素的下标为1
//    }
//    int i = 0;
//    for (i = 2; i < numsSize; i++)
//    {
//        if (nums[i] > max_max)
//        {
//            max_min = max_max; //找到次大的元素
//            max_max = nums[i];
//            index = i;
//        }
//        else if (nums[i] > max_min) //防止下标为1或0的元素最大，从而不进循环
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
//            if (nums2[j] == nums1[i]) break;//判断nums1[i] 是否在nums2数组中
//        }
//        if (j == nums2Size) {// nums1中i位置的数据在nums2数组中不存在，则非交集数据
//            continue;
//        } /
//            /只有在另一个数组中存在的数据才能走下来，判断是否已经被添加到返回数组中
//            for (j = 0; j < *returnSize; j++) {
//                if (nums1[i] == arr[j]) break;//判断nums1[i] 是否在 arr 这个返回数组中
//            }
//        if (j == *returnSize) {//不在返回数组中，则添加到返回数组中
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
//                break;//判断nums1[i] 是否在nums2数组中
//        }
//        if (j == nums2Size)
//        {// nums1中i位置的数据在nums2数组中不存在，则非交集数据
//            continue;
//        }
//        //只有在另一个数组中存在的数据才能走下来，判断是否已经被添加到返回数组中
//        for (j = 0; j < *returnSize; j++)
//        {
//            if (nums1[i] == arr[j])
//                break;//判断nums1[i] 是否在 arr 这个返回数组中
//        }
//        if (j == *returnSize)
//        {//不在返回数组中，则添加到返回数组中
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
//                //找到相同的元素
//                break;
//            }
//        }
//        //如果j == nums2Size时，就没有相同的元素，跳出本层循环
//        if (j == nums2Size)
//        {
//            continue;
//        }
//        //判断找到的相同的元素是否重复
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
//    *returnSize = 0;  //将元素个数设为0，成功找到一个元素加1
//    int i = 0;
//    int j = 0;
//    static int arr[1000];
//    for (i = 0; i < nums1Size; i++)
//    {
//        for (j = 0; j < nums2Size; j++)
//        {
//            if (nums1[i] == nums2[j])
//            {
//                //找到相同的元素
//                break;
//            }
//        }
//        //如果j == nums2Size时，没有找到相同的元素，停止本次循环，调整变量，条件判断
//        if (j == nums2Size)
//        {
//            continue;
//        }
//        //判断找到的相同的元素是否重复
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