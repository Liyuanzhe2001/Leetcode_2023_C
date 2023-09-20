//
// Created by LiYuanzhe on 2023/9/20.
//
#include "vector"

using namespace std;

class Solution {
public:
    void moveZeroes(vector<int> &nums) {
        int lef = 0;
        int rig = 0;
        while (rig < nums.size()) {
            if (nums[rig] != 0) {
                nums[lef] = nums[rig];
                lef++;
                rig++;
            } else {
                rig++;
            }
        }
        while (lef < nums.size()) {
            nums[lef++] = 0;
        }
    }
};
