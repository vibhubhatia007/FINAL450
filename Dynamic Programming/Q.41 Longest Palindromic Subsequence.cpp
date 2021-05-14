#include <bits/stdc++.h> 
using namespace std; 

int lps(string s)
{
    string s1=s;
    reverse(s.begin(),s.end());
    string s2=s;
    
    int n=s.length();
    int dp[n+1][n+1];
    
    for(int i=0;i<=n;i++){
        for(int j=0;j<=n;j++)
        {
            if(i==0||j==0)
            dp[i][j]=0;
            else if(s1[i-1]==s2[j-1])
            dp[i][j]=dp[i-1][j-1]+1;
            else
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            
        }
    }
    
    return dp[n][n];
}

int main()
 {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout << lps(s) <<"\n";
	}
	
	return 0;
}