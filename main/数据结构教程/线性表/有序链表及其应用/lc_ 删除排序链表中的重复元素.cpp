//
// Created by LiYuanzhe on 2023/8/30.
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* pre = new ListNode(-101);
        ListNode* res = pre;
        while (head) {
            if(head->val != pre->val) {
                pre->next = head;
                pre = pre->next;
            }
            head = head->next;
        }
        pre->next = nullptr;
        return res->next;
    }
};