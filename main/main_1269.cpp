//
// Created by LiYuanzhe on 2023/8/24.
//
#include "iostream"
#include "unordered_map"
#include "vector"

using namespace std;

class Solution {
public:
    int countServers(vector<vector<int>> &grid) {
        int m = grid.size();
        int n = grid[0].size();
        unordered_map<int, int> row, col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    row[i]++;
                    col[j]++;
                }
            }
        }
        int res = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1 && (row[i] >= 2 || col[j] >= 2)) {
                    res++;
                }
            }
        }
        return res;
    }
};
