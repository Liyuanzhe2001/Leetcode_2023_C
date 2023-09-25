//
// Created by LiYuanzhe on 2023/9/25.
//
#include "vector"

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
    vector<vector<int>> res;

    vector<vector<int>> pathSum(TreeNode *root, int targetSum) {
        dfs(vector<int>(), root, targetSum);
        return res;
    }

    void dfs(vector<int> v, TreeNode *root, int targetSum) {
        if (!root) {
            return;
        }
        int val = targetSum - root->val;
        v.emplace_back(root->val);
        if (!root->left && !root->right) {
            if (val == 0) {
                res.emplace_back(v);
            }
            return;
        }
        dfs(v, root->left, val);
        dfs(v, root->right, val);
    }


};
