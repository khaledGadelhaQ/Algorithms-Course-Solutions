#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<string> countSort(vector<string>& nums) {
    
    vector<vector<string>> count(27);

    for(auto num : nums){
      count[tolower(num[0]) - 'a'].push_back(num);
    }
    int idx {0};
    for(int i = 0 ; i < count.size() ; i++){
         
        for(int j = 0 ; j < count[i].size() ; j++){
            nums[idx++] = count[i][j];
        }
    }
    return nums;
  }
};
void print(vector<string> &v){
    
    for(auto val : v){
        cout << val << " ";
    }
    cout << endl;
}

int main(){

    vector<string> count_v = {"ziad", "belal", "adam", "baheir", "ali"};
    Solution s;
    s.countSort(count_v);

    cout<<"\nStable Array Sorting: \n";
    print(count_v);

    cout <<"\nNo Run Time Error!\n";
}   