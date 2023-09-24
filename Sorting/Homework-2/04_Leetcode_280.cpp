#include <iostream>
#include <vector>
#include <algorithm>
 
using namespace std ;

class Solution {
public:
    /// one solution
    /// O(nlogn) time , o(1) memory 
    void wiggleSort(vector<int> &nums) {
        if(nums.size() == 0) return;

        sort(nums.begin(), nums.end());

        for(int i = 1 ; i < nums.size()-1 ; i+=2){
            swap(nums[i],nums[i+1]);
        }
        
    }
    
    


};

class Solution2{
public:
    //  O(n) time , O(1) memory
    void wiggleSort(vector<int> &nums) {
        if(nums.size() == 0) return;


        for(int i = 1 ; i < nums.size()-1 ; i++){
            if(i%2 == 0 && nums[i] > nums[i+1]){
                swap(nums[i+1],nums[i]);i++;
            }
            if(i%2 == 1 && nums[i] < nums[i+1]){
                swap(nums[i+1],nums[i]);i++;
            }
        }
        
    }
};

int main(){
    vector<int> v = {3,5,2,1,6,4};
    vector<int> v2 = {3,5,2,1,6,4};
    Solution s;
    Solution2 s2;
    s.wiggleSort(v);
    s2.wiggleSort(v2);
    for(auto val : v ){
        cout << val << " ";
    }
    cout << endl;
    for(auto val : v2 ){
        cout << val << " ";
    }
    cout << endl;

    cout <<"3,5,1,6,2,4";
    return 0 ;
}



