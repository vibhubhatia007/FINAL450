#include<bits/stdc++.h>
using namespace std;


int eggDrop(int n, int k) 
{

    int dp[n+1][k+1];
    
    for(int i=1;i<=n;i++)
    {
        dp[i][0]=0;
        dp[i][1]=1;
    }
    
    for(int i=1;i<=k;i++)
    {
        dp[1][i]=i;
    }
    
    for(int i=2;i<=n;i++)
    {
        for(int j=2;j<=k;j++)
        {
            dp[i][j]=INT_MAX;
            for(int x=1;x<=j;x++)
            {
                int t = 1 + max(dp[i][j-x],dp[i-1][x-1]);
                if(t < dp[i][j])
                dp[i][j]=t;
            }
        }
    }
    
    return dp[n][k];
}

int main()
{
    //taking total testcases
    int t;
    cin>>t;
    while(t--)
    {
        //taking eggs and floors count
        int n, k;
        cin>>n>>k;

        //calling function eggDrop()
        cout<<eggDrop(n, k)<<endl;
    }
    return 0;
}