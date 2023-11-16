//
// Created by LiYuanzhe on 2023/11/16.
//
#include "vector"

using namespace std;

class Solution {
public:
    int longestAlternatingSubarray(vector<int> &nums, int threshold) {
        int res = 0;
        int n = nums.size();
        int i = 0;
        while (i < n) {
            if (nums[i] > threshold || nums[i] % 2) {
                i++;
                continue;
            }
            int start = i;
            i++;
            while (i < n && nums[i] < threshold && nums[i] % 2 != nums[i - 1] % 2) {
                i++;
            }
            res = max(res, i - start);
        }
        return res;
    }
};