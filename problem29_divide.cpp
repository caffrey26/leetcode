#include<iostream>
// #include<vector>
// #include<string>
#include<climits>
// #include<algorithm>

using namespace std; 

class Solution {
public:
    int divide(int dividend, int divisor) {
        
        int q =  0 ;
        if(divisor > INT_MAX || divisor < INT_MIN || dividend > INT_MAX || dividend < INT_MIN) return INT_MAX;
        if(divisor == 0 ) return INT_MAX;
        
        int sign;
        if((dividend < 0 && divisor <0) || (dividend >0 && divisor >0))
            sign =1;
        else 
            sign = -1;
            
        int overflow = 0;
        if(dividend == INT_MIN){
            if(divisor == INT_MIN) 
                return 1;
            // if(divisor == 1) return INT_MIN;
            // if(divisor == -1 ) return INT_MAX;
            dividend = INT_MAX;
            overflow = 1;
        } 
        
        if(dividend < 0 ) dividend = -dividend;
        
        if(divisor == INT_MIN ) return 0;
        if(divisor < 0) divisor = -divisor;
        int trip1 = 1;
        while(divisor <= dividend){
            if(overflow && trip1 ){
                dividend = (dividend - divisor) +1 ;
                trip1 = 0;
            }else  
                dividend -= divisor;
            
            int pdivisor = divisor;
            int pq = 1;
            while(dividend - pdivisor >= 0){
                dividend -= pdivisor;
                pdivisor = pdivisor<<1;
                pq= pq<<1;
            }
            
            q += pq;
        }
        if(sign == 1){ //positive
            if(q == INT_MIN) 
                return INT_MAX;
            return q;
        }
        else{
          return -q;  
        } 
            
     }
   
};

int main(){
    Solution S;
    int dividend, divisor;
    cout<<"Dividend: "<<endl;
    cin>>dividend;
    cout<<"Divisor: "<<endl;
    cin>>divisor;
    cout<<"Calculated division: "<<S.divide(dividend,divisor) <<endl;
    cout<<"Actual division: " << dividend/divisor << endl;
    
}

