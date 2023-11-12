//
// Created by LiYuanzhe on 2023/11/12.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> map(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; ++i) {
            map[i][i] = 0;
        }
        for (const auto &edge: edges) {
            map[edge[0]][edge[1]] = map[edge[1]][edge[0]] = edge[2];
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    if (map[i][k] != INT_MAX && map[k][j] != INT_MAX && map[i][k] + map[k][j] < map[i][j]) {
                        map[i][j] = map[i][k] + map[k][j];
                    }
                }
            }
        }
        int resIndex = 0;
        int resVal = n;
        for (int i = 0; i < n; i++) {
            int tmp = 0;
            for (int j = 0; j < n; j++) {
                if (i != j && map[i][j] <= distanceThreshold) {
                    tmp++;
                }
            }
            if (tmp <= resVal) {
                resVal = tmp;
                resIndex = i;
            }
        }
        return resIndex;
    }
};
