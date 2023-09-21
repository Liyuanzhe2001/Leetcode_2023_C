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

    vector<int> postorderTraversal(TreeNode *root) {
        if (!root) {
            return res;
        }
        postorderTraversal(root->left);
        postorderTraversal(root->right);
        res.emplace_back(root->val);
        return res;
    }
};
