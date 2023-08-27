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
    ListNode *insertionSortList(ListNode *head) {
        ListNode *root = new ListNode();
        ListNode *rootHead = root;
        while (head) {
            ListNode *nex = head->next;
            ListNode *pre = rootHead;
            root = rootHead->next;
            while (root && head->val > root->val) {
                pre = root;
                root = root->next;
            }
            head->next = pre->next;
            pre->next = head;
            head = nex;
        }
        return rootHead->next;
    }
};