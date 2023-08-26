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
    ListNode *swapPairs(ListNode *head) {
        ListNode *pre = head;
        while (pre && pre->next) {
            int tmp = pre->val;
            pre->val = pre->next->val;
            pre->next->val = tmp;
            pre = pre->next->next;
        }
        return head;
    }
};