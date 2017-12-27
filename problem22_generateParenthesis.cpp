#include<iostream>
#include<vector>
#include<string>
// #include<algorithm>
// #include<unordered_map>
using namespace std; 

class Solution {
public:
    void populate(string s, int numLeft, int diff, int n, vector<string>& results){
        if(diff < 0 ) return;
        if(numLeft == n && diff == 0){
            results.push_back(s);
            return;
        }
        if(numLeft + 1 <= n){
            populate(s+"(", numLeft+1, diff +1, n, results);
        }
        if(numLeft <= n){
            if(diff -1 >= 0 )
                populate(s+")", numLeft, diff - 1, n, results);
        }
    }
    vector<string> generateParenthesis(int n) {
            vector<string> results;
            
            if(n == 0) return results;
            
            populate("(", 1, 1, n, results);
            return results;
    }
};

int main(){
    Solution S;
    int n = 4;
    vector<string> v = S.generateParenthesis(n);
    
    for(int i = 0; i<v.size(); i++){
            cout<<v[i]<<endl;
    }
}

