#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int alp(char n, char m)
//{
//    if ((n >= 'A' && n <= 'Z') || (n >= 'a' && n <= 'z'))
//        return 1;
//    else
//        return -1;
//    if ((m >= 'A' && m <= 'Z') || (m >= 'a' && m <= 'z'))
//        return 2;
//    else
//        return -2;
//}
//int main()
//{
//    char val = 0;
//    char input = 0;
//    scanf("%c", &input);
//    getchar();
//    scanf("%c", &val);
//    int ret = alp(input,val);
//    if (1 == ret)
//        printf("%c is an alphabet.\n", input);
//    if (2 == ret)
//        printf("%c is an alphabet.\n", val);
//    if (-1 == ret)
//        printf("%c is not an alphabet.\n", input);
//    if (-2 == ret)
//        printf("%c is not an alphabet.\n", val);
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    char input = 0;
//    while ((input = getchar()) != EOF)
//    {
//        if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
//            printf("%c is an alphabet.\n", input);
//        else
//            printf("%c is not an alphabet.\n", input);
//        getchar();
//    }
//    return 0;
//}
//#include<stdio.h>
////A-Z == 65-90
////a-z == 97-122
////\n == 10
//int main() {
//    char ar;
//    while (scanf("%c", &ar) != EOF) {
//        if (ar == 10) continue;
//        if (ar >= 65 && ar <= 90 || ar >= 97 && ar <= 122)
//            printf("%c is an alphabet.\n", ar);
//        else printf("%c is not an alphabet.\n", ar);
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    char input = 0;
//    while ((scanf("%c", &input) != EOF))
//    {
//        if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
//            printf("%c is an alphabet.\n", input);
//        else
//            printf("%c is not an alphabet.\n", input);
//        getchar();
//    }
//    return 0;
//}

//#include <stdio.h>
//
//int main()
//{
//    char input = 0;
//    while (scanf("%c", &input) != EOF)
//    {
//        if (input >= 'A' && input <= 'Z')
//        {
//            input += 32;
//            printf("%c\n", input);
//        }
//        else if (input >= 'a' && input <= 'z')
//        {
//            input -= 32;
//            printf("%c\n", input);
//        }
//        getchar();
//    }
//    return 0;
//}
//#include <stdio.h>
//
//int main()
//{
//    double price = 0.0;
//    int month = 0;
//    int date = 0;
//    int flag = 0;
//    double a = price * 0.8 - 50;
//    double b = price * 0.7 - 50;
//    while ((scanf("%lf %d %d %d", &price, &month, &date, &flag)) != EOF)
//    {
//        double a = price * 0.8 - 50;
//        double b = price * 0.7 - 50;
//        if (month == 11 && date == 11)
//        {
//            if (1 == flag)
//            {
//                if (b < 0)
//                {
//                    b = 0.0;
//                }
//                printf("%.2lf\n", b);
//            }
//            else
//                printf("%.2lf\n", b + 50);
//        }
//
//        else if (month == 12 && date == 12)
//        {
//            if (1 == flag)
//            {
//                if (a < 0)
//                {
//                    a = 0.0;
//                }
//                printf("%.2lf\n", a);
//            }
//            else
//                printf("%.2lf\n", a + 50);
//        }
//        else
//            printf("%.2lf\n", price);
//    }
//    return 0;
//}
//����·�����
//#include <stdio.h>
//
//int main()
//{
//	int year = 0;
//	int month = 0;
//	while ((scanf("%d %d", &year, &month)) != EOF)
//	{
//		//1 3 5 7 8 10 12   ��31��
//		//4 6 9 11   ��30��
//		//����2��29�죬ƽ��2��28��
//		switch (month)
//		{
//		case 2:
//			if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
//			{
//				printf("29\n");
//				break;
//			}
//			else
//			{
//				printf("28\n");
//				break;
//			}
//		case 4:
//		case 6:
//		case 9:
//		case 11:
//			printf("30\n");
//			break;
//		default:
//			printf("31\n");
//			break;
//		}
//	}
//	return 0;
//}

////�ж��ǲ�����ĸ
//
//#include <stdio.h>
//
//int main()
//{
//	char input = 0;
//	while ((scanf("%c", &input)) != EOF)
//	{
//		if (input >= 'A' && input <= 'Z' || input >= 'a' && input <= 'z')
//			printf("%c is an alphabet.\n", input);
//		else
//			printf("%c is not an alphabet.\n", input);
//		getchar();
//	}
//	return 0;
//}

////��ĸ��Сдת��
//#include <stdio.h>
//
//int main()
//{
//	char input = 0;
//	while ((scanf("%c", &input)) != EOF)
//	{
//		if (input >= 'A' && input <= 'Z')
//		{
//			input += 32;
//			printf("%c\n", input);
//		}
//		else if (input >= 'a' && input <= 'z')
//		{
//			input -= 32;
//			printf("%c\n", input);
//		}
//	}
//	return 0;
//}

//KiKi�ǳ�ϲ����������һ�ҵ�����������һ���·������˽⵽��
//��������ǡ�˫11����11��11�գ�������·���7�ۣ�
//��˫12�� ��12��12�գ�������·���8�ۣ�
//������Ż�ȯ���Զ����50Ԫ���Ż�ȯֻ����˫11��˫12ʹ�ã�����KiKi����������Ǯ����
//���ݷ�Χ���·��۸����� 1 \le val \le 100000 \1��val��100000

#include <stdio.h>

int main()
{
	double price = 0.0;
	int flag = 0;
	int month = 0;
	int date = 0;
	while ((scanf("%lf %d %d %d", &price, &month, &date, &flag)) != EOF)
	{
		double a = price * 0.8 - 50;
		double b = price * 0.7 - 50;
		if (12 == month && 12 == date)
		{
			if (1 == flag)
			{
				if (a < 0)
				{
					a = 0.0;
				}
				printf("%.2lf", a);
			}
			else
				printf("%.2lf", a + 50);
		}
		else if (11 == month && 11 == date)
		{
			if (1 == flag)
			{
				if (b < 0)
				{
					b = 0.0;
				}
				printf("%.2lf", b);
			}
			else
				printf("%.2lf", b + 50);
		}
		else
		{
			printf("%.2lf", price);
		}
	}
	return 0;
}