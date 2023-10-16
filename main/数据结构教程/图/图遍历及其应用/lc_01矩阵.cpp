//
// Created by LiYuanzhe on 2023/10/16.
//
#include "vector"
#include "queue"

using namespace std;

class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>> &mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, 0));
        int distance[4][2] = {{1,  0},
                              {0,  1},
                              {-1, 0},
                              {0,  -1}};
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (!mat[i][j]) {
                    q.emplace(i, j);
                    visited[i][j] = true;
                }
            }
        }

        while (!q.empty()) {
            int s = q.size();
            for (int i = 0; i < s; ++i) {
                pair<int, int> p = q.front();
                q.pop();
                for (const auto &item: distance) {
                    int x = p.first + item[0];
                    int y = p.second + item[1];
                    if (x >= 0 && x < m && y >= 0 && y < n && !visited[x][y]) {
                        res[x][y] = res[p.first][p.second] + 1;
                        q.emplace(x, y);
                        visited[x][y] = true;
                    }
                }
            }
        }
        return res;
    }
};
