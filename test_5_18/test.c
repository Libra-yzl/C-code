#define _CRT_SECURE_NO_WARNINGS 1


#include <stdio.h>
#include <stdlib.h>

typedef int BTDataType;

typedef struct BinaryTreeNode
{
	BTDataType data;
	struct BinaryTreeNode* left;
	struct BinaryTreeNode* right;
}BTNode;

BTNode* BTBuyNode(BTDataType x)
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

//ǰ��/ǰ������
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

//����/�и�����
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

//����/�������
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

int size = 0;

int TreeSize1(BTNode* root)
{
	if (root == NULL)
		return 0;

	static int size = 0;
	size++;
	TreeSize1(root->left);
	TreeSize1(root->right);
	return size;
}

void TreeSize2(BTNode* root)
{
	if (root == NULL)
		return;
	size++;
	TreeSize2(root->left);
	TreeSize2(root->right);
}

//���Ž�
int TreeSize3(BTNode* root)
{
	if (root == NULL)
		return 0;
	return TreeSize3(root->left) + TreeSize3(root->right)+1;
}

//��Ҷ�ӽڵ�
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
	//�����ظ����õĴ����ܶ� ���Ƽ����ַ�ʽ
	return TreeHeight(root->left) > TreeHeight(root->right) ? TreeHeight(root->left) + 1 : TreeHeight(root->right) + 1;
}

//���������/�߶�
int TreeHeight1(BTNode* root)
{
	if (root == NULL)
		return 0;
	int leftHeight = TreeHeight(root->left)+1;
	int rightHeight = TreeHeight(root->right)+1;

	return leftHeight > rightHeight ? leftHeight : rightHeight;
}

int TreeKLevelSize(BTNode* root, int k)
{
	if (root == NULL)
		return 0;
	if (k == 1)
		return 1;
	//k>1
	return TreeKLevelSize(root->left, k - 1) + TreeKLevelSize(root->right, k - 1);
}

void TestBTNode1()
{
	BTNode* n1 = BTBuyNode(1);
	BTNode* n2 = BTBuyNode(2);
	BTNode* n3 = BTBuyNode(3);
	BTNode* n4 = BTBuyNode(4);
	BTNode* n5 = BTBuyNode(5);
	BTNode* n6 = BTBuyNode(6);
	BTNode* n7 = BTBuyNode(7);

	n1->left = n2;
	n2->left = n3;
	n3->right = n7;
	n1->right = n4;
	n4->left = n5;
	n4->right = n6;

	//����
	//ǰ��(ǰ��)����
	PrevOrder(n1);
	printf("\n");

	//����(�и�)����
	InOrder(n1);
	printf("\n");

	//����(���)����
	PostOrder(n1);
	printf("\n");

	////err
	////��������Ľڵ����
	//TreeSize1(n1);
	//TreeSize1(n1);
	//printf("%d ", TreeSize1(n1));

	////err
	//TreeSize2(n1);
	//TreeSize2(n1);
	//TreeSize2(n1);
	//printf("%d\n", size);

	TreeSize3(n1);
	TreeSize3(n1);
	TreeSize3(n1);
	printf("%d\n", TreeSize3(n1));

	//Ҷ�ӽڵ�
	printf("%d\n", TreeLeafSize(n1));

	//�������
	printf("%d\n", TreeHeight1(n1));

	//���k��Ľڵ����
	int k = 4;
	printf("%d\n", TreeKLevelSize(n1, k));
}

int main()
{
	//���Ա���
	TestBTNode1();
	return 0;
}