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
    bool isCousins(TreeNode *root, int x, int y) {
        queue<TreeNode *> q;
        q.emplace(root);
        int n = 0;
        while (!q.empty()) {
            n = 0;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->val == x || node->val == y) {
                    n++;
                }
                int lef = 0;
                if (node->left) {
                    q.emplace(node->left);
                    lef = node->left->val;
                }
                int rig = 0;
                if (node->right) {
                    q.emplace(node->right);
                    rig = node->right->val;
                }
                if ((lef == x || lef == y) && (rig == x || rig == y)) {
                    return false;
                }
            }
            if (n == 2) {
                return true;
            }
            if (n == 1) {
                return false;
            }
        }
        return false;
    }
};
