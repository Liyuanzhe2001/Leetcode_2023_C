//
// Created by LiYuanzhe on 2023/9/14.
//

#include "vector"

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
    bool isPalindrome(ListNode *head) {
        vector<int> v;
        while (head) {
            v.push_back(head->val);
            head = head->next;
        }
        int lef = 0;
        int rig = v.size() - 1;
        while (lef < rig) {
            if (v[lef] != v[rig]) {
                return false;
            }
            lef++;
            rig--;
        }
        return true;
    }
};
