#include <bits/stdc++.h>
using namespace std;

class Solution {
private:
    int memo[305][305];
    int ROW,COL;
    int dp(int r, int c, vector<vector<char>>& matrix){
        if(r == ROW || c == COL || matrix[r][c] == '0') // out of the boundries, or zero   
            return 0;
        auto &ref = memo[r][c];
        if(ref != -1)
            return ref;
        ref = 0 ;
        int right = dp(r,c+1,matrix);
        int down = dp(r+1,c,matrix);
        int diagonal = dp(r+1,c+1,matrix);
        return ref = 1 + min({right,down,diagonal}); // return the maximum valued side of the square
    }
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        ROW = matrix.size(), COL = matrix[0].size();
        memset(memo, -1, sizeof(memo));
        int res = INT_MIN;
        for( int r = 0 ; r < ROW ; r++){
            for(int c  = 0 ; c < COL ; c++){
                res = max(res, dp(r,c,matrix));
            }
        }
        return res * res;
    }
};