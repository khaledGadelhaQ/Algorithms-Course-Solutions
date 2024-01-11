#include <iostream>
#include <bits/stdc++.h>

using namespace std;
/*
* Time complexity: O(nlog K) (K = Max Number in the array)
*  Space complexity: O(1)
*/
class Solution {
public:
    int possible(vector<int> v , int divisor){
        int sum {0};
        for(auto val : v){
            sum += (val + divisor-1)/divisor;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& v, int threshold) {
        int l =1 , r =*max_element(v.begin() , v.end());
        int res;
        while(r >= l){
           int mid = l + (r-l)/2;
           if(possible(v,mid) <= threshold){
               res = mid;
               r =mid-1;
            }else{
                l =mid+1;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}