#include <bits/stdc++.h>
using namespace std;


/////////////Solution 1 using gap strategy/////////////////////

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    
    long long dp[n][n];
    memset(dp,0,sizeof(dp));
    long long val1,val2;
    
    for(int g=0;g<n;g++)
    {
        for(int i=0,j=g;j<n;i++,j++)
        {
            if(g==0)
            dp[i][j] = arr[i];
            else if(g==1)
            dp[i][j] = max(arr[i],arr[j]);
            else
            {
             int val1 = arr[i] + min(dp[i+2][j],dp[i+1][j-1]);
            // arr[i] + min(i+1,j)
             int val2 =  arr[j] + min(dp[i+1][j-1],dp[i][j-2]);
             // arr[j] + min(i,j-1)
             dp[i][j] = max(val1,val2);
            }
        }
    }
    
    return dp[0][n-1];
}

///////////////////Solution 2/////////////////////////////////////


 long long  dp[1000][1000]; 
 
long long solve(int arr[],int i,int j,int s)
{
    if(i+1==j)
    return max(arr[i],arr[j]);
    
    if(dp[i][j]!=-1)
    return dp[i][j];
    
    dp[i][j]=max(s-solve(arr,i+1,j,s-arr[i]),s-solve(arr,i,j-1,s-arr[j]));
    
    return dp[i][j];
}

long long maximumAmount(int arr[], int n) 
{
    // Your code here
    long long  s=0;
    for(int i=0;i<n;i++)
    {
        s=s+arr[i];
    }
   
    memset(dp,-1,sizeof(dp));
    
    
    return solve(arr,0,n-1,s);
    
    
}

// { Driver Code Starts.

int main() {
    
    //taking total testcases
	int T;
	cin>>T;
	while(T--)
	{
	    //taking number of elements
	    int N;
	    cin>>N;
	    
	    int A[N];
	    
	    //inserting the elements
	    for(int i=0;i<N;i++)
	    cin>>A[i];
	    
	    //calling function maximumAmount()
	    cout<<maximumAmount(A,N)<<endl;
	    
	}
	return 0;
} 