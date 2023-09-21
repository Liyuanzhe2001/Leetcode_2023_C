//
// Created by LiYuanzhe on 2023/9/11.
//

#include "iostream"
#include "string"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

ListNode *cal(ListNode *node, int x) {
    if (!node) {
        return nullptr;
    }
    if (node->val == x) {
        return cal(node->next, x);
    } else {
        node->next = cal(node->next, x);
        return node;
    }
}

int main() {
    ListNode *node1 = new ListNode(1);
    ListNode *node2 = new ListNode(2);
    ListNode *node3 = new ListNode(2);
    ListNode *node4 = new ListNode(12);
    ListNode *node5 = new ListNode(2);
    ListNode *node6 = new ListNode(3);
    node1->next = node2;
    node2->next = node3;
    node3->next = node4;
    node4->next = node5;
    node5->next = node6;
    cal(node1, 2);
    while (node1) {
        cout << node1->val << " ";
        node1 = node1->next;
    }
    cout << endl;

}


