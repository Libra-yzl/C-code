#include <iostream>
#include <vector>
#include <queue>


using namespace std;

struct TreeNode 
{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode* left, TreeNode* right) : val(x), left(left), right(right) {}

};

int _TreeHeight(TreeNode* root)
{
    if (root == nullptr) return 0;
    return _TreeHeight(root->left) + 1 > _TreeHeight(root->right) + 1 ?
        _TreeHeight(root->left) + 1 : _TreeHeight(root->right) + 1;
}

//class Solution {
//public:
//    vector<vector<int>> levelOrder(TreeNode* root) {
//        vector<vector<int>> vv;
//        if (root == nullptr) return vv;
//        queue<TreeNode*> q_node;
//        queue<int> q_level;
//
//        q_node.push(root);
//        q_level.push(1);
//
//        while (!q_node.empty()) {
//            int level = q_level.front();
//            if (vv.size() < level) {
//                vv.push_back(vector<int>{});
//            }
//            vv[level - 1].push_back(q_node.front()->val);
//            if (q_node.front()->left != nullptr) {
//                q_node.push(q_node.front()->left);
//                q_level.push(q_level.front() + 1);
//            }
//            if (q_node.front()->right != nullptr) {
//                q_node.push(q_node.front()->right);
//                q_level.push(q_level.front() + 1);
//            }
//            q_node.pop();
//            q_level.pop();
//        }
//        return vv;
//    }
//};

#include <stack>


class Solution {
public:
    void GetPath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
    {
        if (root == nullptr) return;

        path.push(root);
        if (root == node) return;
        else {
            GetPath(root->left, node, path);
            GetPath(root->right, node, path);
        }
        if (root->left == nullptr && root->right == nullptr) {
            path.pop();
            return;
        }
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        stack<TreeNode*> pPath;
        stack<TreeNode*> qPath;
        GetPath(root, p, pPath);
        GetPath(root, q, qPath);
        while (pPath.size() > qPath.size()) {
            pPath.pop();
        }
        while (pPath.size() < qPath.size()) {
            qPath.pop();
        }
        while (pPath.top() != qPath.top())
        {
            pPath.pop();
            qPath.pop();
        }

        return pPath.top();
    }
};

int main()
{
    TreeNode* node1 = new TreeNode(3);
    TreeNode* node2 = new TreeNode(5);
    TreeNode* node3 = new TreeNode(1);
    TreeNode* node4 = new TreeNode(6);
    TreeNode* node5 = new TreeNode(2);
    TreeNode* node6 = new TreeNode(0);
    TreeNode* node7 = new TreeNode(8);
    TreeNode* node8 = new TreeNode(7);
    TreeNode* node9 = new TreeNode(4);

    node1->left = node2;
    node1->right = node3;
    node2->left = node4;
    node2->right = node5;
    node3->left = node6;
    node3->right = node7;
    node5->left = node8;
    node5->right = node9;
    //node5->left = node6;

    //vector<vector<int>> vv;
    //Solution sol;
    //vv = sol.levelOrder(node1);
    //for (int i = 0; i < vv.size(); ++i)
    //{
    //    for (int j = 0; j < vv[i].size(); ++j)
    //    {
    //        cout << vv[i][j] << " ";
    //    }
    //    cout << endl;
    //}
    //cout << endl;

    ///*int n = _TreeHeight(node1);
    //cout << n << endl;*/

    Solution sol;
    TreeNode* cur = sol.lowestCommonAncestor(node1, node2, node3);
    cout << cur->val << endl;
    return 0;
}