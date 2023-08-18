#include "algorithm"
#include "iostream"
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

    vector<int> v;
    int i;

    Solution(ListNode *head) {
        while (head) {
            v.emplace_back(head->val);
            head = head->next;
        }
        i = 0;
    }

    int getRandom() {
        return v[rand() % v.size()];
    }
};