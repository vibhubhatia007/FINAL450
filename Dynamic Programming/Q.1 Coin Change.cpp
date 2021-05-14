#include<bits/stdc++.h>
using namespace std;


class Solution
{
  public:
    long long int count( int s[], int m, int n )
    {
        long long int dp[n+1][m];
        
        for(int i=0;i<m;i++)
        dp[0][i]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<m;j++)
            {
               long long int x=0,y=0;
               if(i-s[j] >=0)
               x=dp[i-s[j]][j];
               if(j>=1)
               y=dp[i][j-1];
               
               dp[i][j]= x+y;
            }
            
        }
        
        return dp[n][m-1];
    }
};

int main()
{
    int t;
    cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		int arr[m];
		for(int i=0;i<m;i++)
		    cin>>arr[i];
	    Solution ob;
		cout<<ob.count(arr,m,n)<<endl;
	}
    
    
    return 0;
}  

////O(n) space solution////

// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
  public:
    long long int count( int S[], int m, int n )
    {
        long long int dp[n+1]={0};
        dp[0]=1;
        for(int i=0;i<m;i++)
        {
            for(int j=S[i];j<=n;j++)
            {
                dp[j]=dp[j]+dp[j-S[i]];
            }
        }
        
        return dp[n];
    }
};