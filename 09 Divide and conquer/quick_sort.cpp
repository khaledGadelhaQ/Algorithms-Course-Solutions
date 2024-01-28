#include <bits/stdc++.h>
using namespace std;

int findPivot(vector<int>& nums, int st, int ed){
    int mid = st + (ed - st)/2;
    int count = st;
    for(int i = st ; i <= ed ; i++){
        if(nums[i] < nums[mid]) count++;
    }
    int pivot_idx = count;
    swap(nums[mid], nums[pivot_idx]);

    for(int s = st, e = ed ; s < pivot_idx && e > pivot_idx ; s++,e--){
        while(nums[s] < nums[pivot_idx]) s++;
        while(nums[e] > nums[pivot_idx]) e--;
        swap(nums[s],nums[e]);
    }
    return pivot_idx;
}

void quick_sort(vector<int> &nums, int st, int ed){
    if(st >= ed) return;
    int pivot_idx = findPivot(nums, st, ed);
    quick_sort(nums, pivot_idx + 1, ed);
    quick_sort(nums, st , pivot_idx - 1);
}

int main(){
	vector<int> vec { 12, 35, 87, 26, 9, 28, 7 };
    quick_sort(vec, 0 , vec.size() -1 );
    for(auto val : vec) cout << val << " ";
    return 0;

}