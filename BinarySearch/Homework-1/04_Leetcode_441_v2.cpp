#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
* Time complexity:
* O(sqrt(n))
* Space complexity:
* O(1)
*/
class Solution {
public:
    int arrangeCoins(int n) {
        int i = 0 ;
       for(; n >= 0; n -= ++i){;}
       return i-1;
    }
};

int main(){
    return 0 ;
}