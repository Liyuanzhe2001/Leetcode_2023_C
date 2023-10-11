//
// Created by LiYuanzhe on 2023/10/11.
//

#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>> &roads) {
        vector<vector<bool>> thought(n, vector<bool>(n));
        vector<int> roadNums(n);
        for (const auto &item: roads) {
            roadNums[item[0]]++;
            roadNums[item[1]]++;
            thought[item[0]][item[1]] = thought[item[1]][item[0]] = true;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                res = max(res, roadNums[i] + roadNums[j] - thought[i][j] ? 1 : 0);
            }
        }
        return res;
    }
};
