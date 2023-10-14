//
// Created by LiYuanzhe on 2023/10/14.
//
#include "vector"

using namespace std;

class Solution {
public:
    int singleNumber(vector<int> &nums) {
        int n = nums.size();
        if (n == 1) {
            return nums[0];
        }
        int res = 0;
        for (const auto &item: nums) {
            res = res ^ item;
        }
        return res;
    }
};
