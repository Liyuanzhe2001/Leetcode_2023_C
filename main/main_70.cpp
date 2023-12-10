//
// Created by LiYuanzhe on 2023/12/10.
//
class Solution {
public:
    int climbStairs(int n) {
        int pre = 0;
        int res = 1;
        int tmp = 0;
        for (int i = 1; i <= n; ++i) {
            tmp = pre;
            pre = res;
            res = tmp + pre;
        }
        return res;
    }
};
