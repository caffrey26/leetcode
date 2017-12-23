#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>

using namespace std; 

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        
        // unordered_map<char,string> m;
        // m['2'] = "abc";
        // m['3'] = "def";
        // m['4'] ="ghi";
        // m['5'] = "jkl";
        // m['6'] = "mno";
        // m['7'] = "pqrs";
        // m['8'] = "tuv";
        // m['9'] = "wxyz";
        
        vector<string> m = {"","",  "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int l = digits.size(); //the final string length has to be l
        
        vector<string> results;
        // results.push_back("");
        // vector<string> tempResults;
        
        for(int pos = 0; pos < l; pos++){
            vector<string> tempResults;

            char c = digits[pos]; //character at this postion, it can offer a variety of options
            int num = c - '0';
            //each option offered by c gets appended to the already existing result strings, and pushed to a new vector of strings 
            // unordered_map<char,string>::iterator got; 
            //loop over each option 
            // got = m.find(c); //try to find the character in the map, if this character offers any option
            
            if(!m[num].empty()){ 
                string sChar =  m[num];
                    for(int j = 0; j<sChar.size(); j++){//loop over each option
                        char p = sChar[j]; //option offered by c
                        string t_p(1,p);
                       
                        //append and push this option to all strings in results vector
                        for(int i = 0; i<results.size(); i++){
                            string s1 = results[i]; 
                            string t = s1 + t_p;
                            tempResults.push_back(t);
                        }
                         if(results.size() == 0){
                            tempResults.push_back(t_p);
                        }
                        
                    }
            }
            // for(int i = 0; i<results.size(); i++){ //loop over each string in results vector
            //     string s1 = results[i]; 
            //     got = m.find(c); //try to find the character in the map, if this character offers any option
            //     if(got != m.end()){ 
            //         //append each option to this string
            //         string sChar =  got->second;
            //         for(int j = 0; j<sChar.size(); j++){//loop over each option
            //             char p = sChar[j]; //option offered by c
            //             string t_p(1,p);
            //             string t = s1 + t_p;
            //             tempResults.push_back(t);
            //         }
            //     }
            // }
            results = tempResults;
        }
        return results;
        
    }
};

int main(){
    Solution S;
    string digits = "23"; 
    vector<string> result= S.letterCombinations(digits);
    for(int i =0; i<result.size(); i ++){
        cout<<result[i]<<endl;
    }
}