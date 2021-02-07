#include<bits/stdc++.h>
using namespace std;

int knapSack(int w, int wt[], int val[], int n) 
{ 
   int dp[n+1][w+1];
   memset(dp,0,sizeof(dp));
   for(int i=0;i<=n;i++)
   {
       for(int j=0;j<=w;j++)
       {
           if(i==0||j==0)
           dp[i][j]=0;
           else if(j-wt[i-1]>=0)
           dp[i][j]=max(dp[i-1][j],(val[i-1]+dp[i-1][j-wt[i-1]]));
           else
           dp[i][j]=dp[i-1][j];
       }
   }
   
   return dp[n][w];
}



int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n, w;
        cin>>n>>w;
        
        int val[n];
        int wt[n];
        
        //inserting the values
        for(int i=0;i<n;i++)
            cin>>val[i];
        
        //inserting the weights
        for(int i=0;i<n;i++)
            cin>>wt[i];
        
        cout<<knapSack(w, wt, val, n)<<endl;
        
    }
	return 0;
} 