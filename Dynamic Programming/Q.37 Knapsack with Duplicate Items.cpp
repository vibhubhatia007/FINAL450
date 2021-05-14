#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int knapSack(int n, int w, int val[], int wt[])
    {
     int dp[w+1];
     memset(dp,0,sizeof(dp));
     
     for(int i=0;i<=w;i++)
     {
         for(int j=0;j<n;j++)
         {
             if(i-wt[j]>=0)
             dp[i]=max(dp[i],dp[i-wt[j]]+val[j]);
         }
     }
        
    return dp[w];
        
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
} 