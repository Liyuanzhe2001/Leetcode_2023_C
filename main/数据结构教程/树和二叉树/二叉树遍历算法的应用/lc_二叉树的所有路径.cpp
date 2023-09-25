//
// Created by LiYuanzhe on 2023/9/25.
//

#include "string"
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
    vector<string> res;

    vector<string> binaryTreePaths(TreeNode *root) {
        dfs("", root);
        return res;
    }

    void dfs(string s, TreeNode *root) {
        s = s + "->" + to_string(root->val);
        if (!root->left && !root->right) {
            res.emplace_back(s.substr(2));
            return;
        }
        if (root->left) {
            dfs(s, root->left);
        }
        if (root->right) {
            dfs(s, root->right);
        }
    }

};