//
// Created by LiYuanzhe on 2023/8/20.
//

#include "vector"

using namespace std;

class Solution {
public:
    int maximizeTheProfit(int n, vector<vector<int>> &offers) {
        vector<vector<pair<int, int>>> v(n);
        for (const auto &offer: offers) {
            v[offer[1]].emplace_back(offer[0], offer[2]);
        }
        int dp[n + 1];
        dp[0] = 0;
        for (int end = 0; end < n; end++) {
            dp[end + 1] = dp[end];
            for (const auto &item: v[end]) {
                dp[end + 1] = max(dp[end + 1], dp[item.first] + item.second);
            }
        }
        return dp[n];
    }
};
