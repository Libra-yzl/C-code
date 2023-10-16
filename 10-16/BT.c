//#include "BT.h"
//
//
//// 二叉树节点个数
//int BinaryTreeSize(TreeNode* root) {
//    if (root == NULL) return 0;
//    return 1 + BinaryTreeSize(root->left) + BinaryTreeSize(root->right);
//}
//
//// 二叉树叶子节点个数
//int BinaryTreeLeafSize(TreeNode* root) {
//    if (root == NULL) return 0;
//    if (root->left == NULL && root->right == NULL) return 1;
//    else return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
//}
//
//// 二叉树第k层节点个数
//int BinaryTreeLevelKSize(TreeNode* root, int k) {
//    if (root == NULL || k < 1) return 0;
//    if (k == 1) return 1;
//
//    return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
//}
//
//// 二叉树查找值为x的节点
//TreeNode* BinaryTreeFind(TreeNode* root, int x) {
//    if (root == NULL) return NULL;
//    if (root->data == x) return root;
//    TreeNode* lnode = BinaryTreeFind(root->left, x);
//    TreeNode* rnode = BinaryTreeFind(root->right, x);
//    return lnode == NULL ? rnode : lnode;
//    //return BinaryTreeFind(root->left, x) != NULL ? BinaryTreeFind(root->left, x) : BinaryTreeFind(root->right, x);
//}
//
//int main()
//{
//    TreeNode* root = createNode(5);
//    root->left = createNode(3);
//    root->right = createNode(8);
//    root->left->left = createNode(2);
//    root->left->right = createNode(4);
//    root->right->left = createNode(7);
//    root->right->right = createNode(9);
//
//    BinaryTreeSize(root);
//    printf("%d\n", BinaryTreeSize(root));
//
//    BinaryTreeLeafSize(root);
//    printf("%d\n", BinaryTreeLeafSize(root));
//
//    BinaryTreeLevelKSize(root, 3);
//    printf("%d\n", BinaryTreeLevelKSize(root, 3));
//
//    PTreeNode newnode = BinaryTreeFind(root, 2);
//    printf("%d\n", newnode->data);
//
//
//    // 释放内存
//    free(root->left->left);
//    free(root->left->right);
//    free(root->right->left);
//    free(root->right->right);
//    free(root->left);
//    free(root->right);
//    free(root);
//
//    return 0;
//}
