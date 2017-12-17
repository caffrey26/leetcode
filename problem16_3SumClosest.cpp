#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>

using namespace std;

class Solution {
public:
    int twoSumClosest (vector<int>& nums, int target, int pos){
        //find two numbers that sum closest to target, from all numbers in nums except the one at pos
        vector<int> temp; 
        for(int i = 0; i<nums.size(); i++){
            if(i != pos)
                temp.push_back(nums[i]);
        }
        
        sort(temp.begin(), temp.end());
        
        int i = 0, j = temp.size() - 1;
        
        int t;
        int bestSum;
        int bestDiff = INT_MAX; 
        
        while(i<j){
            t = temp[i] + temp[j];
            int thisDiff = (t > target)? (t-target): (target-t);
            if(thisDiff < bestDiff){
                bestDiff = thisDiff;
                bestSum = t;
            }
            if(t == target) 
                return target;
            if(t<target)
                i++;
            else
                j--;
        }
        return bestSum;
    }
    
    int threeSumClosest(vector<int>& nums, int target) {
        int closestSum;
        int modDiff = INT_MAX;
        for(int i = 0; i < nums.size(); i++){
            int target2Sum = target - nums[i];
            int sum = twoSumClosest(nums, target2Sum, i);
            if (target2Sum == sum) return target;
            
            int thisSum = sum + nums[i];
            int thisDiff = (thisSum > target) ? (thisSum - target): (target -thisSum);
            if(thisDiff < modDiff){
                modDiff = thisDiff;
                closestSum = thisSum;
            }
        }
        return closestSum;
    }
};

int main(){
    int target = 81; 
    vector<int> nums = {1,6,9,14,16,70};
    Solution S;
    cout<<S.threeSumClosest(nums,target)<<endl;
    return 0;
}