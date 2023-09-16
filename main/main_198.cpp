//
// Created by LiYuanzhe on 2023/9/16.
//
#include "vector"

using namespace std;

class Solution {
public:
    int rob(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        int n1 = nums[0];
        int n2 = max(nums[0], nums[1]);
        for (int i = 2; i < nums.size(); i++) {
            int tmp = max(n1 + nums[i], n2);
            n1 = n2;
            n2 = tmp;
        }
        return n2;
    }
};
