#include <stdio.h>
#include <stdlib.h>


typedef int T;

// �������ڵ�ṹ
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	T data;
}TreeNode, *PTreeNode;

// �����ڵ�
TreeNode* createNode(int data)
{
	TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // ����ָ��
    if (!newNode) {
        perror("malloc fail");
        return NULL;
    }
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;

	return newNode;
}

int countGlobal = 0;

// 1.����ȫ�ֲ��ұ������нڵ�ķ���
void countLess1(TreeNode* root, int a)
{
    // �ݹ�ֹͣ����
    if (root == NULL) return;
    if (root->data < a) ++countGlobal;
    countLess1(root->left, a);
    countLess1(root->right, a);
}

// 2.��ʹ��ȫ�ֱ���
int countLess2(TreeNode* root, int a)
{
    // �ݹ����С��a�Ľڵ����
    if (root == NULL) {
        return 0;
    }
    int count = 0; // ��ʼ������Ϊ0
    if (root->data < a) {
        count++; // �����ڵ��ֵС��aʱ�����Ӽ���
    }
    count += countLess2(root->left, a); // �ݹ����������
    count += countLess2(root->right, a); // �ݹ����������
    return count; // ���ؼ���
}

// 3.���ǻ��ڶ����������ķ���
int countLess3(TreeNode* root, int a)
{
    if (root == NULL) {
        return 0;
    }
    if (root->data < a) {
        // �����ڵ��ֵС��aʱ�����ڵ㼰������������������
        return 1 + countLess3(root->left, a) + countLess3(root->right, a);
    }
    else {
        // �����ڵ��ֵ���ڵ���aʱ��ֻ����������������
        return countLess3(root->left, a);
    }
}

// ����������Ľڵ����
int NodeCount(PTreeNode root) {
    if (root == NULL) return 0;
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int main()
{
    // ����ڵ�
    TreeNode* root = createNode(5);
    root->left = createNode(3);
    root->right = createNode(8);
    root->left->left = createNode(2);
    root->left->right = createNode(4);
    root->right->left = createNode(7);
    root->right->right = createNode(9);
    root->right->left->left = createNode(6);

    int a = 5;
    countLess1(root, a);
    printf("ֵС�� %d �Ľڵ����Ϊ: %d\n", a, countGlobal);

    int count = countLess2(root, a);
    printf("ֵС�� %d �Ľڵ����Ϊ: %d\n", a, count);

    count = countLess3(root, a);
    printf("ֵС�� %d �Ľڵ����Ϊ: %d\n", a, count);

    countLess1(root, a);
    printf("�ڶ���ʹ��ȫ�ֱ����ķ���(����): %d\n", countGlobal);

    count = countLess2(root, a);
    printf("�ڶ���δʹ��ȫ�ֱ����ķ���: %d\n", count);

    count = countLess3(root, a);
    printf("�ڶ���ʹ�ö����������ķ���: %d\n", count);

    // �������Ľڵ����
    int n = NodeCount(root);
    printf("�ö������Ľڵ����: %d\n", n);
    int* arr = (int*)malloc(n * sizeof(int));

    // �ͷ��ڴ�
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}


