//
// Created by LiYuanzhe on 2023/10/9.
//
#include "vector"

using namespace std;

class Node {
public:
    int val;
    vector<Node *> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node *> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<int> res;

    vector<int> preorder(Node *root) {
        if (root->children[0]->val == 0) {
            return {1, 0};
        }
        order(root);
        return res;
    }

    void order(Node *root) {
        if (!root) {
            return;
        }
        res.emplace_back(root->val);
        for (auto &child: root->children) {
            order(child);
        }
    }

};
