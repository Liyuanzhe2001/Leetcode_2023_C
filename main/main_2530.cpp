//
// Created by LiYuanzhe on 2023/10/18.
//
#include "vector"
#include "cmath"
#include "queue"

using namespace std;

class Solution {
public:
    long long maxKelements(vector<int> &nums, int k) {
        priority_queue<int, vector<int>, less<>> q;
        for (const auto &item: nums) {
            q.emplace(item);
        }
        long long res = 0;
        for (int i = 0; i < k; ++i) {
            int n = q.top();
            q.pop();
            res += n;
            q.emplace(ceil(n / 3.0));
        }
        return res;
    }
};
