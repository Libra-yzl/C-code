#define _CRT_SECURE_NO_WARNINGS 1

#include "B.h"

int main()
{
	char a[] = "ABD##E#H##CF##G##";
	int size = (int)strlen(a);
	int i = 0;
	BTNode* root = BinaryTreeCreate(a, size, &i);

	printf("BinaryTreePrevOrder:\n");
	BinaryTreePrevOrder(root);

	printf("\nBinaryTreeInOrder:\n");
	BinaryTreeInOrder(root);

	printf("\nBinaryTreePostOrder:\n");
	BinaryTreePostOrder(root);

	printf("\nBinaryTreeLevelOrder:\n");
	BinaryTreeLevelOrder(root);
	printf("\n");

	printf("BinaryTreeSize:%d\n", BinaryTreeSize(root));
	printf("BinaryTreeLeafSize:%d\n", BinaryTreeLeafSize(root));
	printf("BinaryTreeLevelKSize:%d\n", BinaryTreeLevelKSize(root, 3));
	printf("BinaryTreeFind:%p\n", BinaryTreeFind(root, 'A'));
	printf("BinaryTreeFind:%p\n", root);

	BinaryTreeDestory(root);
	return 0;
}