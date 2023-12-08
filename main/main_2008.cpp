//
// Created by LiYuanzhe on 2023/12/8.
//
#include "vector"
#include "algorithm"
#include "unordered_map"

using namespace std;

class Solution {
public:
    long long maxTaxiEarnings(int n, vector<vector<int>> &rides) {
        unordered_map<int, vector<int>> map;
        vector<long long> dp(n + 1);
        for (int i = 0; i < rides.size(); i++) {
            map[rides[i][1]].emplace_back(i);
        }
        for (int i = 1; i <= n; i++) {
            dp[i] = dp[i - 1];
            for (const auto &rideIdx: map[i]) {
                dp[i] = max(dp[i], dp[rides[rideIdx][0]] + rides[rideIdx][1] - rides[rideIdx][0] + rides[rideIdx][2]);
            }
        }
        return dp[n];
    }
};
