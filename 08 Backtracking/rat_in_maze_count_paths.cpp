#include <bits/stdc++.h>
using namespace std;

const int MAX = 100;
char grid[MAX][MAX];
int rows, cols;

int dr[4] = {0, 0, 1, -1};
int dc[4] = {1, -1, 0, 0};

int res = 0;

bool valid(int r , int c ){
    if (r < 0 || c < 0 || r >= rows || c >= cols ) return false;
    if(grid[r][c] != '.') return false;
    return true;
}

void dfs(int r, int c) {
    if(r == rows - 1 && c == cols - 1){
        res += 1 ;
        return;
    } 

    for (int d = 0; d < 4; d++) {
        int nr = dr[d] + r;
        int nc = dc[d] + c;

        if(!valid(nr,nc)) continue;

        grid[nr][nc] = 'G'; // update
        dfs(nr, nc);
        grid[nr][nc] = '.'; // reset
    }
}

int main() {
    
    cin >> rows >> cols;
	for (int i = 0; i < rows; ++i) {
		for (int j = 0; j < cols; ++j) {
			cin >> grid[i][j];
		}
	}
    grid[0][0] = 'G';
    dfs(0,0);
    cout << res ;
    
    return 0;
}
