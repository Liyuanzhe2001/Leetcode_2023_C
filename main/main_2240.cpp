//
// Created by LiYuanzhe on 2023/9/1.
//

class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long n = total / cost1, res = n + 1;
        for (long long i = 0; i <= n; i++) {
            res += (total - cost1 * i) / cost2;
        }
        return res;
    }
};