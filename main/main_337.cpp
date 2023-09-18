//
// Created by LiYuanzhe on 2023/9/18.
//

#include "unordered_map"

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

    unordered_map<TreeNode*,int> map;

    int rob(TreeNode* root) {
        if (!root) {
            return 0;
        }
        if (map.count(root)) {
            return map[root];
        }
        int money = root->val;
        if (root->left) {
            money += rob(root->left->left) + rob(root->left->right);
        }
        if (root->right) {
            money += rob(root->right->right) + rob(root->right->left);
        }
        int res = max(money, rob(root->left) + rob(root->right));
        map[root] = res;
        return res;
    }
};