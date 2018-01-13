#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
#include<unordered_map>
using namespace std; 

class Solution {
public:
   void needleInHaystack(string s,int j, string s1,vector<pair<int,int>>& v) {
        
        int n = s.size();
        int m = s1.size();
        
        for(int i =0; i< n -m +1; i++){
            int k =0;
            while(k<m && s[i+k] == s1[k])
                k++;
            if(k == m)
                v.push_back( make_pair(i,j) );
        }
        
        // return v;
    }
 
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> v;
        if(words.size() == 0){ 
         v.push_back(0);
         return v;
        
        }if(s.size() == 0 || s.size() < words[0].size()*words.size()) return v; 
    
        int numberOfWords = words.size();
        int wordSize = words[0].size();
        
        unordered_map<string,int> count;
        
        for(int i =0; i<numberOfWords; i++)
            count[words[i]]++;
            
        //run a window of words length size. 
        for(int i =0; i<wordSize; i++){
            
            unordered_map<string,int> findSS;
            int total = 0;
            int left = i; //the left index of window
            int j = i; 
            
            while(j < s.size()){
                string subS = s.substr(j,wordSize);
                
                j += wordSize;
                
                if(count.find(subS) == count.end()){
                    //word doesn't exist in the input words
                    total = 0;
                    findSS.clear();
                    left = j; 
                }else{
                    //word exists, increment the count 
                    findSS[subS]++;
                    total++; //total words encountered till now
                    
                    if(findSS[subS] > count[subS]){
                        //the count has surpassed the allowed number
                        //find the first occurence of this word, and remove it, and start again from the nexr word onwards
                        
                        while(findSS[subS] > count[subS]){
                            string temp = s.substr(left, wordSize);
                            total--;
                            findSS[temp]--;
                            left += wordSize;
                        }
                        
                    }
                    if(total == numberOfWords){
                            v.push_back(left);
                            
                            //remove left from the container
                            findSS[s.substr(left,wordSize)]--;
                            total--;
                            //move left to one word right
                            left += wordSize;
                            
                    }
                    
                }
                
            }
        }//end of for
        return v;
    }
};

int main(){
    Solution S;
    vector<int> v;
    string s ="barfoofoobarthefoobarman"; 
    vector<string> words = {"bar","foo","the"};
    v = S.findSubstring(s, words);
    for(int i =0 ; i<v.size(); i++)
        cout<<v[i]<<endl;
    
}
