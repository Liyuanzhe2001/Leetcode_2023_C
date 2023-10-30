//
// Created by LiYuanzhe on 2023/10/30.
//
#include "vector"
#include "algorithm"

using namespace std;

class Solution {
public:
    void Floyd(vector<vector<int>> &distances, int n) {
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (distances[i][k] != INT_MAX && distances[k][j] != INT_MAX &&
                        distances[i][k] + distances[k][j] < distances[i][j]) {
                        distances[i][j] = distances[i][k] + distances[k][j];
                    }
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<int>> distances(n, vector<int>(n, INT_MAX));
        for (int i = 0; i < n; i++) {
            distances[i][i] = 0;
        }
        for (const auto &edge: edges) {
            int u = edge[0], v = edge[1], w = edge[2];
            distances[u][v] = distances[v][u] = w;
        }
        Floyd(distances, n);
        int index = -1, minCount = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int count = 0;
            for (int j = 0; j < n; ++j) {
                if (distances[i][j] <= distanceThreshold && i != j) {
                    count++;
                }
            }
            if (count <= minCount) {
                minCount = count;
                index = i;
            }
        }
        return index;
    }
};