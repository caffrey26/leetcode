#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
  vector<int> searchRecur (vector<int>& nums, int target, int left, int right){
    vector<int> v;
    while(left <= right){
        int mid = (left+right)/2;
        if(nums[mid] == target){
                vector<int> farLeft = searchRecur (nums, target, left, mid-1);
                vector<int> farRight = searchRecur (nums, target, mid+1, right);
                
                if(farLeft[0] == -1)
                    v.push_back(mid);
                 else 
                     v.push_back(farLeft[0]);
                 
                 
                if(farRight[1] == -1)
                    v.push_back(mid);
                 else 
                     v.push_back(farRight[1]);
                  
                  return v;
        }
        if(nums[mid] > target) 
            right = mid-1;
        else left = mid+1;  
    }
    
    v.push_back(-1);
    v.push_back(-1);
    
    return v;
}
vector<int> searchRange (vector<int>& nums, int target){
    int n = nums.size();
    int left = 0, right = n-1;
    return searchRecur (nums, target, 0, n-1);   
}
};

int main(){
    int target = 8; 
    vector<int> nums = {5, 7, 7, 8, 8, 10};
    Solution S;
    vector<int> v = S.searchRange(nums,target);
    cout<<v[0] <<" "<<v[1]<<endl;
    return 0;
}