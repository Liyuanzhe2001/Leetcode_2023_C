//
// Created by LiYuanzhe on 2023/9/14.
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
    ListNode *swapPairs(ListNode *head) {
        if (!head || !head->next) {
            return head;
        }
        ListNode *headNode = new ListNode;
        ListNode *preNode = headNode;
        ListNode *node1 = head;
        while (node1 && node1->next) {
            ListNode *tmp = node1->next->next;
            preNode->next = node1->next;
            node1->next->next = node1;
            node1->next = tmp;
            preNode = node1;
            node1 = node1->next;
        }
        return headNode->next;
    }
};
