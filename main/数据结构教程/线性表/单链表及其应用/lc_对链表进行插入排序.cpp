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
        ListNode* root = new ListNode();
        root->next = head;

        ListNode* nex;
        while (head){
            nex = head->next;
            
        }

    }
};