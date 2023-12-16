//
// Created by LiYuanzhe on 2023/12/17.
//
#include "vector"

using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int> &cost) {
        int ppre = 0, pre = cost[0], res = cost[0];
        for (int i = 1; i < cost.size(); i++) {
            res = min(pre + cost[i], ppre + cost[i]);
            ppre = pre;
            pre = res;
        }
        return min(res, ppre);
    }
};