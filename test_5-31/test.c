#define _CRT_SECURE_NO_WARNINGS 1


#include "review.h"

void TestSLTNode()
{
	SLTNode* plist = NULL;

	SLTPushBack(&plist, 10);
	SLTPushBack(&plist, 20);
	SLTPushBack(&plist, 30);
	SLTPushBack(&plist, 40);
	SLTPushBack(&plist, 50);
	SLTPushBack(&plist, 60);
	SLTPushBack(&plist, 70);
	SLTPrint(plist);

	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPopBack(&plist);
	SLTPrint(plist);

	SLTPushBack(&plist, 100);
	SLTPrint(plist);

	SLTPushFront(&plist, 1);
	SLTPushFront(&plist, 2);
	SLTPushFront(&plist, 3);
	SLTPushFront(&plist, 4);
	SLTPushFront(&plist, 5);
	SLTPrint(plist);

	/*SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);
	SLTPopFront(&plist);*/

	SLTNode* pos = SListFind(plist, 10);
	SListInsertAfter(pos, 1000);
	SLTPrint(plist);

	SListEraseAfter(pos);
	SLTPrint(plist);
	SListEraseAfter(pos);
	SLTPrint(plist);

	SListInsert(&plist, pos, 2000);
	SLTPrint(plist);
	
	pos = SListFind(plist, 5);
	SListInsert(&plist, pos, 5000);
	//SListInsertAfter(pos, 5000);
	SLTPrint(plist);

	pos = SListFind(plist, 5000);
	SListErase(&plist, pos);
	SLTPrint(plist);

	SLTDestroy(&plist);
}

void TestLTNode()
{
	LTNode* plist = LTInit();

	/*LTPushBack(plist, 10);
	LTPushBack(plist, 20);
	LTPushBack(plist, 30);
	LTPushBack(plist, 40);
	LTPushBack(plist, 50);
	LTPrint(plist);

	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPopBack(plist);
	LTPrint(plist);*/

	/*LTPushFront(plist, 100);
	LTPushFront(plist, 200);
	LTPushFront(plist, 300);
	LTPushFront(plist, 400);
	LTPushFront(plist, 500);
	LTPrint(plist);

	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPopFront(plist);
	LTPrint(plist);*/

	LTPushBack(plist, 10);
	LTPushBack(plist, 20);
	LTPushBack(plist, 30);
	LTPushBack(plist, 40);
	LTPushBack(plist, 50);
	LTPrint(plist);

	LTNode* pos = LTFind(plist, 50);
	LTInsert(pos, 100);
	LTPrint(plist);

	pos = LTFind(plist, 20);
	//LTErase(pos);
	LTPrint(plist);

	printf("Size:%d\n", LTSize(plist));
	printf("isEmpty:%d\n", LTEmpty(plist));

	LTDestroy(plist);
}

void TestStack()
{
	Stack s;
	StackInit(&s);

	StackPush(&s, 100);
	StackPush(&s, 200);
	StackPush(&s, 300);
	StackPush(&s, 400);
	StackPush(&s, 500);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");
	printf("Top:%d\n", StackTop(&s));
	printf("Size:%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);
	for (int i = 0; i < s.top; i++)
	{
		printf("%d ", s.a[i]);
	}
	printf("\n");
	printf("Top:%d\n", StackTop(&s));
	printf("Size:%d\n", StackSize(&s));

	StackPop(&s);
	StackPop(&s);
	//StackPop(&s);
	//printf("Top:%d\n", StackTop(&s));
	printf("isEmpty:%d\n", StackEmpty(&s));

	StackDestroy(&s);
}

void TestQueue()
{
	Queue q;
	QueueInit(&q);
	
	QueuePush(&q, 100);
	QueuePush(&q, 200);
	QueuePush(&q, 300);
	QueuePush(&q, 400);
	QueuePush(&q, 500);
	
	while (!QueueEmpty(&q))
	{
		printf("%d ", QueueFront(&q));
		QueuePop(&q);
	}
	printf("\n");

	printf("Size:%d\n", QueueSize(&q));
	printf("isEmpty:%d\n", QueueEmpty(&q));

	QueueDestroy(&q);
}

void TestHeap1()
{
	Heap hp;
	HeapInit(&hp);

	HeapPush(&hp, 10);
	HeapPush(&hp, 29);
	HeapPush(&hp, 8);
	HeapPush(&hp, 21);
	HeapPush(&hp, 16);
	HeapPush(&hp, 3);
	HeapPush(&hp, 38);
	HeapPush(&hp, 27);
	HeapPush(&hp, 32);
	HeapPush(&hp, 15);
	HeapPrint(&hp);

	printf("删除堆顶元素后:\n");
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);
	HeapPop(&hp);

	HeapPrint(&hp);

	//printf("HeapTop:%d\n", HeapTop(&hp));
	printf("HeapSize:%d\n", HeapSize(&hp));
	printf("HeapEmpty:%d\n", HeapEmpty(&hp));

	HeapDestroy(&hp);
}

void TestHeap2()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	Heap hp;

	HeapCreate(&hp, arr, sizeof(arr) / sizeof(arr[0]));
	HeapPrint(&hp);

	HeapDestroy(&hp);
}

