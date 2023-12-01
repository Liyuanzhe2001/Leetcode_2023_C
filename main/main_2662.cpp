//
// Created by LiYuanzhe on 2023/12/1.
//
#include "vector"
#include "unordered_map"

using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int> &arr, vector<vector<int>> &mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> rows(m);
        vector<int> columns(n);
        unordered_map<int, vector<int>> map;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                map[mat[i][j]] = {i, j};
            }
        }
        for (int i = 0; i < m; i++) {
            int row = map[arr[i]][0];
            int column = map[arr[i]][1];
            rows[row]++;
            columns[column]++;
            if (rows[row] == n || columns[column] == m) {
                return i;
            }
        }
        return arr.size() - 1;
    }
};
