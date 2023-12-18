//
// Created by LiYuanzhe on 2023/12/18.
//
#include "vector"

using namespace std;

//class Solution {
//public:
//    int findPeakElement(vector<int> &nums) {
//        int maxIdx = 0;
//        int maxV = nums[maxIdx];
//        for (int i = 1; i < nums.size(); i++) {
//            if (nums[i] > maxV) {
//                maxV = nums[i];
//                maxIdx = i;
//            }
//        }
//        return maxIdx;
//    }
//};

class Solution {
public:
    int findPeakElement(vector<int> &nums) {
        int lef = 0;
        int rig = nums.size() - 1;
        while (lef < rig) {
            int mid = (lef + rig) >> 1;
            if (nums[mid] > nums[mid + 1]) {
                rig = mid;
            } else {
                lef = mid + 1;
            }
        }
        return lef;
    }
};