void TestHeapSort()
{
	int arr[] = { 27,15,19,18,28,34,65,49,25,37 };
	HeapSort(arr, sizeof(arr) / sizeof(arr[0]));
	for (int i = 0; i < sizeof(arr) / sizeof(arr[0]); i++)
	{
		printf("%d ", arr[i]);
	}
	printf("\n");
}

void TestHeap3()
{
	//topK问题
	int n = 100;
	int k = 5;
	srand((unsigned)time(NULL));
	FILE* pfin = fopen("data.txt", "w");
	if (!pfin)
	{
		perror("fopen fail");
		return;
	}
	for (int i = 0; i < n; i++)
	{
		int val = rand() % 100000;
		fprintf(pfin, "%d\n", val);
	}
	fclose(pfin);
	pfin = NULL;

	//找topK
	FILE* pfout = fopen("data.txt", "r");
	if (!pfout)
	{
		perror("fopen fail");
		return;
	}
	int* minHeap = (int*)malloc(sizeof(int) * k);
	if (!minHeap)
	{
		perror("malloc fail");
		return;
	}
	for (int i = 0; i < k; i++)
	{
		fscanf(pfout, "%d", &minHeap[i]);
	}
	//建小堆找最大的topK
	for (int i = (k - 1 - 1) / 2; i >= 0; i--)
	{
		AdjustDown(minHeap, k, i);
	}
	int val = 0;
	while (fscanf(pfout, "%d", &val) != EOF)
	{
		if (val > minHeap[0])
		{
			minHeap[0] = val;
			AdjustDown(minHeap, k, 0);
		}
	}
	for (int i = 0; i < k; i++)
	{
		printf("%d ", minHeap[i]);
	}
	printf("\n");

	fclose(pfout);
	pfout = NULL;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->val);
	PrevOrder(root->left);
	PrevOrder(root->right);
}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	InOrder(root->left);
	printf("%d ", root->val);
	InOrder(root->right);
}

void PostOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->val);
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	if (root->left == NULL && root->right == NULL)
		return 1;
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}

int TreeHeight(BTNode* root)
{
	if (root == NULL)
		return 0;

	int leftHeight = TreeHeight(root->left);
	int rightHeight = TreeHeight(root->right);
	return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;

	//return TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}

int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	else
		return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->val == x)
		return root;
	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	return NULL;
}

void LevelOrder(BTNode* root)
{
	Queue q;
	QueueInit(&q);

	if (root)
		QueuePush(&q, root);

	while (!QueueEmpty(&q))
	{
		BTNode* front = QueueFront(&q);
		printf("%d ", front->val);
		QueuePop(&q);

		if (front->left)
		{
			QueuePush(&q, front->left);
		}
		if (front->right)
		{
			QueuePush(&q, front->right);
		}
	}
	printf("\n");

	QueueDestroy(&q);
}

void TestBTNode()
{
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);

	n1->left = n2;
	n1->right = n4;
	n2->left = n3;
	//n2->right = n7;
	n4->left = n5;
	n4->right = n6;
	n3->right = n7;

	printf("PrevOrder:\n");
	PrevOrder(n1);
	printf("\n");

	printf("InOrder:\n");
	InOrder(n1);
	printf("\n");

	printf("PostOrder:\n");
	PostOrder(n1);
	printf("\n");

	printf("LevelOrder:\n");
	LevelOrder(n1);
	printf("\n");

	printf("TreeSize:%d\n", TreeSize(n1));
	printf("TreeLeafSize:%d\n", TreeLeafSize(n1));
	printf("TreeHeight:%d\n", TreeHeight(n1));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1, 3));
	printf("TreeKLevelSize:%d\n", TreeKLevelSize(n1, 2));
	printf("TreeFind:%p\n", TreeFind(n1, 5));
	printf("TreeFind:%p\n", n5);
}

void Print(int* a, int n)
{
	for (int i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	printf("\n");
}

void test_bubble(int* a, int size)
{
	printf("BubbleSort:\n");
	BubbleSort(a, size);
	Print(a, size);
}

void test_insert(int* a, int size)
{
	printf("InsertSort:\n");
	InsertSort(a, size);
	Print(a, size);
}

void test_shell(int* a, int size)
{
	printf("ShellSort:\n");
	ShellSort(a, size);
	Print(a, size);
}

void test_heap(int* a, int size)
{
	printf("HeapSort:\n");
	HeapSort(a, size);
	Print(a, size);
}

void TestSort()
{
	int a1[] = { 9,8,7,6,5,4,3,2,1,0 };
	int size = sizeof(a1) / sizeof(a1[0]);
	test_bubble(a1, size);

	int a2[] = { 9,8,7,6,5,4,3,2,1,0 };
	test_insert(a2, size);

	int a3[] = { 9,8,7,6,5,4,3,2,1,0 };
	test_shell(a3, size);

	int a4[] = { 9,8,7,6,5,4,3,2,1,0 };
	test_heap(a4, size);
}

int main()
{
	//TestSLTNode();
	//TestLTNode();

	//TestStack();
	//TestQueue();

	//TestHeap1();
	//TestHeap2();
	// //?*****
	//TestHeapSort();
	//TestHeap3();

	TestBTNode();

	//TestSort();
	return 0;
}