// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


//User function Template for C++

class Solution{
    public:

    int optimalSearchTree(int keys[], int freq[], int n)
    {
        // code here
        int sum[n][n];
        int cost[n][n];
        
        for(int i=0;i<n;i++)
        {
            cost[i][i]=freq[i];
        }
        
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
             int j=i+l-1;
             sum[i][j]=0;
             for(int k=i;k<=j;k++)
             {
                 sum[i][j]+=freq[k];
             }
            }
        }
        
        for(int l=2;l<=n;l++)
        {
            for(int i=0;i<n-l+1;i++)
            {
             int j=i+l-1;
             cost[i][j]=INT_MAX;
             for(int r=i;r<=j;r++)
             {

                int x = ((r > i)? cost[i][r-1]:0) + 
					((r < j)? cost[r+1][j]:0) + 
					sum[i][j];
                 
                 if(x<cost[i][j])
                 cost[i][j]=x;
             }
            }
        }
        
         return cost[0][n-1];
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin >> n;
        int keys[n];
        for(int i=0;i<n;i++)cin>>keys[i];
        int freq[n];
        for(int i=0;i<n;i++)cin>>freq[i];
        Solution ob;
        cout<<ob.optimalSearchTree(keys, freq, n)<<endl;
    }
    return 0;