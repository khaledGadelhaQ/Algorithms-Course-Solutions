#include <bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7;
int ROW, COL;
int dr[4] = {1, -1, 0, 0}; // directional arrays
int dc[4] = {0, 0, 1, -1};
int memo[51][51][51];

class Solution {
public:
    int ans(int r, int c, int maxMove) {
        if (maxMove == -1) // no more allowed moves = 0 
            return 0;
        if (r < 0 || c < 0 || r >= ROW || c >= COL) // out of the boundaries = one path  
            return 1;
        return memo[r][c][maxMove];
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        ROW = m, COL = n;
        memset(memo, 0, sizeof(memo)); // Initialize memo array to 0

        for (int moves = 1; moves <= maxMove; moves++) {
            for (int r = 0; r < m; r++) {
                for (int c = 0; c < n; c++) {
                    for (int d = 0; d < 4; d++) {
                        memo[r][c][moves] = (memo[r][c][moves] + ans(r + dr[d], c + dc[d], moves - 1)) % MOD;
                    }
                }
            }
        }
        return memo[startRow][startColumn][maxMove];
    }
};
