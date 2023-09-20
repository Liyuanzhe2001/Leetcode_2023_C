//
// Created by LiYuanzhe on 2023/9/20.
//

#include "vector"

using namespace std;

class Solution {
public:
    int majorityElement(vector<int> &nums) {
        int res = nums[0];
        int n = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == res) {
                n++;
            } else {
                n--;
            }
            if (n < 0) {
                res = nums[i];
                n = 1;
            }
        }
        return res;
    }
};