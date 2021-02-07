#include<bits/stdc++.h>
using namespace std;

int maximizeTheCuts(int n, int x, int y, int z);

int main() {
    int t;
    cin >> t;
    while(t--)
    {
        //taking length of line segment
        int n;
        cin >> n;

        int x,y,z;
        cin>>x>>y>>z;

        cout<<maximizeTheCuts(n,x,y,z)<<endl;

    }

	return 0;
}

int maximizeTheCuts(int n, int x, int y, int z)
{
    int dp[n+1];
    memset(dp,-1,sizeof(dp));
    dp[0]=0;
    for(int i=0;i<=n;i++)
    {
        if(dp[i]==-1)
        continue;
        
        if(i+x<=n)
        dp[i+x]=max(dp[i]+1,dp[i+x]);
        if(i+y<=n)
        dp[i+y]=max(dp[i]+1,dp[i+y]);
        if(i+z<=n)
        dp[i+z]=max(dp[i]+1,dp[i+z]);
    }
    
    if(dp[n]==-1)
    return 0;
    else
    return dp[n];
    
}