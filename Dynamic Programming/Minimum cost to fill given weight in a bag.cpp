#include <bits/stdc++.h>
using namespace std;

#define INF 10000000000

class Solution{
		

	public:
	long long int minimumCost(int cost[], int n, int W) 
	{ 
     vector<int> val, wt;
    int size = 0;
    for (int i=0; i<n; i++)
    {
        if (cost[i]!= -1)
        {
            val.push_back(cost[i]);
            wt.push_back(i+1);
            size++;
        }
    }

 
    n = size;
    long long int dp[n+1][W+1];
 
    for (int i=0; i<=W; i++)
        dp[0][i] = INF;

    for (int i=1; i<=n; i++)
        dp[i][0] = 0;
 
    for (int i=1; i<=n; i++)
    {
        for (int j=1; j<=W; j++)
        {
            if (wt[i-1] > j)
                dp[i][j] = dp[i-1][j];
            else
                dp[i][j] = min(dp[i-1][j],
                     dp[i][j-wt[i-1]] + val[i-1]);
        }
    }
    return (dp[n][W]==INF)? -1: dp[n][W];
        
	} 
};

int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}