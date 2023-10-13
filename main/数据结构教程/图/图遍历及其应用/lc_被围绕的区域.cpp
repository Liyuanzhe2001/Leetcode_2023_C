//
// Created by LiYuanzhe on 2023/10/13.
//
#include "vector"

using namespace std;

class Solution {
public:
    void solve(vector<vector<char>> &board) {
        int m = board.size();
        int n = board[0].size();
        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') {
                dfs(board, i, 0, 'A');
            }
            if (board[i][n - 1] == 'O') {
                dfs(board, i, n - 1, 'A');
            }
        }
        for (int i = 0; i < n; i++) {
            if (board[0][i] == 'O') {
                dfs(board, 0, i, 'A');
            }
            if (board[m - 1][i] == 'O') {
                dfs(board, m - 1, i, 'A');
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') {
                    dfs(board, i, j, 'X');
                }
            }
        }
        for (auto &i: board) {
            for (char &j: i) {
                if (j == 'A') {
                    j = 'O';
                }
            }
        }
    }

    void dfs(vector<vector<char>> &board, int x, int y, char c) {
        if (x < 0 || x >= board.size() || y < 0 || y >= board[x].size() || board[x][y] != 'O') {
            return;
        }
        board[x][y] = c;
        dfs(board, x + 1, y, c);
        dfs(board, x - 1, y, c);
        dfs(board, x, y + 1, c);
        dfs(board, x, y - 1, c);
    }
};