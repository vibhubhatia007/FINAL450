#include<bits/stdc++.h>
using namespace std;



class Solution
{
	public:
		int editDistance(string s, string t)
		{
		    int n=s.length();
		    int m=t.length();
		    int dp[n+1][m+1];
		    memset(dp,0,sizeof(dp));
		    
		    for(int i=0;i<=n;i++)
		    {
		        for(int j=0;j<=m;j++)
		        {
		            if(i==0)
		            dp[i][j]=j;
		            else if(j==0)
		            dp[i][j]=i;
		            else if(s[i-1]==t[j-1])
		            dp[i][j]=dp[i-1][j-1];
		            else
		            dp[i][j]=min(min(dp[i-1][j],dp[i][j-1]),dp[i-1][j-1])+1;
		        }
		    }
		    
		   return dp[n][m];
		    
		    
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	string s, t;
    	cin >> s >> t;
    	Solution ob;
    	int ans = ob.editDistance(s, t);
    	cout << ans <<"\n";
    }
	return 0;
}