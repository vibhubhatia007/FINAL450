

#include <bits/stdc++.h>
using namespace std;


int min(int a, int b) { return (a < b) ? a : b; }

class Solution{
public:
    long long int nCr(int n, int r){
        
        if(n<r)
        return 0;
        
        if (r == 0 || r == n)
        return 1;
        
        long long int dp[n+1][r+1];
        
        memset(dp, 0, sizeof(dp));
        
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=min(i,r);j++)
            {
                if(i==0||j==0)
                dp[i][j]=1;
                else
                dp[i][j]= ((dp[i-1][j-1]%1000000007)+(dp[i-1][j]%1000000007)%1000000007);
            }
        }
        
        return dp[n][r]%1000000007;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int n, r;
        cin>>n>>r;
        
        Solution ob;
        cout<<ob.nCr(n, r)<<endl;
    }
    return 0;
}  