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
    bool isSymmetric(TreeNode *root) {
        return compare(root->left, root->right);
    }

    bool compare(TreeNode *node1, TreeNode *node2) {
        if (!node1 || !node2) {
            if (!node1 && !node2) {
                return true;
            }
            return false;
        }
        if (node1->val != node2->val) {
            return false;
        }
        return compare(node1->left, node2->right) && compare(node1->right, node2->left);
    }
};
