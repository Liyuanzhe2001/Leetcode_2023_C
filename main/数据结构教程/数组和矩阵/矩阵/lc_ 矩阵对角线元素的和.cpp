//
// Created by LiYuanzhe on 2023/9/20.
//

#include "vector"

using namespace std;

class Solution {
public:
    int diagonalSum(vector<vector<int>> &mat) {
        int res = 0;
        for (int i = 0; i < mat.size(); i++) {
            if (mat.size() - 1 - i == i) {
                res += mat[i][i];
            } else {
                res += mat[i][i] + mat[i][mat.size() - 1 - i];
            }
        }
        return res;
    }
};
