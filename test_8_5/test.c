#define _CRT_SECURE_NO_WARNINGS 1
//��Ŀ��
//����һ���������飬ʵ��һ��������
//�����������������ֵ�˳��ʹ�����������е�����λ�������ǰ�벿�֣�
//����ż��λ������ĺ�벿��

//#include <stdio.h>
//#include <assert.h>
//#include <string.h>
//
//void odd(int* arr,int sz)
//{
//	assert(arr);//����  --�ж��Ƿ�Ϊ��
//	int* left = arr;
//	int* right =arr + sz - 1;
//	while (left <= right)
//	{
//		if (*left % 2 == 0)
//		{
//			int tmp = *left;
//			*left = *right;
//			*right = tmp;
//			continue;
//		}
//		left++;
//		right--;
//	}
//	/*int i = 0;*/
//	/*int j = 0;
//	for (i = 0; i < sz/2; i++)
//	{
//		int flag = 1;
//		for (j = 0; j < sz - 1 - i; j++)
//		{
//			if (arr[j] > arr[j + 1])
//			{
//				int tmp = arr[j];
//				arr[j] = arr[j + 1];
//				arr[j + 1] = tmp;
//				flag = 0;
//			}
//		}
//		if (1 == flag)
//			break;
//	}*/
//	/*for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}*/
//}
//int main()
//{
//	int arr[] = { 1,2,3,4,5,6,7,8,9,10 };
//	int sz = sizeof(arr) / sizeof(arr[0]);
//	odd(arr,sz);
//	int i = 0;
//	for (i = 0; i < sz; i++)
//	{
//		printf("%d ", arr[i]);
//	}
//	return 0;
//}

//ģ��ʵ��strccpy����
// 
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//char* my_strcpy(char* det, const char* src)
//{
//	assert(det && src); //���ԣ��ж��Ƿ�Ϊ��ָ��
//	/*while (*src)
//	{
//		*det = *src;
//		det++;
//		src++;
//	}*/
//	//�Ż�
//	char* tmp = det;
//	while (*det++ = *src++)
//	{
//		;
//	}
//	return tmp; //����ֱ�ӷ���det ��Ϊ�����det++�ı���det��ֵ
//	            //��strcpy�����ķ���ֵʱĿ��ռ����ʼλ��
//}
//int main()
//{
//	char arr1[] = "hello bit!";
//	char arr2[] = "**************"; //��ӡ����۲��Ƿ񴫵�'\0'
//	/*strcpy(arr2, arr1);
//	printf("%s\n", arr2);*/
//	my_strcpy(arr2, arr1);
//	printf("%s\n", arr2);
//	return 0;
//}

////ģ��ʵ�ֿ⺯��strlen
//
//#include <stdio.h>
//#include <string.h>
//#include <assert.h>
//
//int my_strlen(const char* str)
//{
//	assert(str);//���ԣ��Ƿ�Ϊ��
//	int ret = 0;
//	while (*str++)
//	{
//		ret++;
//	}
//	return ret;
//}
//int main()
//{
//	char arr[] = "I am a bit person!";
//	int len = (int)strlen(arr);
//	int ret_len = my_strlen(arr);
//	printf("%d\n", len);
//	printf("%d\n", ret_len);
//	return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    int arr[50];
//    int n = 0;
//    int flag1 = 0;
//    int flag2 = 0;
//    scanf("%d", &n);
//    int i = 0;
//    for (i = 0; i < n; i++)
//    {
//        scanf("%d", &arr[i]);
//    }
//    for (i = 0; i < n - 1 ; i++)
//    {
//        if (arr[i] >= arr[i + 1])
//            flag1 = 1;
//        else if (arr[i] < arr[i + 1])
//            flag2 = 2;
//    }
//    if (flag1 && flag2)
//        printf("unsorted\n");
//    else
//        printf("sorted\n");
//    return 0;
//}

#include <stdio.h>

/*#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int gra[n];
    for (i = 0; i < n; i++)
    {
        scanf("%d", &gra[i]);
    }
    int high = gra[0];
    int low = gra[0];
    for (i = 0; i < n; i++)
    {
        if (gra[i] > high)
            high = gra[i];
        else if (gra[i] < low)
            low = gra[i];
    }
    printf("%d", high - low);
    return 0;
}*/
#include <stdio.h>

int main()
{
    int n = 0;
    scanf("%d", &n);
    int i = 0;
    int k = 0;
    //�ɼ������100�������0����high = 0��������������
    //���ϴ�ֵ����high���high�������ֵ��
    //��֮����low = 100����������Сֵ
    int high = 0;
    int low = 100;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &k);
        if (k > high)
            high = k;
        if (k < low)
            low = k;
    }
    printf("%d", high - low);
    return 0;
}