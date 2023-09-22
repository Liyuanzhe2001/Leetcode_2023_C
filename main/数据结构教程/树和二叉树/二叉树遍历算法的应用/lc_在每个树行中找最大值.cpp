//
// Created by LiYuanzhe on 2023/9/22.
//
#include "vector"
#include "algorithm"
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
    vector<int> largestValues(TreeNode *root) {
        vector<int> res;
        if (!root) {
            return res;
        }
        queue<TreeNode *> q;
        q.emplace(root);
        int maxV;
        while (!q.empty()) {
            maxV = q.front()->val;
            int s = q.size();
            for (int i = 0; i < s; i++) {
                TreeNode *node = q.front();
                q.pop();
                if (node->left) {
                    q.emplace(node->left);
                }
                if (node->right) {
                    q.emplace(node->right);
                }
                maxV = max(node->val, maxV);
            }
            res.emplace_back(maxV);
        }
        return res;
    }
};
