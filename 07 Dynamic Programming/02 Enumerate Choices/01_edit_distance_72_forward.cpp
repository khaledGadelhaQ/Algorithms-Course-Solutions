#include <bits/stdc++.h>
using namespace std;

/*
so we have three options and four conditions
1- if the two letters are the same we skip to the next characters
2- insert the str2[indx] in front of the str1[indx] which
means to move the pointer to the next character in the str2 but
not in the str1
3- changing str1[indx] to str2[indx] so we move the pointer of 
the two string to the next character and add the cost to the res
4- deleting the element of the str1[indx] so we move the indx of 
the 

Time and Memory are O(N^2)

*/
const int MAX = 500 +  1 ;
int memo[MAX][MAX];
string str1 = "";
string str2 = "";

int edit(int i, int j){

    if(i == str1.size())
        return str2.size() - j ;
    if(j == str2.size())
        return str1.size() - i ;

    auto &ret = memo[i][j];
    if(ret != -1)
        return ret;
    
    if(str1[i] == str2[j])
        return ret = edit(i+1, j+1);
    int insert = 1 + edit(i,j+1);
    int change = 1 + edit(i+1,j+1);
    int del = 1 + edit(i+1, j);
    return ret = min(insert,min(del,change));
}
class Solution {
public:
    
    int minDistance(string word1, string word2) {
        memset(memo, -1 , sizeof(memo));
        str1 = word1;
        str2 = word2;
        return edit(0,0);
    }
};
int main(){
    return 0;
}