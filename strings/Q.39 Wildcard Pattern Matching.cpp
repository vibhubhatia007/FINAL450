
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    bool match(string wild, string pattern)
    {
    
      int m = wild.size();
      int n = pattern.size();
      
      
      int dp[m+1][n+1];
      
      memset(dp,false,sizeof(dp));
      
      
      dp[0][0]=true;
  
      for(int i=1;i<=m;i++)
      {
          if(wild[i-1]=='*')
          dp[i][0]=dp[i-1][0];
      }
      
      dp[m][n];
          
      for(int i=1;i<=m;i++)
      {
          for(int j=1;j<=n;j++)
          {
              if(wild[i-1]==pattern[j-1]||wild[i-1]=='?')
              dp[i][j]=dp[i-1][j-1];
              else if(wild[i-1]=='*')
              dp[i][j]=dp[i-1][j]||dp[i][j-1];
              else
              dp[i][j]=false;
             
          }
      }
      

        
      return dp[m][n];
        
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
} 