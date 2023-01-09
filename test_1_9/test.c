#define _CRT_SECURE_NO_WARNINGS 1

#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

int main()
{

    return 0;
}

void reverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k) {
    k %= numsSize;
    // while (k)
    // {
    //     int j = 0;
    //     int tmp = nums[numsSize - 1];
    //     for (j = numsSize - 1; j > 0; j--)
    //     {
    //         nums[j] = nums[j - 1];
    //     }
    //     nums[0] = tmp;
    //     k--;
    // } //时间复杂度过大

    //翻转数组
    int i = 0;
    //翻转
    for (i = 0; i < numsSize / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }
    for (i = 0; i < k / 2; i++)
    {
        int tmp = nums[i];
        nums[i] = nums[k - 1 - i];
        nums[k - 1 - i] = tmp;
    }
    for (i = 0; i < (numsSize - k) / 2; i++)
    {
        int tmp = nums[i + k];
        nums[i + k] = nums[numsSize - 1 - i];
        nums[numsSize - 1 - i] = tmp;
    }

    // //以空间换时间
    // //创建一个数组临时存放
    // int tmp[numsSize];
    // //后k个元素
    // int i = 0;
    // int j = 0;
    // for (i = numsSize - k; i < numsSize; i++)
    // {
    //     tmp[j] = nums[i];
    //     j++;
    // }
    // //前n-k个元素
    // for (i = 0; i < numsSize - k; i++)
    // {
    //     tmp[j] = nums[i];
    //     j++;
    // }
    // //将数组重新放回原数组
    // for (i = 0; i < numsSize; i++)
    // {
    //     nums[i] = tmp[i];
    // }

    // //三步逆置 -- 函数法
    // //逆置后n-k个元素
    // reverse(nums, numsSize - k, numsSize - 1);
    // //逆置前k个元素
    // reverse(nums, 0, numsSize - k - 1);
    // //整体逆置
    // reverse(nums,0, numsSize - 1);
}

// void rotate(int* nums, int numsSize, int k)
// {
//     //用空间换时间
//     //时间复杂度 O(N)
//     //空间复杂度 O(N)

//     k %= numsSize;
//     int tmp[numsSize];
//     //后k个元素移动到前面
//     int j = 0;
//     for (int i = numsSize - k; i < numsSize; i++)
//     {
//         tmp[j++] = nums[i];
//     }
//     //前n-k个元素移动到后面
//     for (int i = 0; i < numsSize - k; i++)
//     {
//         tmp[j++] = nums[i];
//     }
//     //将临时数组重新放回原数组中
//     for (int i = 0; i < numsSize; i++)
//     {
//         nums[i] = tmp[i];
//     }
// }

//逆置函数
void reverse(int* nums, int begin, int end)
{
    while (begin < end)
    {
        int tmp = nums[begin];
        nums[begin] = nums[end];
        nums[end] = tmp;
        begin++;
        end--;
    }
}

void rotate(int* nums, int numsSize, int k)
{
    //三步逆置法
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}