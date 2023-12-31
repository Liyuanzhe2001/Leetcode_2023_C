//
// Created by LiYuanzhe on 2023/9/21.
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

    TreeNode *pre = nullptr;

    void flatten(TreeNode *root) {
        if (!root) {
            return;
        }
        TreeNode *lef = root->left;
        TreeNode *rig = root->right;
        if (pre) {
            pre->left = nullptr;
            pre->right = root;
        }
        pre = root;
        flatten(lef);
        flatten(rig);
    }
};
