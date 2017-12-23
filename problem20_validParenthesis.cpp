#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
// #include<algorithm>
#include<stack>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> m ;
        m[')'] = '(' ;
        m['}'] = '{' ;
        m[']'] = '[' ;
        
        for(int i =0; i<s.size(); i++){
            char c = s[i];
            if(c == '(' || c == '[' || c=='{')
                st.push(c);
            else{
                //closing brace
                if(st.empty())
                    return false;
                char t = st.top();
                st.pop();
                if( m[c] != t)
                    return false;
            }
        }
        if(!st.empty()) 
            return false;
        return true;
        
    }
};

int main(){
    Solution S;
    string s = "()[]{}";
    cout<<S.isValid(s)<<endl;
    
}