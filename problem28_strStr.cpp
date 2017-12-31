#include<iostream>
// #include<vector>
#include<string>
// #include<algorithm>

using namespace std; 

class Solution {
public:
   int strStr(string haystack, string needle) {
        int h = haystack.size();
        int n = needle.size();
    
        if(n==0) //empty needle always matches
            return 0;
        if(h == 0 || n > h)
            return -1;
            
        for(int i = 0; i < h-n +1; i++){
            // if(haystack[i] == needle[0]){
                int j = 0;
                for(j = 0; j< n; j++){
                    if( haystack[i+j] == needle[j])
                        continue;
                    else
                        break;
                }
                if(j == n)
                    return i;
            // }
        }
        
        return -1;
    }
};

int main(){
    Solution S;
  string haystack = "helooollo";
  string needle = "ll";
    // int target = 0;
    cout<<S.strStr(haystack, needle) <<endl;
    
}

