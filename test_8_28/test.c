#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <string.h>

int main() 
{
    //*returnSize = 2;
    char solution[] = "BRBB";
    char guess[] = "RBGY";
    int arr[2] = { 0 };
    int len = (int)strlen(solution);
    int i = 0;
    for (i = 0; i < len; i++)
    {
        if (solution[i] == guess[i])
        {
            arr[0] += 1;
        }
        //int j = 0;
        //for (j = 0; j < len; j++)
        //{

        //    //if (i == j)
        //    //{
        //    //    if (solution[i] == guess[j])
        //    //    {
        //    //        arr[1] += 1;
        //    //        /*if (arr[1] > 1)
        //    //        {
        //    //            arr[1]--;
        //    //        }*/
        //    //    }
        //    //}
        //    //else
        //    //{
        //    //    if (solution[i] == guess[j] && solution[i] != solution[j])
        //    //    {
        //    //        arr[1] += 1;
        //    //        //if (solution[i] == guess[j])
        //    //        //{
        //    //        //    arr[1] += 1;
        //    //        //    /*if (arr[1] > 1)
        //    //        //    {
        //    //        //        arr[1]--;
        //    //        //    }*/
        //    //        //}
        //    //    }
        //    //}
        //}
    }
    int i = 0;
    char tmp[4] = { 0 };
    for (i = 0; i < len; i++)
    {
        int j = 0;
        for (j = 0; j < len; j++)
        {
            if (i != j && solution[i] == solution[j])
            {
                break;
            }
            tmp[i] = solution[i];
            if (tmp[i] == guess[i])
        }
    }
    printf("%d %d\n", arr[0], arr[1]);
    return 0;
}

//int main()
//{
//
//	return 0;
//}

int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
    // write code here
    int* arr = (int*)calloc(2, sizeof(int));
    int i = 0;
    for (i = 0; i < numbersLen; i++)
    {
        if (numbers[i] > target)
            continue;
        int j = 0;
        for (j = i + 1; j < numbersLen; j++)
        {
            if (numbers[i] + numbers[j] == target)
            {
                arr[0] = i + 1;
                arr[1] = j + 1;
                return arr;
            }
        }
    }
    /**returnSize = 0;
    return NULL;*/
}

//int* twoSum(int* numbers, int numbersLen, int target, int* returnSize) {
//    *returnSize = 2;
//    static ret_arr[2] = { 0 };
//    memset(ret_arr, 0x00, sizeof(ret_arr));//静态空间不会二次初始化，因此手动初始化
//    for (int i = 0; i < numbersLen; i++) 
//    {//从第0个位置开始一个一个数字找
//        for (int j = i + 1; j < numbersLen; j++) 
//        {//从第一个数字往后的数字中找出另一个数字
//            //与numbers[i]相加等于target的数字找到了则i和j就是对应两个数字下标
//            if (numbers[i] + numbers[j] == target) 
//            {
//                ret_arr[0] = i + 1;//题目要求下标从1开始
//                ret_arr[1] = j + 1;
//                return ret_arr;
//            }
//        }
//    } 
//    *returnSize = 0;//没有符合的下标则返回数组大小为0；
//    return NULL;
//}