#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int inSequence(long long int A, long long int B, long long int C){
        if(A==B)
        return 1;
        if(C==0)
        return 0;
        if((B-A)%C==0)
        {
            if((C*(B-A))>0)
            return 1;
            else
            return 0;
        }
      
        return 0;
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int A, B, C;
        cin>>A>>B>>C;
        
        Solution ob;
        cout<<ob.inSequence(A, B, C)<<endl;
    }
    return 0;
}  