#include<iostream>
#include <bits/stdc++.h>

using namespace std;

class Solution {
private:
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {-1, 1, 0, 0};

public:
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        /*
        we iterate on the grid2 calculating the possible islands
        and keeping the index in an array
        then we check if this index is in grid1 if it is all
        exits we now have a new sub-island
        -> We will make a boolean function 'visited' to not 
        repeat the conditions
        -> We do the previous structure on all the nodes in the grid2
        */
        int R = grid2.size(), C = grid2[0].size();
        vector<vector<bool>> visited(R, vector<bool>(C));
        int sum = 0;

        for (int i = 0; i < R; i++) {
            for (int j = 0; j < C; j++) {
                if (grid2[i][j] == 0 || visited[i][j]) continue;
                vector<pair<int, int>> island;
                dfs(i, j, visited, island, grid2);
                sum += checkPossibleSubIsland(grid1, island);

            }
        }
        return sum;
    }

    void dfs(int r, int c, vector<vector<bool>>& visited,
    vector<pair<int, int>>& island, vector<vector<int>>& grid2) {
        island.push_back({r, c});
        visited[r][c] = true;

        for (int i = 0; i < 4; i++) {
            int nr = r + dr[i], nc = c + dc[i];
            if (nr < 0 || nr >= grid2.size() ||
             nc < 0 || nc >= grid2[0].size() ||
              grid2[nr][nc] == 0 || visited[nr][nc]) {
                continue;
            }
            dfs(nr, nc, visited, island, grid2);
        }
    }

    int checkPossibleSubIsland(vector<vector<int>>& grid1, vector<pair<int, int>>& island) {
        for (auto& p : island) {
            int r = p.first, c = p.second;
            if (grid1[r][c] == 0) {
                return 0;
            }
        }
        return 1;
    }
};
