//
// Created by LiYuanzhe on 2023/8/25.
//

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
#include "algorithm"
#include "iostream"

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
    int res = 0;

    int goodNodes(TreeNode *root) {
        dfs(root->val, root);
        return res;
    }

    void dfs(int preMaxV, TreeNode *node) {
        if (node == nullptr) {
            return;
        }
        if (preMaxV <= node->val) {
            res++;
        }
        preMaxV = max(preMaxV, node->val);
        dfs(preMaxV, node->right);
        dfs(preMaxV, node->left);
    }
};
