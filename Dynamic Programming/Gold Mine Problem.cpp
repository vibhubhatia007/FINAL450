#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int maxGold(int m, int n, vector<vector<int>> gold)
    {
        int dp[m][n]; 
    memset(dp, 0, sizeof(dp)); 
  
    for (int col=n-1; col>=0; col--) 
    { 
        for (int row=0; row<m; row++) 
        { 
            int right = (col==n-1)? 0: dp[row][col+1]; 
  
            int right_up = (row==0 || col==n-1)? 0: 
                            dp[row-1][col+1]; 
  
            int right_down = (row==m-1 || col==n-1)? 0: 
                             dp[row+1][col+1]; 
  
            dp[row][col] = gold[row][col] + 
                              max(right, max(right_up, right_down)); 
                                                      
        } 
    } 

    int res = 0 ;
    for (int i=0; i<m; i++) 
        res = max(res, dp[i][0]); 
    return res; 
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
        cin>>n>>m;
        vector<vector<int>> M(n, vector<int>(m, 0));
        for(int i = 0;i < n;i++){
            for(int j = 0;j < m;j++)
                cin>>M[i][j];
        }
        
        Solution ob;
        cout<<ob.maxGold(n, m, M)<<"\n";
    }
    return 0;
}  