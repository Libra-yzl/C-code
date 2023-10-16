#include <stdio.h>
#include <stdlib.h>


typedef int T;

// 定义树节点结构
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	T data;
}TreeNode, *PTreeNode;

// 创建节点
TreeNode* createNode(int data)
{
	TreeNode* newNode = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    // 检查空指针
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

// 1.这是全局并且遍历所有节点的方法
void countLess1(TreeNode* root, int a)
{
    // 递归停止条件
    if (root == NULL) return;
    if (root->data < a) ++countGlobal;
    countLess1(root->left, a);
    countLess1(root->right, a);
}

// 2.不使用全局变量
int countLess2(TreeNode* root, int a)
{
    // 递归计算小于a的节点个数
    if (root == NULL) {
        return 0;
    }
    int count = 0; // 初始化计数为0
    if (root->data < a) {
        count++; // 当根节点的值小于a时，增加计数
    }
    count += countLess2(root->left, a); // 递归计算左子树
    count += countLess2(root->right, a); // 递归计算右子树
    return count; // 返回计数
}

// 3.这是基于二叉排序树的方法
int countLess3(TreeNode* root, int a)
{
    if (root == NULL) {
        return 0;
    }
    if (root->data < a) {
        // 当根节点的值小于a时，根节点及其左子树都满足条件
        return 1 + countLess3(root->left, a) + countLess3(root->right, a);
    }
    else {
        // 当根节点的值大于等于a时，只有左子树满足条件
        return countLess3(root->left, a);
    }
}

// 计算二叉树的节点个数
int NodeCount(PTreeNode root) {
    if (root == NULL) return 0;
    return 1 + NodeCount(root->left) + NodeCount(root->right);
}

int main()
{
    // 申请节点
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
    printf("值小于 %d 的节点个数为: %d\n", a, countGlobal);

    int count = countLess2(root, a);
    printf("值小于 %d 的节点个数为: %d\n", a, count);

    count = countLess3(root, a);
    printf("值小于 %d 的节点个数为: %d\n", a, count);

    countLess1(root, a);
    printf("第二次使用全局变量的方法(错误): %d\n", countGlobal);

    count = countLess2(root, a);
    printf("第二次未使用全局变量的方法: %d\n", count);

    count = countLess3(root, a);
    printf("第二次使用二叉排序树的方法: %d\n", count);

    // 计算树的节点个数
    int n = NodeCount(root);
    printf("该二叉树的节点个数: %d\n", n);
    int* arr = (int*)malloc(n * sizeof(int));

    // 释放内存
    free(root->left->left);
    free(root->left->right);
    free(root->right->left);
    free(root->right->right);
    free(root->left);
    free(root->right);
    free(root);

    return 0;
}


