//
// Created by LiYuanzhe on 2023/8/25.
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
    ListNode *removeElements(ListNode *head, int val) {
        if (!head) {
            return nullptr;
        }
        if (head->val == val) {
            return removeElements(head->next, val);
        }
        head->next = removeElements(head->next, val);
        return head;
    }
};