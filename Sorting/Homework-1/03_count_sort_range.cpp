#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<int> sortArray(vector<int>& nums) {

    
    int maxVal = *max_element(nums.begin(),nums.end());
    int minVal = *min_element(nums.begin(),nums.end());
    
    vector<int> count(maxVal - minVal + 1, 0);

    for(auto num : nums){
      count[num - minVal]++;
    }
    int idx {0};
    for(int i = 0 ; i < count.size() ; i++){
         
        while(count[i]){
          nums[idx++] = i + minVal;
          count[i]--;
        }
    }
    return nums;




  }
};

void print(vector<int> &v){
    
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}

int main(){

    vector<int> count_v = {40,23,0,-40,-30,100,-15,99};
    Solution s;
    s.sortArray(count_v);

    cout<<"Array Sorted: \n";
    print(count_v);

    cout <<"\nNo Run Time Error!\n";
}   