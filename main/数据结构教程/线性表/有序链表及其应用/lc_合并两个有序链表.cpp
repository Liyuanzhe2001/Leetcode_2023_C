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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2) {
        if (!list1 && !list2) {
            return nullptr;
        }
        if (list1 && !list2) {
            return list1;
        }
        if (!list1 && list2) {
            return list2;
        }
        ListNode *res = new ListNode();
        if (list1->val >= list2->val) {
            res->val = list2->val;
            res->next = mergeTwoLists(list1, list2->next);
        } else {
            res->val = list1->val;
            res->next = mergeTwoLists(list1->next, list2);
        }
        return res;
    }
};