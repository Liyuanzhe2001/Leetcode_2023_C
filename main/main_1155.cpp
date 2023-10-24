//
// Created by LiYuanzhe on 2023/10/24.
//
#include "vector"

using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> f(n + 1, vector<int>(target + 1));
        f[0][0] = 1;
        for (int i = 1; i <= n; ++i) {
            for (int j = 0; j <= target; ++j) {
                for (int x = 1; x <= k; ++x) {
                    if (j - x >= 0) {
                        f[i][j] = (f[i][j] + f[i - 1][j - x]) % mod;
                    }
                }
            }
        }
        return f[n][target];
    }

private:
    static constexpr int mod = 1000000007;
};

