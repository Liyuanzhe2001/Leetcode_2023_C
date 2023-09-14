//
// Created by LiYuanzhe on 2023/9/14.
//

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        if (n == 1) {
            return {{1}};
        }
        vector<vector<int>> res(n, vector<int>(n, 0));
        int dis[][2] = {{0,  1},
                        {1,  0},
                        {0,  -1},
                        {-1, 0}};
        int x = 0;
        int y = 0;
        int i = 0;
        int t = 1;
        while (res[x][y] == 0) {
            res[x][y] = t++;
            if (x + dis[i % 4][0] < 0 || x + dis[i % 4][0] >= n ||
                y + dis[i % 4][1] < 0 || y + dis[i % 4][1] >= n ||
                res[x + dis[i % 4][0]][y + dis[i % 4][1]] != 0) {
                i++;
            }
            x += dis[i % 4][0];
            y += dis[i % 4][1];
        }
        return res;
    }
};
