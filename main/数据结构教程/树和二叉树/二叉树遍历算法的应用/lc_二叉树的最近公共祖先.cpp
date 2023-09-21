//
// Created by LiYuanzhe on 2023/9/21.
//

#include "iostream"

using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;

    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode *res;

    TreeNode *lowestCommonAncestor(TreeNode *root, TreeNode *p, TreeNode *q) {
        dfs(root, p, q);
        return res;
    }

    bool dfs(TreeNode *node, TreeNode *node1, TreeNode *node2) {
        if (!node) {
            return false;
        }
        bool lFlag = dfs(node->left, node1, node2);
        bool rFlag = dfs(node->right, node1, node2);
        if (lFlag && rFlag || ((lFlag || rFlag) && (node->val == node1->val || node->val == node2->val))) {
            res = node;
        }
        return lFlag || rFlag || node->val == node1->val || node->val == node2->val;
    }
};