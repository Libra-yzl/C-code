#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int T;

// 定义树节点结构
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	T data;
}TreeNode, * PTreeNode;

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
