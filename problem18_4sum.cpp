#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std; 

class Solution {
public:
    
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> v;
        
        //sort the numbers first
        sort(nums.begin(),nums.end());
        int n = nums.size();
        for(int i = 0; i<n; i++){
            // int num1 = nums[i];
            
            int targetFor3Sum = target - nums[i];
            
            //the set of numbers for 3 sum to act is from i+1 to n-1
            for(int j = i+1; j<n; j++){
                //the set for 2 sum to act is j+1 to n-1
                int targetFor2Sum = targetFor3Sum - nums[j];
                
                //now act for 2 sum
                int a = j+1;
                int b = n-1;
                while(a<b){
                    int sum = nums[a] + nums[b];
                    if(sum == targetFor2Sum){
                        vector<int> t;
                        t.push_back(nums[i]);
                        t.push_back(nums[j]);
                        t.push_back(nums[a]);
                        t.push_back(nums[b]);
                        v.push_back(t);
                        
                        //scan over the same a's now
                        while(a<n-1 && a<b && nums[a] == nums[a+1])
                            a++;
                        //scan over the same b's as well now
                        while(b>0 && a<b && nums[b] == nums[b-1])
                            b--;
                        
                        a++;
                        b--;
                    }else{
                        if(sum < targetFor2Sum)
                            a++;
                        else
                            b--;
                            
                    }
                }
                
                //now one iteration of 3 sum is over, time to check for duplicates
                
                while(j<n-1 && nums[j] == nums[j+1])
                    j++;
                //either j is the last value, or the value which is different
                if( j == n-1 && nums[j] == nums[j-1])
                    j++;
                //now j is either out of scope, or a value that is different
            }
            
            //now one iteration of 4 sum is over, time to check for duplicates
            while(i<n-1 && nums[i] == nums[i+1])
                    i++;
                //either i is the last value, or the value which is different
                if( i == n-1 && nums[i] == nums[i-1])
                    i++;
                //now i is either out of scope, or a value that is different
            
        }
        return v;
    }
};

int main(){
    Solution S;
    vector<int> nums = {1, 0, -1, 0, -2, 2};
    int target = 0;
    vector<vector<int>> v = S.fourSum(nums, target);
    
    for(int i = 0; i<v.size(); i++){
        for(int j = 0; j<v[i].size(); j++){
            cout<<v[i][j]<<", ";
        }
        cout<<endl;
    }
    
}

