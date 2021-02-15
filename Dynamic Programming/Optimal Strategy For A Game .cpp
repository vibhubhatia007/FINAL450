#include <bits/stdc++.h>
using namespace std;


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