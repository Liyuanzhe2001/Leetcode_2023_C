//
// Created by LiYuanzhe on 2023/8/25.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


#include "iostream"

using namespace std;

class Solution {
public:
    ListNode *reverseList(ListNode *head) {
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
    }

    ListNode *reverseBetween(ListNode *head, int left, int right) {
        if (left != 1) {
            head->next = reverseBetween(head->next, left - 1, right - 1);
            return head;
        }

        ListNode* root = head;
        for (int i = 1; i < right; i++) {
            head = head->next;
        }

        ListNode *tmp = head->next;
        head->next = nullptr;
        ListNode *rootR = reverseList(root);
        ListNode *headPart = rootR;
        while (headPart->next) {
            headPart = headPart->next;
        }
        headPart->next = tmp;
        return rootR;
    }
};