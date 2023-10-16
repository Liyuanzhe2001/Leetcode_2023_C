//
// Created by LiYuanzhe on 2023/10/16.
//

#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>> &grid) {
        queue<pair<int, int>> q;
        int sum = 0;
        int m = grid.size();
        int n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    q.emplace(i, j);
                }
                if (grid[i][j] == 1) {
                    sum++;
                }
            }
        }
        if (sum == 0) {
            return 0;
        }
        int distance[4][2] = {{1,  0},
                              {0,  1},
                              {-1, 0},
                              {0,  -1}};
        int res = 0;
        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; i++) {
                pair<int, int> p = q.front();
                q.pop();
                int x = p.first;
                int y = p.second;
                for (const auto &d: distance) {
                    if (x + d[0] >= 0 && x + d[0] < m && y + d[1] >= 0 && y + d[1] < n &&
                        grid[x + d[0]][y + d[1]] == 1) {
                        q.emplace(x + d[0], y + d[1]);
                        grid[x + d[0]][y + d[1]] = 2;
                        sum--;
                    }
                }
            }
            res++;
        }
        return sum == 0 ? res - 1 : -1;
    }
};
