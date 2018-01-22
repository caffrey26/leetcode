#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
 int searchInsert(vector<int>& nums, int target){
    int n = nums.size();
    if (n == 0) return 0;
    int left = 0, right = n-1;
    while(left < right){
        int mid = (left+right)/2;
        if(nums[mid] == target) return mid;
        if(nums[mid] > target) right = mid-1;
        else left = mid+1; 
    }
    
    if(nums[left] == target) return left;
    if(nums[left] > target) return left==0?0:left;
    if(nums[left] < target) return left+1;
}
};

int main(){
    int target = 2; 
    vector<int> nums = {1,3,5,6};
    Solution S;
    cout<<S.searchInsert(nums,target)<<endl;

    return 0;
}