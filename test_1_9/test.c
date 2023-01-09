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
    // } //ʱ�临�Ӷȹ���

    //��ת����
    int i = 0;
    //��ת
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

    // //�Կռ任ʱ��
    // //����һ��������ʱ���
    // int tmp[numsSize];
    // //��k��Ԫ��
    // int i = 0;
    // int j = 0;
    // for (i = numsSize - k; i < numsSize; i++)
    // {
    //     tmp[j] = nums[i];
    //     j++;
    // }
    // //ǰn-k��Ԫ��
    // for (i = 0; i < numsSize - k; i++)
    // {
    //     tmp[j] = nums[i];
    //     j++;
    // }
    // //���������·Ż�ԭ����
    // for (i = 0; i < numsSize; i++)
    // {
    //     nums[i] = tmp[i];
    // }

    // //�������� -- ������
    // //���ú�n-k��Ԫ��
    // reverse(nums, numsSize - k, numsSize - 1);
    // //����ǰk��Ԫ��
    // reverse(nums, 0, numsSize - k - 1);
    // //��������
    // reverse(nums,0, numsSize - 1);
}

// void rotate(int* nums, int numsSize, int k)
// {
//     //�ÿռ任ʱ��
//     //ʱ�临�Ӷ� O(N)
//     //�ռ临�Ӷ� O(N)

//     k %= numsSize;
//     int tmp[numsSize];
//     //��k��Ԫ���ƶ���ǰ��
//     int j = 0;
//     for (int i = numsSize - k; i < numsSize; i++)
//     {
//         tmp[j++] = nums[i];
//     }
//     //ǰn-k��Ԫ���ƶ�������
//     for (int i = 0; i < numsSize - k; i++)
//     {
//         tmp[j++] = nums[i];
//     }
//     //����ʱ�������·Ż�ԭ������
//     for (int i = 0; i < numsSize; i++)
//     {
//         nums[i] = tmp[i];
//     }
// }

//���ú���
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
    //�������÷�
    k %= numsSize;
    reverse(nums, 0, numsSize - k - 1);
    reverse(nums, numsSize - k, numsSize - 1);
    reverse(nums, 0, numsSize - 1);
}