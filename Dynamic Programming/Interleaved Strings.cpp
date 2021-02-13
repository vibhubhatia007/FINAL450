#include <bits/stdc++.h>
using namespace std;

bool isInterleave(string A, string B, string C);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		string a,b,c;
		cin>>a;
		cin>>b;
		cin>>c;
		cout<<isInterleave(a,b,c)<<endl;
	}
	return 0;
}

bool isInterleave(string a, string b, string c) 
{
    int m=a.length();
    int n=b.length();
    bool dp[m+1][n+1];
    
    memset(dp,0,sizeof(dp));
    
    if(m+n!=c.length())
    return false;
    
    for(int i=0;i<=m;i++)
    {
        for(int j=0;j<=n;j++)
        {
            if(i==0&&j==0)
            dp[i][j]=true;
            
            else if(i==0)
            {
                if(b[j-1]==c[j-1])
                dp[i][j]=dp[i][j-1];
            }
            
            else if(j==0)
            {
                if(a[i-1]==c[i-1])
                dp[i][j]=dp[i-1][j];
            }
            
            else if(a[i-1]==c[i+j-1]&&b[j-1]!=c[i+j-1])
            dp[i][j]=dp[i-1][j];
            
            
            else if(a[i-1]!=c[i+j-1]&&b[j-1]==c[i+j-1])
            dp[i][j]=dp[i][j-1];
            
            else if(a[i-1]==c[i+j-1]&&b[j-1]==c[i+j-1])
            dp[i][j]=(dp[i-1][j]||dp[i][j-1]);
            
        }
    }
    
    return dp[m][n];
    
    
}
