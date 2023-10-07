//
// Created by LiYuanzhe on 2023/9/27.
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
    TreeNode *constructFromPrePost(vector<int> &preorder, vector<int> &postorder) {
        this->pre = preorder;
        this->post = postorder;
        return build(0, pre.size(), 0, post.size());
    }

    TreeNode *build(int preBegin, int preEnd, int postBegin, int postEnd) {
        int n = preEnd - preBegin;
        if (!n) {
            return nullptr;
        }
        auto *root = new TreeNode(pre[preBegin]);
        if (n == 1) {
            return root;
        }

        int L = 0;
        for (int i = 0; i < postEnd - postBegin; i++) {
            if (post[postBegin + i] == pre[preBegin + 1]) {
                L = i + 1;
                break;
            }
        }
        root->left = build(preBegin + 1, preBegin + L + 1, postBegin, postBegin + L);
        root->right = build(preBegin + L + 1, preEnd, postBegin + L, postEnd - 1);
        return root;
    }

private:
    vector<int> pre;
    vector<int> post;
};
