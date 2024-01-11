#include <bits/stdc++.h>
using namespace std;


const int MAX = 1000 + 1;
int memo[MAX][MAX];

string str;

bool isPalindrome(int st_indx, int end_indx){
    if(st_indx >= end_indx)
        return true; // "" or "a"
    auto &ref = memo[st_indx][end_indx];
    if(ref != -1)
        return ref;
    if(str[st_indx] == str[end_indx])
        return ref = isPalindrome(st_indx+1, end_indx -1);
    return ref = 0 ; // memorizing the answer as 0 (false)
}

class Solution {
public:
    string longestPalindrome(string s) {
        int sz = s.size();
        if(sz <= 1)
            return s;
        memset(memo, -1 , sizeof(memo));
        str = s;
        int length = 0, indx = 0;
        for(int i = 0 ; i < sz ;i++){
            for(int j = i ; j < sz ; j++){
                if(isPalindrome(i,j) && (j-i+1 > length))
                    indx = i, length = (j-i+1);
            }
        }
        return s.substr(indx, length);
    }
};


int main() {
    Solution sol;
    cout << sol.longestPalindrome("babad") << endl; // Output the longest palindrome substring
    return 0;
}

/* This approach fails on large inputs
class Solution {
private:
    bool isPalindrome(string &str){
        for(int i = 0 ; i < str.size() ; i++){
            if(str[i] != str[str.size() - i - 1])
                return false;
        }
        return true;
    }

    string dp(int start, int end, const string &s, vector<vector<string>> &memo) {
        if (start > end || start < 0 || end >= s.size())
            return "";
        
        if (!memo[start][end].empty())
            return memo[start][end];
        
        if (start == end)
            return memo[start][end] = s[start];
        
        string longest;
        for (int i = end; i >= start; --i) {
            for (int j = start; j <= end; ++j) {
                string current = s.substr(j, i - j + 1);
                if (isPalindrome(current) && current.size() > longest.size()) {
                    longest = current;
                }
            }
        }
        return memo[start][end] = longest;
    }

public:
    string longestPalindrome(string s) {
        int n = s.size();
        if (n <= 1) return s;
        vector<vector<string>> memo(n, vector<string>(n, ""));
        return dp(0, n - 1, s, memo);
    }
};
*/