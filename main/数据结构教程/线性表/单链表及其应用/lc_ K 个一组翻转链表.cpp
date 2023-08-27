//
// Created by LiYuanzhe on 2023/8/27.
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
        ListNode *pre = nullptr;
        ListNode *curr = head;
        while (curr) {
            ListNode *tmp = curr->next;
            curr->next = pre;
            pre = curr;
            curr = tmp;
        }
        return pre;
    }

    ListNode *reverseKGroup(ListNode *head, int k) {
        int n = 1;
        ListNode *preTail = new ListNode();
        ListNode *res = preTail;
        ListNode *partHead = head;
        while (head) {
            if (n % k != 0) {
                head = head->next;
            } else {
                ListNode *nex = head->next;
                head->next = nullptr;
                ListNode *revList = reverseList(partHead);
                preTail->next = revList;
                while (revList->next) {
                    revList = revList->next;
                }
                revList->next = nex;
                preTail = revList;
                partHead = nex;
                head = nex;
            }
            n++;
        }
        return res->next;
    }
};