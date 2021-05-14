#include <iostream>
#include <climits> 
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    int profit [k+1][n+1];
    for(int i=0;i<=k;i++)
    {profit[i][0]=0;}
     for(int i=0;i<=n;i++)
    {profit[0][i]=0;}
   for (int i = 1; i <= k; i++) { 
        int prevDiff = INT_MIN; 
        for (int j = 1; j < n; j++) { 
            prevDiff = max(prevDiff, 
                           profit[i - 1][j - 1] - a[j - 1]); 
            profit[i][j] = max(profit[i][j - 1], 
                               a[j] + prevDiff); 
        } 
    } 
  
    cout<<profit[k][n - 1]<<"\n"; 
}
}