#include<iostream>
#include<vector>
#include<string>
// #include<algorithm>

using namespace std; 

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        
        int len = 1; 
        int n = nums.size(), i = 1;
        while(i<n){
            while(i<n && nums[i] == nums[i-1]){
                i++;
            }
            if(i<n){
                len++;
                nums[len-1] = nums[i];
                i++;
            }
        }
        return len;
    }
   
};

int main(){
    Solution S;
    vector<int> nums = {1, 1,2,2,3,3,3};
    // int target = 0;
    cout<<S.removeDuplicates(nums) <<endl;
    for(int i = 0; i<nums.size(); i++){
    
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

