//
// Created by LiYuanzhe on 2023/10/9.
//
#include "vector"
#include "queue"

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
    vector<vector<int>> levelOrder(Node *root) {
        if (!root) {
            return {};
        }
        vector<vector<int>> res;
        queue<Node *> q;
        q.emplace(root);
        while (!q.empty()) {
            int s = q.size();
            vector<int> v;
            for (int i = 0; i < s; i++) {
                Node *node = q.front();
                q.pop();
                for (auto &child: node->children) {
                    q.emplace(child);
                }
                v.emplace_back(node->val);
            }
            res.emplace_back(v);
        }
        return res;
    }
};
