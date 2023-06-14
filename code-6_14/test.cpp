#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>

using namespace std;

namespace yzl
{
#include <assert.h>
#include <stdlib.h> 


	struct SL
	{
		int* data;
		int capacity;
		int size;
	};

	void SLInit(SL* ps)
	{
		ps->data = NULL;
		ps->capacity = ps->size = 0;
	}

	void SLDestroy(SL* ps)
	{
		assert(ps);

		ps->data = NULL;
		ps->capacity = ps->size = 0;
	}

	void SLPushBack(SL* ps, int x)
	{
		assert(ps);

		if (ps->capacity == ps->size)
		{
			int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
			int* tmp = (int*)malloc(sizeof(int) * newCapacity);
			if (!tmp)
			{
				perror("malloc fail");
				exit(-1);
			}
			ps->capacity = newCapacity;
			ps->data = tmp;
		}

		ps->data[ps->size++] = x;
	}

	void Print(SL* ps)
	{
		assert(ps);

		for (int i = 0; i < ps->size; i++)
		{
			cout << ps->data[i] << " ";
		}
		cout << endl;
	}
}

using namespace yzl;

int main()
{
	SL s;
	SLInit(&s);

	SLDestroy(&s);
	return 0;
}