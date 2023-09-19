//
// Created by LiYuanzhe on 2023/9/19.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
    bool check(vector<int> &nums, int k, int mx) {
        int f0 = 0, f1 = 0;
        for (int x: nums) {
            if (x > mx) {
                f0 = f1;
            } else {
                int tmp = f1;
                f1 = max(f1, f0 + 1);
                f0 = tmp;
            }
        }
        return f1 >= k;
    }

public:
    int minCapability(vector<int> &nums, int k) {
        int left = 0, right = *max_element(nums.begin(), nums.end());
        while (left + 1 < right) { // 开区间写法
            int mid = left + (right - left) / 2;
            (check(nums, k, mid) ? right : left) = mid;
        }
        return right;
    }
};