#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxSum(int n){
       
       if(n==1)
       return 1;
       else
       return ((n*(n-1))/2)+(n/2)-1;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        
        Solution ob;
        cout<<ob.maxSum(N)<<"\n";
    }
    return 0;
} 