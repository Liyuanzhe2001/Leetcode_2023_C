////
//// Created by LiYuanzhe on 2023/12/22.
////
//// TODO 1671
//#include "vector"
//
//using namespace std;
//
//class Solution {
//public:
//    int minimumMountainRemovals(vector<int> &nums) {
//        int n = nums.size();
//        vector<int> suf(n), g;
//        for (int i = n - 1; i; i--) {
//            int x = nums[i];
//            auto it = lower_bound(g.begin(), g.end(), x);
//            suf[i] = it - g.begin() + 1; // 从 nums[i] 开始的最长严格递减子序列的长度
//            if (it == g.end()) {
//                g.push_back(x);
//            } else {
//                *it = x;
//            }
//        }
//
//        int mx = 0;
//        g.clear();
//        for (int i = 0; i < n - 1; i++) {
//            int x = nums[i];
//            auto it = lower_bound(g.begin(), g.end(), x);
//            int pre = it - g.begin() + 1; // 在 nums[i] 结束的最长严格递增子序列的长度
//            if (it == g.end()) {
//                g.push_back(x);
//            } else {
//                *it = x;
//            }
//            if (pre >= 2 && suf[i] >= 2) {
//                mx = max(mx, pre + suf[i] - 1); // 减去重复的 nums[i]
//            }
//        }
//        return n - mx;
//    }
//};
