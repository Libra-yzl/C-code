#define _CRT_SECURE_NO_WARNINGS 1

#include "SeqList.h"

void SLInit(SL* ps)
{
	assert(ps);
	ps->data = NULL;
	ps->size = 0;
	ps->capacity = 0;
}

void SLDestroy(SL* ps)
{
	assert(ps);
	//if (ps->data != NULL)
	if (ps->data)
	{
		free(ps->data);
		ps->size = 0;
		ps->capacity = 0;
	}
}

void SLPushBack(SL* ps, SLDataType x)
{
	assert(ps);
	//����
	if (ps->size == ps->capacity)
	{
		size_t newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		//ps->data = (SLDataType*)realloc(ps->data, newCapacity * sizeof(SLDataType));
		SLDataType* tmp = (SLDataType*)realloc(ps->data, newCapacity * sizeof(SLDataType));
		if (tmp == NULL)
		{
			perror("realloc fail");
			exit(-1); //�쳣��ֹ
		}
		ps->data = tmp;
		ps->capacity = newCapacity;
	}
	ps->data[ps->size] = x;
	ps->size++;
}

void SLPopBack(SL* ps)
{
	//˳�����û�����ݣ����ܽ���ɾ������
	////����ļ��
	//if (ps->size == 0)
	//{
	//  printf("˳����������ݣ�����ɾ��");
	//	return;
	//}
	
	//�ֱ��ļ��
	assert(ps->size > 0);

	ps->size--;
}

void SLPrint(SL* ps)
{
	assert(ps);
	int i = 0;
	for (i = 0; i < ps->size; i++)
	{
		printf("%d ", ps->data[i]);
	}
	printf("\n");
}