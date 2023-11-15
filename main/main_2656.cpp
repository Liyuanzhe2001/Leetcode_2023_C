//
// Created by LiYuanzhe on 2023/11/15.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int maximizeSum(vector<int> &nums, int k) {
        int m = *max_element(nums.begin(), nums.end());
        return k * m + k * (k - 1) / 2;
    }
};