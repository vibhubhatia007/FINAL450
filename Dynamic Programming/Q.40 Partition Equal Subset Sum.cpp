
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
         

         
    int equalPartition(int n, int arr[])
    {
        int t=0;
        for(int i=0;i<n;i++)
        {
            t=t+arr[i];
            
        }
        if(t%2==1)
        return 0;
        else
        t=t/2;
        
        bool dp[t+1][n+1];
        for(int i=0;i<=n;i++)
        dp[0][i]=true;
        for(int i=0;i<=t;i++)
        dp[i][0]=false;
        for(int i=1;i<=t;i++)
        {
            for(int j=1;j<=n;j++)
            {
                dp[i][j]=dp[i][j-1];
                if(i-arr[j-1]>=0)
                dp[i][j]=(dp[i][j]||dp[i-arr[j-1]][j-1]);
            }
        }
        
        if(dp[t][n])
        return 1;
        else
        return 0;
    }
};



int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  