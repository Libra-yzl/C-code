#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <time.h>

int main()
{
	size_t begin = clock();
	size_t n = 0;
	for (size_t i = 0; i < 100000000; ++i)
	{
		++n;
	}
	size_t end = clock();
	printf("%zdms\n", end - begin);
	return 0;
}