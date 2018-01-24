#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;


class Solution{
   public:
   unordered_map<int, double> powStore;
   double myPow(double x, int n){
        if(n == 0) return 1; 
        bool overflow = false;
        int sign = n<0?-1:1;
        if(n == INT_MIN){ 
            overflow = true;
            n = INT_MAX;
        }
        if(n== -1) return 1/x;
        n = n<0?-n:n;
         if(n == 1){
            return x;
        }       
        int t = n/2;
        if(powStore.find(t) == powStore.end())
            powStore[t] = myPow(x,t);
        
        powStore[n] = powStore[t]*powStore[t];
 
        if(n%2 != 0){//even                       
            powStore[n] *= x;   
        }
        if(overflow)
            powStore[n] *=x;
        return sign<0? 1/powStore[n]:powStore[n];
       
   }
};
int main(){
    Solution S;
    double x = 2.000;
    int n = -2147483648;
    cout<<S.myPow(x,n)<<endl;
}
