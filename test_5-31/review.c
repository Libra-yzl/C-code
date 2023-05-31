#define _CRT_SECURE_NO_WARNINGS 1

#include "review.h"

SLTNode* BuySLTNode(SLTDataType x)
{
	SLTNode* newnode = (SLTNode*)malloc(sizeof(SLTNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;
	return newnode;
}

SLTNode* CreateSLTNode(int n)
{
	SLTNode* phead = NULL, * ptail = NULL;
	for (int i = 0; i < n; i++)
	{
		SLTNode* newnode = BuySLTNode(i);
		if (phead == NULL)
		{
			phead = ptail = newnode;
		}
		else
		{
			ptail->next = newnode;
			ptail = newnode;
		}
	}
	return phead;
}

void SLTDestroy(SLTNode** pphead)
{
	SLTNode* cur = *pphead;
	while (cur)
	{
		SLTNode* node = cur->next;
		free(cur);
		cur = node;
	}

	*pphead = NULL;
}

void SLTPrint(SLTNode* phead)
{
	SLTNode* cur = phead;
	while (cur)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("NULL\n");
}

void SLTPushBack(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	SLTNode* ptail = *pphead;
	if (*pphead == NULL)
	{
		*pphead = newnode;
	}
	else
	{
		//找尾
		while (ptail->next)
		{
			ptail = ptail->next;
		}
		ptail->next = newnode;
		ptail = newnode;
	}
}

void SLTPopBack(SLTNode** pphead)
{
	assert(*pphead);

	SLTNode* ptail = *pphead;
	if ((*pphead)->next == NULL)
	{
		free(*pphead);
		*pphead = NULL;
	}
	else
	{
		//找尾
		while (ptail->next->next)
		{
			ptail = ptail->next;
		}
		free(ptail->next);
		ptail->next = NULL;
	}
}

void SLTPushFront(SLTNode** pphead, SLTDataType x)
{
	SLTNode* newnode = BuySLTNode(x);
	
	newnode->next = *pphead;
	*pphead = newnode;
}

void SLTPopFront(SLTNode** pphead)
{
	assert(*pphead);

	SLTNode* node = *pphead;
	*pphead = (*pphead)->next;
	free(node);
}

SLTNode* SListFind(SLTNode* plist, SLTDataType x)
{
	SLTNode* cur = plist;
	while (cur)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void SListInsertAfter(SLTNode* pos, SLTDataType x)
{
	assert(pos);

	SLTNode* newnode = BuySLTNode(x);
	newnode->next = pos->next;
	pos->next = newnode;
}

void SListEraseAfter(SLTNode* pos)
{
	assert(pos);
	assert(pos->next);

	SLTNode* node = pos->next;
	pos->next = pos->next->next;
	free(node);
}

void SListInsert(SLTNode** pphead, SLTNode* pos, SLTDataType x)
{
	assert(pos);

	if (*pphead == pos)
		SLTPushFront(pphead, x);
	else
	{
		SLTNode* newnode = BuySLTNode(x);
		SLTNode* tail = *pphead;
		while (tail->next != pos)
		{
			tail = tail->next;
		}
		newnode->next = tail->next;
		tail->next = newnode;
	}
}

void SListErase(SLTNode** pphead, SLTNode* pos)
{
	assert(pos);
	assert(*pphead);

	if (*pphead == pos)
	{
		SLTPopFront(pphead);
	}
	else
	{
		SLTNode* tail = *pphead;
		while (tail->next != pos)
		{
			tail = tail->next;
		}
		tail->next = pos->next;
		free(pos);
	}
}

LTNode* LTBuyNode(LTDataType x)
{
	LTNode* newnode = (LTNode*)malloc(sizeof(LTNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->next = NULL;
	newnode->prev = NULL;
	newnode->val = x;
	return newnode;
}

LTNode* LTInit()
{
	LTNode* newnode = LTBuyNode(-1);
	newnode->next = newnode;
	newnode->prev = newnode;
	return newnode;
}

void LTPrint(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		printf("%d ", cur->val);
		cur = cur->next;
	}
	printf("\n");
}

void LTPushBack(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTBuyNode(x);
	
	newnode->prev = phead->prev;
	phead->prev->next = newnode;
	phead->prev = newnode;
	newnode->next = phead;

}

void LTPopBack(LTNode* phead)
{
	assert(phead);
	assert(phead->next);

	LTNode* del = phead->prev;
	phead->prev->prev->next = phead;
	phead->prev = phead->prev->prev;
	free(del);
}

void LTPushFront(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* newnode = LTBuyNode(x);

	phead->next->prev = newnode;
	newnode->next = phead->next;
	newnode->prev = phead;
	phead->next = newnode;

}

void LTPopFront(LTNode* phead)
{
	assert(phead);
	assert(phead->next);

	LTNode* del = phead->next;
	phead->next->next->prev = phead;
	phead->next = phead->next->next;
	free(del);
}

LTNode* LTFind(LTNode* phead, LTDataType x)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		if (cur->val == x)
			return cur;
		cur = cur->next;
	}
	return NULL;
}

void LTInsert(LTNode* pos, LTDataType x)
{
	assert(pos);

	LTNode* newnode = LTBuyNode(x);
	pos->prev->next = newnode;
	newnode->prev = pos->prev;
	pos->prev = newnode;
	newnode->next = pos;
}

void LTErase(LTNode* pos)
{
	assert(pos);

	pos->prev->next = pos->next;
	pos->prev = pos->next->prev;
	free(pos);
}

bool LTEmpty(LTNode* phead)
{
	assert(phead);

	return phead == phead->next;
}

int LTSize(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	int size = 0;
	while (cur != phead)
	{
		size++;
		cur = cur->next;
	}
	return size;
}

void LTDestroy(LTNode* phead)
{
	assert(phead);

	LTNode* cur = phead->next;
	while (cur != phead)
	{
		LTNode* node = cur->next;
		free(cur);
		cur = node;
	}
	free(phead);
	phead = NULL;
}

void StackInit(Stack* ps)
{
	assert(ps);

	ps->a = NULL;
	ps->top = ps->capacity = 0;
}

void StackDestroy(Stack* ps)
{
	assert(ps);

	free(ps->a);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void StackPush(Stack* ps, STDataType x)
{
	assert(ps);

	//检查扩容
	if (ps->capacity == ps->top)
	{
		int newCapacity = ps->capacity == 0 ? 4 : ps->capacity * 2;
		STDataType* tmp = (STDataType*)realloc(ps->a, sizeof(STDataType) * newCapacity);
		if (!tmp)
		{
			perror("reallco fail");
			exit(-1);
		}
		ps->a = tmp;
		ps->capacity = newCapacity;
	}
	ps->a[ps->top++] = x;
}

void StackPop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	ps->top--;
}

STDataType StackTop(Stack* ps)
{
	assert(ps);
	assert(ps->top > 0);

	return ps->a[ps->top - 1];
}

bool StackEmpty(Stack* ps)
{
	assert(ps);

	return ps->top == 0;
}

int StackSize(Stack* ps)
{
	assert(ps);

	return ps->top;
}


//Queue

void QueueInit(Queue* pq)
{
	assert(pq);

	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

void QueueDestroy(Queue* pq)
{
	assert(pq);

	QNode* cur = pq->head;
	while (cur)
	{
		QNode* node = cur->next;
		free(cur);
		cur = node;
	}
	pq->head = pq->tail = NULL;
	pq->size = 0;
}

void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->val = x;
	newnode->next = NULL;

	if (pq->head == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
	pq->size++;
}

void QueuePop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//assert(!QueueEmpty(pq));

	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		QNode* node = pq->head->next;
		free(pq->head);
		pq->head = node;
	}
	pq->size--;
}

QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//assert(!QueueEmpty(pq));


	return pq->head->val;
}

QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	//assert(!QueueEmpty(pq));


	return pq->tail->val;
}

bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == pq->tail && pq->head == NULL;
}

int QueueSize(Queue* pq)
{
	assert(pq);

	return pq->size;
}


//

void HeapPrint(Heap* php)
{
	assert(php);

	for (int i = 0; i < php->size; i++)
	{
		printf("%d ", php->a[i]);
	}
	printf("\n");
}

void HeapInit(Heap* php)
{
	assert(php);

	php->a = NULL;
	php->size = php->capacity = 0;
}

void HeapDestroy(Heap* php)
{
	assert(php);

	free(php->a);
	php->a = NULL;
	php->capacity = php->size = 0;
}

void Swap(HPDataType* buf1, HPDataType* buf2)
{
	HPDataType tmp = *buf1;
	*buf1 = *buf2;
	*buf2 = tmp;
}

void AdjustUp(HPDataType* a, int child)
{
	int parent = (child - 1) / 2;
	while (child > 0)
	{
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			child = parent;
			parent = (child - 1) / 2;
		}
		else
			break;
	}
}

void HeapPush(Heap* php, HPDataType x)
{
	assert(php);

	if (php->capacity == php->size)
	{
		int newCapacity = php->capacity == 0 ? 4 : php->capacity * 2;
		HPDataType* tmp = (HPDataType*)realloc(php->a, sizeof(HPDataType) * newCapacity);
		if (!tmp)
		{
			perror("realloc fail");
			exit(-1);
		}
		php->a = tmp;
		php->capacity = newCapacity;
	}
	php->a[php->size++] = x;

	//保持继续是一个堆
	AdjustUp(php->a, php->size - 1);
}

