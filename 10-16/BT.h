#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int T;

// �������ڵ�ṹ
typedef struct TreeNode
{
	struct TreeNode* left;
	struct TreeNode* right;
	T data;
}TreeNode, * PTreeNode;

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
