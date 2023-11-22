//
// Created by LiYuanzhe on 2023/11/22.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int minPathCost(vector<vector<int>> &grid, vector<vector<int>> &moveCost) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> f(m, vector<int>(n, INT_MAX));
        f[m - 1] = grid[m - 1];
        for (int i = m - 2; i >= 0; i--) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) { // 移动到下一行的第 k 列
                    f[i][j] = min(f[i][j], f[i + 1][k] + moveCost[grid[i][j]][k]);
                }
                f[i][j] += grid[i][j];
            }
        }
        return *min_element(f[0].begin(), f[0].end());
    }
};