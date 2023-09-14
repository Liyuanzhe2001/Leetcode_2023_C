//
// Created by LiYuanzhe on 2023/9/14.
//
#include "string"
#include "vector"
#include "functional"

using namespace std;

class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<int> col(n), on_path(n), diag1(n * 2 - 1), diag2(n * 2 - 1);
        function<void(int)> dfs = [&](int r) {
            if (r == n) {
                vector<string> board(n);
                for (int i = 0; i < n; ++i)
                    board[i] = string(col[i], '.') + 'Q' + string(n - 1 - col[i], '.');
                ans.emplace_back(board);
                return;
            }
            for (int c = 0; c < n; ++c) {
                int rc = r - c + n - 1;
                if (!on_path[c] && !diag1[r + c] && !diag2[rc]) {
                    col[r] = c;
                    on_path[c] = diag1[r + c] = diag2[rc] = true;
                    dfs(r + 1);
                    on_path[c] = diag1[r + c] = diag2[rc] = false; // 恢复现场
                }
            }
        };
        dfs(0);
        return ans;
    }
};