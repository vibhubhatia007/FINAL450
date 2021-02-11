#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maximumPath(int n, vector<vector<int>> mx)
    {
        
        int dp[n][n+2];
        for(int i=0;i<n;i++)
        {
            dp[0][i+1]=mx[0][i];
        }
        for(int i=0;i<n;i++)
        {
            dp[i][n+1]=0;
            dp[i][0]=0;
        }
        
        int ans=0;
        
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<n+1;j++)
            {
                dp[i][j]=max(dp[i-1][j-1],max(dp[i-1][j],dp[i-1][j+1]))+mx[i][j-1];
            }
        }
        
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n+2;j++)
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
        int N;
        cin>>N;
        vector<vector<int>> Matrix(N, vector<int>(N, 0));
        for(int i = 0;i < N*N;i++)
            cin>>Matrix[(i/N)][i%N];
        
        Solution ob;
        cout<<ob.maximumPath(N, Matrix)<<"\n";
    }
    return 0;
}  