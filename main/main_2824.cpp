//
// Created by LiYuanzhe on 2023/11/24.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int countPairs(vector<int> &nums, int target) {
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 1; i < nums.size(); i++) {
            int l = 0, r = i - 1;
            while (l < r) {
                int mid = (l + r + 1) >> 1;
                if (nums[mid] + nums[i] < target) {
                    l = mid;
                } else {
                    r = mid - 1;
                }
            }
            if (nums[r] + nums[i] < target) {
                res += r + 1;
            }
        }
        return res;
    }
};
