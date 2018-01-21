#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:

    int binarySearch(vector<int>& nums, int left, int right, int target){
        while(left <= right){
            int mid = left + (right-left)/2;
            
            if(nums[mid] == target) 
                return mid;
            if(nums[mid] < target){
                left = mid+1;
            }else 
                right = mid-1;
        }
        return -1;
    }
    
    int searchRecurse(vector<int>& nums, int target, int left, int right){
        if(left <= right){
            if(nums[left] > nums[right]){
                int mid = left + (right - left)/2;
                
                if(nums[mid] > nums[right]){ //left,mid is sorted
                    if(target >= nums[left] && target <= nums[mid]) 
                        return binarySearch(nums, left, mid, target);
                    else 
                        return searchRecurse(nums, target, mid+1, right);
                }else{ //mid, right is ordered
                    
                    if(target >= nums[mid] && target <= nums[right]) 
                        return binarySearch(nums, mid, right, target);
                    else 
                        return searchRecurse(nums, target, left, mid-1);
                }
            }else{
                return binarySearch(nums,left,right,target);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target){
        //mid 1 mid, n-1 still violates, then [left, mid-1] can be searched, and forgotten 2. mid, right satisfies the condition, then left to 
        //left, right left, mid-1 still violates, and go on.
        int n = nums.size();
        if(n==0) return -1;
        return searchRecurse(nums, target, 0, n-1);
        
    }
};

int main(){
    int target = 2; 
    vector<int> nums = {4,5,6,7,0,1,2};
    Solution S;
    cout<<S.search(nums,target)<<endl;
    return 0;
}