void AdjustDown(HPDataType* a, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child < size)
	{
		if (child + 1 < size && a[child] < a[child + 1])
		{
			child++;
		}
		if (a[child] > a[parent])
		{
			Swap(&a[child], &a[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			break;
	}
}

void HeapPop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	//这里要删除堆顶的元素
	Swap(&php->a[0], &php->a[php->size - 1]);
	php->size--;
	
	//保持继续是一个堆
	//AdjustUp(php->a, php->size - 1);
	AdjustDown(php->a, php->size, 0);
}

HPDataType HeapTop(Heap* php)
{
	assert(php);
	assert(php->size > 0);

	return php->a[0];
}

int HeapSize(Heap* php)
{
	assert(php);

	return php->size;
}

bool HeapEmpty(Heap* php)
{
	assert(php);

	return php->size == 0;
}

void HeapCreate(Heap* php, HPDataType* a, int n)
{
	assert(php);

	php->a = (HPDataType*)malloc(sizeof(HPDataType) * n);
	if (!php->a)
	{
		perror("malloc fail");
		exit(-1);
	}
	memcpy(php->a, a, n * sizeof(HPDataType));
	php->size = php->capacity = n;

	////向下调整建堆
	//for (int i = (n - 1 - 1) / 2; i >= 0; i--)
	//{
	//	AdjustDown(php->a, n, i);
	//}

	//向上调整建堆
	for (int i = 0; i < n; i++)
	{
		AdjustUp(php->a, i);
	}

	//AdjustDown(php->a, n, 0);
}

//void HeapSort(int* a, int size)
//{
//	for (int i = 0; i < size; i++)
//	{
//		AdjustUp(a, i);
//	}
//
//	int end = size - 1;
//	while (end > 0)
//	{
//		Swap(&a[0], &a[end]);
//		for (int i = 0; i < end; i++)
//		{
//			AdjustUp(a, i);
//		}
//		end--;
//	}
//}

void HeapSort(int* a, int size)
{
	//为什么不从i = 0开始向下调整建堆
	//因为向下调整建堆有要求 子树必须是一个堆
	//如果i==0开始 并不能保证根节点的子树是堆(注意：这里是无序的数组 不是堆)

	//这里是在建堆
	for (int i = (size - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(a, size, i);
	}

	int end = size - 1;
	while (end > 0)
	{
		Swap(&a[0], &a[end]);
		AdjustDown(a, end, 0);
		end--;
	}
}

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (!newnode)
	{
		perror("malloc fail");
		exit(-1);
	}
	newnode->left = NULL;
	newnode->right = NULL;
	newnode->val = x;

	return newnode;
}

void BinaryTreeDestory(BTNode* root)
{
	if (root == NULL)
		return;
	BinaryTreeDestory(root->left);
	BinaryTreeDestory(root->right);
	free(root);
}



//Sort

void InsertSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int end = i;
		int tmp = a[end + 1];
		while (end >= 0)
		{
			if (tmp < a[end])
			{
				a[end + 1] = a[end];
				--end;
			}
			else
				break;
		}
		a[end + 1] = tmp;
	}
}
void ShellSort(int* a, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = 0; i < size - gap; i++)
		{
			int end = i;
			int tmp = a[end + gap];
			while (end >= 0)
			{
				if (tmp < a[end])
				{
					a[end + gap] = a[end];
					end -= gap;
				}
				else
					break;
			}
			a[end + gap] = tmp;
		}
	}
}

//void HeapSort(int* a, int size);
void SelectSort(int* a, int size);


void BubbleSort(int* a, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int flag = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				Swap(&a[j], &a[j + 1]);
				flag = 0;
			}
		}
		if (flag == 1)
			break;
	}
}
void QuickSort(int* a, int size);

void MergeSort(int* a, int size);