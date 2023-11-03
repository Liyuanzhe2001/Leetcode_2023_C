//
// Created by LiYuanzhe on 2023/11/3.
//
#include "iostream"
#include "queue"

using namespace std;

class Node {
public:
    int val;
    Node *left;
    Node *right;
    Node *next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node *_left, Node *_right, Node *_next)
            : val(_val), left(_left), right(_right), next(_next) {}
};

class Solution {
public:
    Node *connect(Node *root) {
        if (!root) {
            return root;
        }
        queue<Node *> q;
        q.emplace(root);
        while (!q.empty()) {
            int s = q.size();
            Node *pre = q.front();
            if (pre->left) {
                q.emplace(pre->left);
            }
            if (pre->right) {
                q.emplace(pre->right);
            }
            q.pop();
            for (int i = 0; i < s - 1; ++i) {
                pre->next = q.front();
                pre = q.front();
                if (pre->left) {
                    q.emplace(pre->left);
                }
                if (pre->right) {
                    q.emplace(pre->right);
                }
                q.pop();
            }
        }
        return root;
    }
};