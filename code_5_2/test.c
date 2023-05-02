#define _CRT_SECURE_NO_WARNINGS 1


#include "List.h"

void TestLTNode1()
{
	LTNode* phead = BuyLTNode(5);
	phead = InitLTNode(phead);
}



//int main()
//{
//	TestLTNode1();
//	return 0;
//}

#include <stdio.h>

#define N 11

int main()
{
    int n = 0;
    int arr[N+1];
    int pos_count = 0; //正数个数
    int neg_count = 0; //负数个数
    float sum_pos = 0; //正数总和
    //scanf("%d", &n);
    for (int i = 0; i < N; i++)
    {
        scanf("%d", &arr[i]);
    }
    for (int i = 0; i < N; i++)
    {

        if (arr[i] > 0)
        {
            sum_pos += arr[i];
            pos_count++;
        }
        else if (arr[i] < 0)
        {
            neg_count++;
        }
        else
        {
            continue;
        }
    }
    float avg = 0.0;
    if (sum_pos != 0)
    {
        avg = sum_pos / pos_count;
    }
    printf("%d %.1f", neg_count, avg);
    return 0;
}

int minNumberInRotateArray(int* rotateArray, int rotateArrayLen) {
    int left = 0;
    int right = rotateArrayLen - 1;
    while (left < right)
    {
        int mid = left + (right - left) / 2;
        if (rotateArray[mid] > rotateArray[right])
        {
            left = mid + 1;
        }
        else if (rotateArray[mid] < rotateArray[right])
        {
            right = mid;
        }
        else
        {
            right--;
        }
    }
    return rotateArray[left];
}