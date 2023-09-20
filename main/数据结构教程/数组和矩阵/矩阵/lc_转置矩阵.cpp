//
// Created by LiYuanzhe on 2023/9/20.
//

#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> transpose(vector<vector<int>> &matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> transposed(n, vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                transposed[i][j] = matrix[j][i];
            }
        }
        return transposed;
    }
};
