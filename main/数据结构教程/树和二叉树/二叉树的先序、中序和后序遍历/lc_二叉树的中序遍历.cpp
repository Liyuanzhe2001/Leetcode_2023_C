//
// Created by LiYuanzhe on 2023/9/21.
//
#include "vector"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode() : val(0), left(nullptr), right(nullptr) {}

    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}

    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    vector<int> res;

    vector<int> inorderTraversal(TreeNode *root) {
        if (!root) {
            return res;
        }
        inorderTraversal(root->left);
        res.emplace_back(root->val);
        inorderTraversal(root->right);
        return res;
    }
};
