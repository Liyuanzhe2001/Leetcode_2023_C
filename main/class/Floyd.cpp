//
// Created by LiYuanzhe on 2023/11/12.
//
#include "algorithm"
#include "vector"

using namespace std;

class FloydAlgorithm {
public:
    FloydAlgorithm(int n, vector<tuple<int, int, int>> roads) {
        map.resize(n, vector<int>(n, INT_MAX));
        this->len = n;
        for (int i = 0; i < n; i++) {
            map[i][i] = 0;
        }
        for (const auto &[n1, n2, len]: roads) {
            map[n1][n2] = map[n2][n1] = len;
        }
        for (int k = 0; k < n; k++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    map[i][j] = min(map[i][j], map[i][k] + map[k][j]);
                }
            }
        }
    }

    int getLen(int node1, int node2) {
        if (node1 < 0 || node1 >= len || node2 < 0 || node2 >= len || map[node1][node2] == INT_MAX) {
            return -1;
        }
        return map[node1][node2];
    }

private:
    vector<vector<int>> map;
    int len;

};
