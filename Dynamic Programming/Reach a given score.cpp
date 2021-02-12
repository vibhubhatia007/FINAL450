#include<bits/stdc++.h>
#define ll long long int
using namespace std;


long long int count(long long int n)
{
  long long int dp[n+1];
  
  for(long long int i=0;i<=n;i++)
  {
      dp[i]=0;
  }
  dp[0]=1;
  
  for(int i=3;i<=n;i++)
  {
     dp[i]+=dp[i-3];
  }
  
   for(int i=5;i<=n;i++)
  {
     dp[i]+=dp[i-5];
  }
  
   for(int i=10;i<=n;i++)
  {
     dp[i]+=dp[i-10];
  }
  
  return dp[n];
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  