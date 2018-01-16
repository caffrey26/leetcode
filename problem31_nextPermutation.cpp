#include<iostream>
#include<vector>
// #include<string>
// #include<algorithm>
// #include<utility>
// #include<unordered_map>
using namespace std; 

class Solution {
public:
     void swap (int i , int n, vector<int>& nums){
        int temp = nums[i];
        nums[i] = nums[n];
        nums[n] = temp;
     }
    
    void sortN (int i , int n, vector<int>& nums){
        int j = i;
        
        while(j <n-1){
            //pick smallest, and swap it with j
            int smallest = j;
            for(int k = j+1; k<n; k++){
                    if(nums[smallest] > nums[k])
                        smallest = k;
            }
            if(smallest != j)
                swap(j,smallest, nums);
            
            j++;
        }
        
        
    }
    void nextPermutation(vector<int>& nums) {
        
        // int j = 1;
        int n = nums.size();
        
        if(n <=1) return;
        int j = n-1;
        while(j >= 0){
            int smaller = j;
            
            for(int i = j+1; i<n; i++){
                if(nums[i] > nums[j] ){
                    if(smaller > j){
                        if (nums[smaller] > nums[i])
                            smaller = i;
                    }else smaller = i;
                }
            }
            
            if(smaller == j)
                j--;
            else{ 
                swap(j,smaller,nums);//TODO Swap
                //TODO: sort the number from j+1 to n;
                sortN(j+1, n, nums);
                return;
            }
        }
        
        //this point of program discourse implies that positions j = 1 to n-2 don't have a larger value to be replaced
        
        // j= 0;
        // int smaller = j;
        // for(int i = j+1; i<n; i++){
        //         if(nums[i] > nums[j] ){
        //             if(smaller > j){
        //                 if (nums[smaller] > nums[i])
        //                     smaller = i;
        //             }else smaller = i;
        //         }
        //     }
            
        //     if(smaller != j){ 
        //         swap(j,smaller,nums);//TODO Swap
        //         //TODO: sort the number from j+1 to n;
        //         sortN(j+1, n, nums);
        //         return;
        //     }
        
        
        //TODO sort the numbers from 1 to n;
        sortN(0,n,nums);
    }
};

int main(){
    Solution S;
    vector<int> v = {1,1,5};
    S.nextPermutation(v);
    for(int i =0 ; i<v.size(); i++)
        cout<<v[i]<<endl;
    
}
