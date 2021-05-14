#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxSquare(int n, int m, vector<vector<int>> mx){
        
        int dp[n][m];
        
        for(int i=0;i<n;i++)
        dp[i][0]=mx[i][0];
        
        for(int i=0;i<m;i++)
        dp[0][i]=mx[0][i];
      
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
              if(mx[i][j]==1)
              dp[i][j]=min(dp[i-1][j-1],min(dp[i-1][j],dp[i][j-1]))+1;
              else
              dp[i][j]=0;
             
            }
        }
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                 if(dp[i][j]>ans)
                 ans=dp[i][j];
            }
        }
        return ans;
       
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> mat(n, vector<int>(m, 0));
        for(int i = 0;i < n*m;i++)
            cin>>mat[i/m][i%m];
        
        Solution ob;
        cout<<ob.maxSquare(n, m, mat)<<"\n";
    }
    return 0;
}  