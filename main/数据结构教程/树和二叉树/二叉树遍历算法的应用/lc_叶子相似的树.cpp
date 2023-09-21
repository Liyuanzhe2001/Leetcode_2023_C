//
// Created by LiYuanzhe on 2023/9/21.
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
    bool leafSimilar(TreeNode *root1, TreeNode *root2) {
        vector<int> rootV1;
        cal(rootV1, root1);
        vector<int> rootV2;
        cal(rootV2, root2);
        if (rootV1.size() != rootV2.size()) {
            return false;
        }
        for (int i = 0; i < rootV1.size(); i++) {
            if (rootV1[i] != rootV2[i]) {
                return false;
            }
        }
        return true;
    }

    void cal(vector<int> &v, TreeNode *root) {
        if (!root->left && !root->right) {
            v.emplace_back(root->val);
            return;
        }
        if (root->left)
            cal(v, root->left);
        if (root->right)
            cal(v, root->right);
    }
};