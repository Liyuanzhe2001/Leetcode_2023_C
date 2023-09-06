////
//// Created by LiYuanzhe on 2023/8/29.
////
//
//#include "iostream"
//#include "algorithm"
//#include "numeric"
//
//using namespace std;
//
//class Solution {
//public:
//    int numFactoredBinaryTrees(vector<int> &arr) {
//        const int MOD = 1e9 + 7;
//        sort(arr.begin(), arr.end());
//        int n = arr.size();
//        unordered_map<int, int> idx;
//        for (int i = 0; i < n; i++) {
//            idx[arr[i]] = i;
//        }
//        vector<long long> f(n, 1);
//        for (int i = 0; i < n; i++) {
//            int val = arr[i];
//            for (int j = 0; j < i; j++) {
//                int x = arr[j];
//                if (1LL * x * x > val) { // 防止乘法溢出
//                    break;
//                }
//                if (x * x == val) {
//                    f[i] += f[j] * f[j];
//                    break;
//                }
//                if (val % x == 0 && idx.count(val / x)) {
//                    f[i] += f[j] * f[idx[val / x]] * 2;
//                }
//            }
//        }
//        return accumulate(f.begin(), f.end(), 0LL) % MOD;
//    }
//};
