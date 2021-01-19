#include <bits/stdc++.h>
using namespace std;


class Solution{
  public:
    int middle(int A, int B, int C){
        if((B-A)*(B-C)<0)
        return B;
        if((A-B)*(A-C)<0)
        return A;
        else
        return C;
        
        
    }
};

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int A,B,C;
        cin>>A>>B>>C;
        Solution ob;
        cout<<ob.middle(A,B,C) <<"\n";
    }
    return 0;
} 