////
//// Created by LiYuanzhe on 2023/10/4.
////
//#include "vector"
//#include "algorithm"
//
//using namespace std;
//
//
//class Solution {
//public:
//    int maxProfit(int k, vector<int> &prices) {
//        k = min<int>(k, prices.size() / 2) + 1;
//        vector buy(k, INT_MIN), sel(k, 0);
//        for (int i: prices) {
//            for (int j = 1; j < k; j++) {
//                buy[j] = max(buy[j], sel[j - 1] - i);
//                sel[j] = max(sel[j], buy[j] + i);
//            }
//        }
//        return sel.back();
//    }
//};