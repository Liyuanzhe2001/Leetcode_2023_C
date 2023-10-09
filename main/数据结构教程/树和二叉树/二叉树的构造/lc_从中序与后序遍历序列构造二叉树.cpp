//
// Created by LiYuanzhe on 2023/10/9.
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
    TreeNode *buildTree(vector<int> &inorder, vector<int> &postorder) {
        in = inorder;
        post = postorder;
        return build(0, in.size(), 0, post.size());
    }

    TreeNode *build(int inBegin, int inEnd, int postBegin, int postEnd) {
        int n = inEnd - inBegin;
        if (!n) {
            return nullptr;
        }
        auto *root = new TreeNode(post[postEnd - 1]);
        if (n == 1) {
            return root;
        }
        int l = 0;
        for (int i = 0; i < inEnd - inBegin; i++) {
            if (in[inBegin + i] == post[postEnd - 1]) {
                l = i;
                break;
            }
        }
        root->left = build(inBegin, inBegin + l, postBegin, postBegin + l);
        root->right = build(inBegin + l + 1, inEnd, postBegin + l, postEnd - 1);
        return root;
    }

private:
    vector<int> in;
    vector<int> post;

};
