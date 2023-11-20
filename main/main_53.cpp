//
// Created by LiYuanzhe on 2023/11/20.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int> &nums) {
        int tmp = 0;
        int res = nums[0];
        for (int num: nums) {
            tmp = max(tmp + num, num);
            res = max(res, tmp);
        }
        return res;
    }
};

