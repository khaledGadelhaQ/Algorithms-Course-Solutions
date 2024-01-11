#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
public:
    int maxProfitAssignment(vector<int>& diff, vector<int>& profit, vector<int>& worker) {
         
        vector<pair<int,int>> diffProfit ; 
        for( int i  =0  ; i< diff.size() ;i++){
            diffProfit.push_back({profit[i],diff[i]});
        }
        sort(diffProfit.rbegin(), diffProfit.rend());

        int sum {0};

        for( int i = 0 ; i < worker.size() ; i++){
           int tmp {0};
           for(int j = 0 ; j <diffProfit.size() ; j++){
              if(diffProfit[j].second <= worker[i]){
                  tmp = diffProfit[j].first;
                  break;
              }

           }
           sum += tmp;
        }
        return sum; 
    }
};

int main(){
    return 0;
}