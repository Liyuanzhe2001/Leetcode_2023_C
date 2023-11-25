//
// Created by LiYuanzhe on 2023/11/25.
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
    int pseudoPalindromicPaths(TreeNode *root) {
        vector<int> counter(10);
        return dfs(root, counter);
    }

    int dfs(TreeNode *root, vector<int> &counter) {
        if (root == nullptr) {
            return 0;
        }
        counter[root->val]++;
        int res = 0;
        if (root->left == nullptr && root->right == nullptr) {
            if (isPseudoPalindrome(counter)) {
                res = 1;
            }
        } else {
            res = dfs(root->left, counter) + dfs(root->right, counter);
        }
        counter[root->val]--;
        return res;
    }

    bool isPseudoPalindrome(const vector<int> &counter) {
        int odd = 0;
        for (int value: counter) {
            if (value % 2 == 1) {
                odd++;
            }
        }
        return odd <= 1;
    }
};
