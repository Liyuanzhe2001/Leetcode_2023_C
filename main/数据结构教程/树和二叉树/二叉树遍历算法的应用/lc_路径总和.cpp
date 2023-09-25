//
// Created by LiYuanzhe on 2023/9/25.
//


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
    bool hasPathSum(TreeNode *root, int targetSum) {
        if (!root) {
            return false;
        }
        int val = targetSum - root->val;
        if (!root->left && !root->right) {
            if (val == 0) {
                return true;
            }
            return false;
        }
        return hasPathSum(root->left, val) || hasPathSum(root->right, val);;
    }
};