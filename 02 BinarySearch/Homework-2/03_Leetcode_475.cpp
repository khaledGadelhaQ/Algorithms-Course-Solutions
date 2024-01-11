#include <iostream>
#include <bits/stdc++.h>

using namespace std;

/*
* Time complexity: sorting is (nlog n) => heaters array , ( klog k) => houses array
* Binary Search is (log M) (M is the biggest number in the two arrays)
* Total is : O(nlogn)
* Space complexity is O(N+M) => N for sorting houses and M for sorting the heaters
*/

class Solution {
public:
    bool possible(vector<int> houses, vector<int> heaters, int mid){
        int i = 0 ; // houses index
        int j = 0 ; // heaters index
        // while loop to iterate on the houses array
        // to see if every house will be covered in the radius 
        while(i < houses.size() && j < heaters.size()){
            if(abs(houses[i]-heaters[j]) <= mid){
                i++;
            }else{
                j++;
            }
        }
        return i == houses.size() ;
    }

    int findRadius(vector<int>& houses, vector<int>& heaters) {
        sort(houses.begin(), houses.end());
        sort(heaters.begin(), heaters.end());
        int l = 0, r = max(houses.back() , heaters.back());
        int res {0};
        while(l <= r){
            int mid = l +(r-l)/2;
            if(possible(houses,heaters,mid)){
                res = mid ;
                r= mid-1;
            }else{
                l = mid+1;
            }
        }
        return res;
    }
};

int main(){
    return 0;
}