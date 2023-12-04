//
// Created by LiYuanzhe on 2023/12/4.
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
    TreeNode *bstToGst(TreeNode *root) {
        dfs(root);
        return root;
    }

    void dfs(TreeNode *node) {
        if (!node) {
            return;
        }
        dfs(node->right);
        pre = pre + node->val;
        node->val = pre;
        dfs(node->left);
    }

private:
    int pre = 0;
};
