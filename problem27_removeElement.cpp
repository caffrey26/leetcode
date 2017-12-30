#include<iostream>
#include<vector>
#include<string>
// #include<algorithm>

using namespace std; 

class Solution {
public:
   int removeElement(vector<int>& nums, int val) {
        
        int n = nums.size();
        int replaceIndex = n-1;
        // int len = n;
        
        for(int i = n-1; i>=0; i--){
            if(nums[i] == val ){
                nums[i] = nums[replaceIndex--];
                
            }
        }
        return replaceIndex+1;
    }
};

int main(){
    Solution S;
    vector<int> nums = {3,3};
    // int target = 0;
    cout<<S.removeElement(nums,3) <<endl;
    for(int i = 0; i<nums.size(); i++){
    
        cout<<nums[i]<<" ";
    }
    cout<<endl;
}

