//
// Created by LiYuanzhe on 2023/9/22.
//
#include "queue"

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
    int minDepth(TreeNode *root) {
        if (!root) {
            return 0;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        int n = 0;
        while (!q.empty()) {
            n++;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (!node->left && !node->right) {
                    return n;
                }
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
        }
        return n;
    }
};