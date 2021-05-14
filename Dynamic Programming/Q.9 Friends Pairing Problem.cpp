#include <bits/stdc++.h> 
using namespace std; 


class Solution
{
public:
    long long int countFriendsPairings(long long int n,long long int m=1000000007 ) 
    { 
        if(n<0)
        return -1;
        if(n==0)
        return 0;
        if(n==1)
        return 1;
        if(n==2)
        return 2;
        
        int dp[n+1];
        memset(dp,0,sizeof(dp));
        dp[0]=0;dp[1]=1;dp[2]=2;
        for(int i=3;i<=n;i++)
        {
            dp[i]=(dp[i-1]%m)+(((dp[i-2]%m)*((i-1)%m))%m);
            dp[i]=dp[i]%m;
        }
        
        return dp[n];
    }
};    
 
int main() 
{
    int t;
    cin>>t;
    while(t--)
    {
    	int n;
    	cin>>n;
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 