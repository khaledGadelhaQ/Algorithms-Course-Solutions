#include <bits/stdc++.h>

using namespace std;

const int weightArr[5] = {10,4,6,5,1};
const int valueArr[5] = {10,15,2,8,2};
const int sz = 5;
const int MAX = 2000;
int memory [MAX][MAX];

int knapsack(int indx , int remaining_weight){
     
    if(indx == sz)
        return 0;
    auto &ret = memory[indx][remaining_weight];

    if(ret != -1)
       return ret;

    int leave = knapsack(indx + 1, remaining_weight);
    int pick = 0 ;

    if(weightArr[indx] <= remaining_weight)
       pick = valueArr[indx] + knapsack(indx + 1 , remaining_weight - weightArr[indx]);

   return ret =  max(pick,leave);
     
}

int main(){
    memset(memory, -1, sizeof(memory)); //setting all values to -1
    cout << knapsack(0,21);
   return 0 ;
}