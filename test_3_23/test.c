#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>

struct Point
{
	int x;
	int y;
};

struct S
{
	char c;
	struct Point p;
	double d;
	char str[20];
};

int main()
{
	struct S ss = { 'x', {100,200}, 3.14, "hehe" };
	printf("%c %d %d %lf %s\n", ss.c, ss.p.x, ss.p.y, ss.d, ss.str);
	return 0;
}