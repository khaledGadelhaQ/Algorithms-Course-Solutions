#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
        int sz = books.size();
        vector<int> dp(sz + 1 , INT_MAX);
        dp[0] = 0;
        for(int i = 1 ; i <= sz ; i++ ){
            int mx_height = 0 , mx_width = 0;
            for(int j = i ; j > 0; j--){
                mx_width += books[j-1][0];
                if(mx_width > shelfWidth)
                    break;
                mx_height = max(mx_height, books[j-1][1]);
                dp[i] = min(dp[i] , dp[j-1] + mx_height);
            }
        }
        return dp[sz];
    }
};