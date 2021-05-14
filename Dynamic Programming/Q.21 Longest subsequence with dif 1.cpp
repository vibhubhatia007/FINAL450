// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int longestSubsequence(int n, int A[])
    {

        int dp[n]={0};
        for(int i=0;i<n;i++)
        dp[i]=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(abs(A[i]-A[j])==1&&dp[i]<=dp[j])
                {
                    dp[i]=dp[j]+1;
                }
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++)
        ans=max(ans,dp[i]);
        
        return ans;
        
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int A[N];
        for(int i = 0;i < N;i++)
            cin>>A[i];
        
        Solution ob;
        cout<<ob.longestSubsequence(N, A)<<endl;
    }
    return 0;
}  