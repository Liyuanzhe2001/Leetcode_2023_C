//
// Created by LiYuanzhe on 2023/9/25.
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
    int findBottomLeftValue(TreeNode *root) {
        int res;
        queue<TreeNode *> q;
        q.emplace(root);
        while (!q.empty()) {
            int s = q.size();
            res = q.front()->val;
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
            }
        }
        return res;
    }
};