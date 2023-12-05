#include <bits/stdc++.h>

using namespace std;

const int MAX_N = 500;
const int MAX_T = 2000 + 1;
int memo[MAX_N][MAX_T];

bool subset_sum(int indx , vector<int> values, int target){
    if(target < 0)
        return false;
    if(target == 0)
       return true;
    if(indx == (int) values.size())
        return false;
    auto &ret = memo[indx][target];
    if(ret != -1)
      return ret;
    if(subset_sum(indx+1, values, target))
       return ret =  true;
    return ret = subset_sum(indx+1 , values, target - values[indx]);

}

bool subset_sum_test(const vector<int>&values, int target ){
    return subset_sum(0,values, target);
}


void test(){
   cout<<"\nTest Cases:\n\n";
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({3, 12, 4, 12, 5, 2},9) << endl;
   cout<<"\tExpected: 0 - Result: ";
   cout<< subset_sum_test({3, 40, 4, 12, 5, 2},30) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({10, 20, 30, 40, 50},60) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({10, 20, 30, 40, 50},100) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({10, 20, 30, 40, 50},90) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({10, 20, 30, 40, 50},70) << endl;
   cout<<"\tExpected: 0 - Result: ";
   cout<< subset_sum_test({10, 20, 30, 40, 50},200) << endl;
   cout<<"\tExpected: 0 - Result: ";
   cout<< subset_sum_test({200},300) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({200},200) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({1,2,3},6) << endl;
   cout<<"\tExpected: 1 - Result: ";
   cout<< subset_sum_test({1,1},1) << endl;
}

int main(){
    memset(memo, -1, sizeof(memo));
    test();
    cout << "\n\nNOT RUN TIME ERRORS!!\n\n";
}