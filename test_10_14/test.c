#define _CRT_SECURE_NO_WARNINGS 1

//#include <stdio.h>
//
//int main()
//{
//	//读文件
//	FILE * pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用
//	//fputc('a', pf);
//	/*int ch = fgetc(pf);
//	printf("%c", ch);*/
//
//
//	int ch = 0;
//	/*for (i = 0; i < 26; i++)
//	{
//		fputc('a' + i, pf);
//	}*/
//	while ((ch = fgetc(pf)) != EOF)
//	{
//		printf("%c ", ch);
//	}
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//
//int main()
//{
//	//读文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	
//	//使用
//	/*fputs("hello\n", pf);
//	fputs("bit\n", pf);*/
//
//	char str[20];
//	fgets(str, 6, pf);
//	printf("%s\n", str);
//	fgets(str, 5, pf);
//	printf("%s\n", str);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}


//#include <stdio.h>
//
//struct tag
//{
//	char name[20];
//	int age;
//	char sex[6];
//};
//
//int main()
//{
//	//读文件
//	FILE* pf = fopen("test.txt", "r");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//struct tag t = { .name = "张三", .age = 20, .sex = "男" };
//	struct tag t = { 0 };
//	//使用
//	//fprintf(pf,"%s %d %s", t.name, t.age, t.sex);
//
//	fscanf(pf, "%s %d %s", t.name, &t.age, t.sex);
//	printf("%s %d %s", t.name, t.age, t.sex);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}

////二进制读写文件操作
//#include <stdio.h>
//
//struct tag
//{
//	char name[20];
//	int age;
//	char sex[6];
//};
//
////int main()
////{
////	struct tag t = { "张三", 20,"男" };
////	FILE* pf = fopen("test.txt", "wb");
////	if (NULL == pf)
////	{
////		perror("fopen");
////		return 1;
////	}
////	//使用
////	fwrite(&t, sizeof(t), 1, pf);
////
////	//关闭文件
////	fclose(pf);
////	pf = NULL;
////	return 0;
////}
//
//int main()
//{
//	struct tag t = { 0 };
//	FILE* pf = fopen("test.txt", "rb");
//	if (NULL == pf)
//	{
//		perror("fopen");
//		return 1;
//	}
//	//使用
//	fread(&t, sizeof(t), 1, pf);
//
//	printf("%s %d %s", t.name, t.age, t.sex);
//	//关闭文件
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//


//qsort存入文件

#include <stdio.h>
#include <string.h>


void Swap(char* buf1, char* buf2, int width)
{
	int i = 0;
	for (i = 0; i < width; i++)
	{
		char tmp = *buf1;
		*buf1 = *buf2;
		*buf2 = tmp;
		buf1++;
		buf2++;
	}
}

void bubble_sort(void* base, int sz, int width, int(*compare)(const void* e1, const void* e2))
{
	int i = 0;
	for (i = 0; i < sz - 1; i++)
	{
		int j = 0;
		for (j = 0; j < sz - 1 - i; j++)
		{
			// 
			if (compare((char*)base + j * width, (char*)base + (j+1) * width) > 0)
			{
				//交换
				Swap((char*)base + j * width, (char*)base + (j + 1)* width, width);
			}
		}
	}
}

void print1(int* arr, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%d ", *(arr + i));
	}
	printf("\n");
}

int cmp(const void* e1, const void* e2)
{
	return *(int*)e1 - *(int*)e2;
}

void test1()
{
	int arr[] = { 9,8,7,6,5,4,3,2,1,0 };
	int sz = sizeof(arr) / sizeof(arr[0]);
	bubble_sort(arr, sz, sizeof(int), cmp);
	print1(arr, sz);
}

int cmp_float(const void* e1, const void* e2)
{
	return *(float*)e1 - *(float*)e2;
}

void print2(float* f, int sz)
{
	int i = 0;
	for (i = 0; i < sz; i++)
	{
		printf("%.2f ", *(f + i));
	}
	printf("\n");
}

void test2()
{
	float f[] = { 9.0f,8.0f,7.0f,6.0f,5.0f,4.0f,3.0f,2.0f,1.0f,0.0f };
	int sz = sizeof(f) / sizeof(f[0]);
	bubble_sort(f, sz, sizeof(float), cmp_float);
	print2(f, sz);
}

struct tag
{
	char name[20];
	int age;
};

int cmp_stu_age(const void* e1, const void* e2)
{
	return ((struct tag*)e1)->age - ((struct tag*)e2)->age;
}

int cmp_stu_name(const void* e1, const void* e2)
{
	return strcmp(((struct tag*)e1)->name, ((struct tag*)e2)->name);
}

void print3(struct tag* t)
{
	int i = 0;
	for (i = 0; i < 2; i++)
	{
		printf("%s %d\n", t[i].name, t[i].age);
	}
}

void test3()
{
	struct tag t[] = { {"张三", 20}, {"李四", 21} };
	int sz = sizeof(t) / sizeof(t[0]);
	//bubble_sort(t, sz, sizeof(t[0]), cmp_stu_age);
	bubble_sort(t, sz, sizeof(t[0]), cmp_stu_name);
	print3(t);
}

int main()
{
	//test1();//测试整型数据
	//test2();//测试浮点数数据
	test3();//测试结构体数据
	return 0;
}