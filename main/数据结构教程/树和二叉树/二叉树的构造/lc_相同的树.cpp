//
// Created by LiYuanzhe on 2023/10/7.
//
#include "vector"
#include "algorithm"

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
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        this->nums = nums;
        return build(0, this->nums.size());
    }

    TreeNode *build(int start, int end) {
        int n = end - start;
        if (!n) {
            return nullptr;
        }
        int index = -1;
        int max = INT_MIN;
        for (int i = 0; i < end - start; i++) {
            if (max < nums[start + i]) {
                index = start + i;
                max = nums[start + i];
            }
        }
        auto root = new TreeNode(max);
        if (n == 1) {
            return root;
        }

        root->left = build(start, index);
        root->right = build(index + 1, end);
        return root;
    }

private:
    vector<int> nums;
};
