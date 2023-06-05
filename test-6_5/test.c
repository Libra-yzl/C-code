#define _CRT_SECURE_NO_WARNINGS 1


//https://leetcode.cn/problems/invert-binary-tree/submissions/
//https://leetcode.cn/submissions/detail/434005253/
//https://leetcode.cn/problems/symmetric-tree/submissions/

#pragma once


#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>



typedef int QDataType;

typedef struct QueueNode
{
	QDataType data;
	struct QueueNode* next;
}QNode;

typedef struct Queue
{
	QNode* head;
	QNode* tail;
	int size;
}Queue;


//声明
//初始化及释放
void QueueInit(Queue* pq);
void QueueDestroy(Queue* pq);

//队列插入删除
void QueuePush(Queue* pq, QDataType x);
void QueuePop(Queue* pq);

//取出队头队尾的元素
QDataType QueueFront(Queue* pq);
QDataType QueueBack(Queue* pq);

//判断队列的状态（为空\大小）
bool QueueEmpty(Queue* pq);
int QueueSize(Queue* pq);


#define _CRT_SECURE_NO_WARNINGS 1


#include "Queue.h"


//初始化及释放
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
		QNode* del = cur;
		cur = cur->next;
		free(del);

		//局部变量 即使不置空也不会被访问
		//del = NULL;
	}
	pq->head = NULL;
	pq->tail = NULL;
	pq->size = 0;
}

//队列插入删除
void QueuePush(Queue* pq, QDataType x)
{
	assert(pq);

	QNode* newnode = (QNode*)malloc(sizeof(QNode));
	if (!newnode)
	{
		perror("malloc fail");
		return;
	}
	newnode->data = x;
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
	assert(!QueueEmpty(pq));

	QNode* del = pq->head;
	pq->head = pq->head->next;
	free(del);

	if (pq->head == NULL)
		pq->tail = NULL;

	pq->size--;
}

//取出队头队尾的元素
QDataType QueueFront(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->head->data;
}
QDataType QueueBack(Queue* pq)
{
	assert(pq);
	assert(!QueueEmpty(pq));

	return pq->tail->data;
}

//判断队列的状态（为空\大小）
bool QueueEmpty(Queue* pq)
{
	assert(pq);

	return pq->head == NULL && pq->tail == NULL;
}
int QueueSize(Queue* pq)
{
	assert(pq);

	/*QNode* cur = pq->head;
	int size = 0;
	while (cur)
	{
		size++;
		cur = cur->next;
	}
	return size;*/

	return pq->size;
}

//void QueuePrint(Queue* pq)
//{
//	assert(pq);
//	
//	QNode* cur = pq->head;
//	while (cur)
//	{
//		printf("%d ", cur->data);
//		cur = cur->next;
//	}
//	printf("\n");
//}


#define _CRT_SECURE_NO_WARNINGS 1

#include "Queue.h"


//https://leetcode.cn/problems/univalued-binary-tree/
//https://nowcoder.com/practice/4b91205483694f449f94c179883c1fef?tpId=60&&tqId=29483&rp=1&ru=/activity/oj&qru=/ta/tsing-kaoyan/question-ranking
//https://leetcode.cn/problems/same-tree/submissions/


typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BuyBTNode(BTDataType x)
{
	BTNode* node = (BTNode*)malloc(sizeof(BTNode));
	if (!node)
	{
		perror("malloc fail");
		exit(-1);
	}
	node->data = x;
	node->left = node->right = NULL;
	return node;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		printf("NULL ");
		return;
	}

	printf("%d ", root->data);
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
	printf("%d ", root->data);
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
	printf("%d ", root->data);
}

int TreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize(root->left) + TreeSize(root->right) + 1;
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
}

int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

BTNode* TreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;

	if (root->data == x)
		return root;

	BTNode* ret1 = TreeFind(root->left, x);
	if (ret1)
		return ret1;
	BTNode* ret2 = TreeFind(root->right, x);
	if (ret2)
		return ret2;
	return NULL;
}

//void LevelOrder(BTNode* root)
//{
//	struct Queue q1;
//	QueueInit(&q1);
//	if (root)
//		QueuePush(&q1, root);
//	while (!QueueEmpty(&q1))
//	{
//		BTNode* front = QueueFront(&q1);
//		printf("%d ", front->data);
//		QueuePop(&q1);
//		if (front->left)
//			QueuePush(&q1, front->left);
//		if (front->right)
//			QueuePush(&q1, front->right);
//		
//	}
//	printf("\n");
//
//	QueueDestroy(&q1);
//}

void TestTree1()
{
	BTNode* n1 = BuyBTNode(1);
	BTNode* n2 = BuyBTNode(2);
	BTNode* n3 = BuyBTNode(3);
	BTNode* n4 = BuyBTNode(4);
	BTNode* n5 = BuyBTNode(5);
	BTNode* n6 = BuyBTNode(6);
	BTNode* n7 = BuyBTNode(7);

	n1->left = n2;
	n2->left = n3;
	n1->right = n4;
	n4->left = n5;
	n4->right = n6;
	//n3->right = n7;

	//前序遍历
	printf("前序遍历:");
	PrevOrder(n1);
	printf("\n");
	//中序遍历
	printf("中序遍历:");
	InOrder(n1);
	printf("\n");
	//后序遍历
	printf("后序遍历:");
	PostOrder(n1);
	printf("\n");

	////层序遍历
	//printf("层序遍历:");
	//LevelOrder(n1);
	//printf("\n");

	//求二叉树的节点个数
	printf("二叉树的节点个数:%d\n", TreeSize(n1));
	//求二叉树的叶子节点个数
	printf("二叉树的叶子节点:%d\n", TreeLeafSize(n1));
	//求二叉树的高度
	printf("二叉树的高度深度:%d\n", TreeHeight(n1));
	//求第k层的节点个数
	int k = 3;
	printf("二叉树的第%d层节点个数:%d\n", k, TreeKLevelSize(n1, k));
	//查找指定值
	printf("查找指定值的地址:%p\n", TreeFind(n1, 5));
	printf("比对指定值的地址:%p\n", n5);
}




int main()
{
	TestTree1();
	return 0;
}