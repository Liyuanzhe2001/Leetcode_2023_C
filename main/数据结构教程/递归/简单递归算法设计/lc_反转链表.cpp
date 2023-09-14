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
    ListNode *reverseList(ListNode *head) {
        ListNode *headNode = new ListNode;
        while (head) {
            auto *tmpNode = new ListNode(head->val);
            tmpNode->next = headNode->next;
            headNode->next = tmpNode;
            head = head->next;
        }
        return headNode->next;
    }
};
