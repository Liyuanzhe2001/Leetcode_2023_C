//
// Created by LiYuanzhe on 2023/8/26.
//

#include "iostream"
#include "algorithm"

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode() : val(0), next(nullptr) {}

    ListNode(int x) : val(x), next(nullptr) {}

    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode *partition(ListNode *head, int x) {
        ListNode *minListNode = new ListNode();
        ListNode *minHead = minListNode;
        ListNode *largeListNode = new ListNode();
        ListNode *largeHead = largeListNode;
        while (head) {
            if (head->val < x) {
                minListNode->next = new ListNode(head->val);
                minListNode = minListNode->next;
            } else {
                largeListNode->next = new ListNode(head->val);
                largeListNode = largeListNode->next;
            }
            head = head->next;
        }
        minListNode->next = largeHead->next;
        return minHead->next;
    }
};
