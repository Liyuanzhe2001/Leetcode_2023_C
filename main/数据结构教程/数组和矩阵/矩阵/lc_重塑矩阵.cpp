//
// Created by LiYuanzhe on 2023/9/20.
//
#include "vector"

using namespace std;

class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &mat, int r, int c) {
        if (mat.size() * mat[0].size() != r * c) {
            return mat;
        }
        vector<vector<int>> res(r, vector<int>(c));
        int index = 0;
        for (int i = 0; i < mat.size(); i++) {
            for (int j = 0; j < mat[0].size(); j++) {
                res[index / c][index % c] = mat[i][j];
                index++;
            }
        }
        return res;
    }
};
