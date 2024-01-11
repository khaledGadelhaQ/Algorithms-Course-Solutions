#include <bits/stdc++.h>
using namespace std;


const int MAX = 101;
int memo[MAX][MAX];
class Solution {
private:
    int ROW,COL;
    int dp(int r , int c, vector<vector<int>>& obstacleGrid){
        if(r > ROW || c > COL || obstacleGrid[r][c])
            return 0;
        if(r == ROW && c == COL)
            return 1;

        auto &ref = memo[r][c];
        if(ref != -1)
            return ref;

        int down = dp(r+1,c, obstacleGrid);
        int right = dp(r,c+1, obstacleGrid);

        return ref = down + right;
    }
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        ROW = obstacleGrid.size() - 1;
        COL = obstacleGrid[0].size()- 1;
        memset(memo, -1, sizeof(memo));
        return dp(0,0,obstacleGrid);
    }
};
