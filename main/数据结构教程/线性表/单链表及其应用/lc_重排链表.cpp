//
// Created by LiYuanzhe on 2023/8/26.
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
    void reorderList(ListNode *head) {
        vector<ListNode *> v;
        for (ListNode *tmp = head; tmp; tmp = tmp->next) {
            v.emplace_back(tmp);
        }
        int lef = 0;
        int rig = v.size() - 1;
        while (lef < rig) {
            v[lef]->next = v[rig];
            lef++;
            if (lef == rig) {
                break;
            }
            v[rig]->next = v[lef];
            rig--;
        }
        v[lef]->next = nullptr;
    }
};