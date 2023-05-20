
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
	return TreeKLevelSize(root->left, k-1) + TreeKLevelSize(root->right, k-1);
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

	//ǰ�����
	printf("ǰ�����:");
	PrevOrder(n1);
	printf("\n");
	//�������
	printf("�������:");
	InOrder(n1);
	printf("\n");
	//�������
	printf("�������:");
	PostOrder(n1);
	printf("\n");

	////�������
	//printf("�������:");
	//LevelOrder(n1);
	//printf("\n");

	//��������Ľڵ����
	printf("�������Ľڵ����:%d\n", TreeSize(n1));
	//���������Ҷ�ӽڵ����
	printf("��������Ҷ�ӽڵ�:%d\n", TreeLeafSize(n1));
	//��������ĸ߶�
	printf("�������ĸ߶����:%d\n", TreeHeight(n1));
	//���k��Ľڵ����
	int k = 3;
	printf("�������ĵ�%d��ڵ����:%d\n", k, TreeKLevelSize(n1, k));
	//����ָ��ֵ
	printf("����ָ��ֵ�ĵ�ַ:%p\n", TreeFind(n1, 5));
	printf("�ȶ�ָ��ֵ�ĵ�ַ:%p\n", n5);
}




int main()
{
	TestTree1();
	return 0;
}