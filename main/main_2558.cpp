//
// Created by LiYuanzhe on 2023/10/28.
//

#include "vector"
#include "queue"
#include "cmath"

using namespace std;

class Solution {
public:
    long long pickGifts(vector<int> &gifts, int k) {
        priority_queue<int> q;
        for (const auto &gift: gifts) {
            q.emplace(gift);
        }
        for (int i = 0; i < k; ++i) {
            int tmp = q.top();
            q.pop();
            q.emplace(sqrt(tmp));
        }
        long long res = 0;
        while (!q.empty()) {
            res += q.top();
            q.pop();
        }
        return res;
    }
};