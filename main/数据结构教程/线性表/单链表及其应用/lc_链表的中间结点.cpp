//
// Created by LiYuanzhe on 2023/8/26.
//


struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *middleNode(ListNode *head) {
        ListNode *node = head;
        while (node && node->next) {
            node = node->next->next;
            head = head->next;
        }
        return head;
    }
};