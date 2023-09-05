//
// Created by LiYuanzhe on 2023/9/5.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minNumber(vector<int> &nums1, vector<int> &nums2) {
        int res = 100;
        for (const auto &i: nums1) {
            for (const auto &j: nums2) {
                res = min(i * 10 + j, res);
                res = min(j * 10 + i, res);
                if (i == j) {
                    res = min(i, res);
                }
            }
        }
        return res;
    }
};

//Arrays.sort(nums1);
//Arrays.sort(nums2);
//for (int i : nums1) {
//for (int j : nums2) {
//if (i == j) {
//return i;
//}
//}
//}
//int n1 = nums1[0];
//int n2 = nums2[0];
//if (n1 > n2) {
//int tmp = n1;
//n1 = n2;
//n2 = tmp;
//}
//return n1 * 10 + n2;
