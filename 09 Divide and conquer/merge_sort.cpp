#include <bits/stdc++.h>
using namespace std;
    
    vector<int> nums;
    vector<int> tmp;
    void merge_sorted_subarrays(int start , int end , int mid){
        for(int i = start, j = mid+1, k = start ; k <= end ; k++){
            if(i > mid){
                tmp[k] = nums[j++];
            }else if( j > end){
                tmp[k] = nums[i++];
            }else if(nums[i] >= nums[j]){
                tmp[k] = nums[j++];
            }else{
                tmp[k] = nums[i++];
            }
        }
        for (int i = start; i <= end; i++){
		    nums[i] = tmp[i];
        }
    }

    void merge(int start, int end){
        if(start == end) return;
        int mid = start + ( end - start) / 2;
        merge(start,mid);
        merge(mid+1, end);
        merge_sorted_subarrays(start, end, mid);
    }
int main(){
    nums = {10,9,3,5,2,11,0};
    tmp = nums;
    merge(0, nums.size()-1);
    for(auto val : tmp){
        cout << val << " ";
    }
    return 0;
}