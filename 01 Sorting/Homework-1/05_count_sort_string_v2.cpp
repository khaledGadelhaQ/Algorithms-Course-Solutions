#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;


/// sorting for only the first two letters 
class Solution {
public:
  int id(string str){
    return ((tolower(str[0])-'a') * 26) + (tolower(str[1])- 'a'); 
  }
  vector<string> countSort(vector<string>& nums) {
    
    vector<vector<string>> count(26*26);

    for(auto num : nums){
      count[id(num)].push_back(num);
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

    vector<string> count_v = {"axz", "axa", "zzz", "abc", "abe"};
    Solution s;
    s.countSort(count_v);

    cout<<"\nStable Array Sorting: \n";
    print(count_v);

    cout <<"\nNo Run Time Error!\n";
}   