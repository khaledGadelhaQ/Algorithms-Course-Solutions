#include <bits/stdc++.h>
using namespace std;

#include <vector>

class Solution {
public:
    vector<vector<bool>> board;
    int res = 0;

    bool isSafe(int row, int col, int n) {
        // Check if there is a queen in the same column
        for (int i = 0; i < row; ++i) {
            if (board[i][col]) {
                return false;
            }
        }

        // Check if there is a queen in the left diagonal
        for (int i = row, j = col; i >= 0 && j >= 0; --i, --j) {
            if (board[i][j]) {
                return false;
            }
        }

        // Check if there is a queen in the right diagonal
        for (int i = row, j = col; i >= 0 && j < n; --i, ++j) {
            if (board[i][j]) {
                return false;
            }
        }

        return true;
    }

    void solve(int row, int n) {
        if (row == n) {
            res += 1;
            return;
        }

        for (int col = 0; col < n; col++) {
            if (isSafe(row, col, n)) {
                board[row][col] = true;
                solve(row + 1, n);
                board[row][col] = false;
            }
        }
    }

    int totalNQueens(int n) {
        board = vector<vector<bool>>(n, vector<bool>(n, false));
        solve(0, n);
        return res;
    }
};
