#include <iostream>
#include <vector>
#include <stack>
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

//#include <stack>
//
//
//class Solution {
//public:
//    void GetPath(TreeNode* root, TreeNode* node, stack<TreeNode*>& path)
//    {
//        if (root == nullptr) return;
//
//        path.push(root);
//        if (root == node) return;
//        else {
//            GetPath(root->left, node, path);
//            GetPath(root->right, node, path);
//        }
//        if (root->left == nullptr && root->right == nullptr) {
//            path.pop();
//            return;
//        }
//    }
//
//    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
//        stack<TreeNode*> pPath;
//        stack<TreeNode*> qPath;
//        GetPath(root, p, pPath);
//        GetPath(root, q, qPath);
//        while (pPath.size() > qPath.size()) {
//            pPath.pop();
//        }
//        while (pPath.size() < qPath.size()) {
//            qPath.pop();
//        }
//        while (pPath.top() != qPath.top())
//        {
//            pPath.pop();
//            qPath.pop();
//        }
//
//        return pPath.top();
//    }
//};

// https://www.nowcoder.com/practice/947f6eb80d944a84850b0538bf0ec3a5?tpId=13&&tqId=11179&rp=1&ru=/activity/oj&qru=/ta/coding-interviews/question-ranking

class Solution {
public:

    // // 1.使用数组更改链接关系
    // void _inOrder(TreeNode* root, vector<TreeNode*>& v_node) 
    // {
    // 	if (root == nullptr) return;

    // 	_inOrder(root->left, v_node);
    // 	v_node.push_back(root);
    // 	_inOrder(root->right, v_node);
    // }

    // TreeNode* Convert(TreeNode* pRootOfTree) {
    // 	if (pRootOfTree == nullptr) return nullptr;
    //     vector<TreeNode*> v_node;
    // 	_inOrder(pRootOfTree, v_node);

    // 	size_t len = v_node.size()-1;
    // 	for (size_t i = 0; i < len; ++i) {
    // 		v_node[i]->right = v_node[i+1];
    // 		v_node[i+1]->left = v_node[i];
    // 	}
    // 	return v_node[0];
    // }

    void _InOrder(TreeNode* root, TreeNode*& prev) {
        if (root == nullptr) return;
        _InOrder(root->left, prev);
        // 中序到这里
        root->left = prev;
        if (prev) prev->right = root;
        prev = root;
        _InOrder(root->right, prev);
    }

    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (pRootOfTree == nullptr) return nullptr;

        TreeNode* prev = nullptr;
        _InOrder(pRootOfTree, prev);
        TreeNode* head = pRootOfTree;
        while (head && head->left)
        {
            head = head->left;
        }
        return head;
    }
};

class Solution {
public:
    TreeNode* _buildTree(vector<int>& preorder, vector<int>& inorder, int& prei, int begin, int end) {
        if (begin > end) return nullptr;

        TreeNode* newroot = new TreeNode(preorder[prei]);

        int rooti = begin;
        while (rooti <= end) {
            if (inorder[rooti] == preorder[prei]) break;
            else ++rooti;
        }
        ++prei;
        newroot->left = _buildTree(preorder, inorder, prei, begin, rooti - 1);
        newroot->right = _buildTree(preorder, inorder, prei, rooti + 1, end);
        return newroot;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int i = 0;
        return _buildTree(preorder, inorder, i, 0, inorder.size() - 1);
    }
};


//https://leetcode.cn/problems/construct-binary-tree-from-inorder-and-postorder-traversal/description/

class Solution {
public:
    TreeNode* _buildTree(vector<int>& inorder, vector<int>& postorder, int& posti, int begin, int end) {
        if (begin > end) return nullptr;

        TreeNode* newroot = new TreeNode(postorder[posti]);
        int rooti = begin;
        while (rooti <= end) {
            if (inorder[rooti] == postorder[posti]) break;
            else ++rooti;
        }
        --posti;
        newroot->right = _buildTree(inorder, postorder, posti, rooti + 1, end);
        newroot->left = _buildTree(inorder, postorder, posti, begin, rooti - 1);
        return newroot;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int i = postorder.size() - 1;
        return _buildTree(inorder, postorder, i, 0, postorder.size() - 1);
    }
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int>{};
        TreeNode* cur = root;
        stack<TreeNode*> st_node;
        vector<int> v_val;
        while (cur || !st_node.empty()) {
            while (cur) {
                st_node.push(cur);
                cur = cur->left;
            }

            TreeNode* top = st_node.top();
            v_val.push_back(top->val);
            st_node.pop();
            cur = top->right;
        }
        return v_val;
    }
};

class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        if (root == nullptr) return vector<int> {};
        vector<int> v_val;
        stack<TreeNode*>st_node;
        TreeNode* cur = root;
        TreeNode* prev = nullptr;
        while (cur || !st_node.empty()) {
            while (cur) {
                st_node.push(cur);
                cur = cur->left;
            }
            TreeNode* top = st_node.top();
            // 如果右为空 或者 右子树已经访问(上一个访问的节点是右子树的根) 可以访问根节点
            if (top->right == nullptr || top->right == prev) {
                v_val.push_back(top->val);
                st_node.pop();
                prev = top;
            }
            else {
                cur = top->right;
            }
        }
        return v_val;
    }
};

// 后续非递归遍历二叉树
//https://leetcode.cn/problems/binary-tree-postorder-traversal/description/

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

    /*Solution sol;
    TreeNode* cur = sol.lowestCommonAncestor(node1, node2, node3);
    cout << cur->val << endl;*/
    return 0;
}