#include <bits/stdc++.h>
using namespace std;

struct val{
	int first;
	int second;
};



int maxChainLen(struct val p[],int n);
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		val p[n];
		for(int i=0;i<n;i++)
		{
			cin>>p[i].first>>p[i].second;
		}
		
		cout<<maxChainLen(p,n)<<endl;
	}
	return 0;
}


int maxChainLen(struct val p[],int n)
{
vector<pair<int,int> > v;
int dp[n];int ans=1;

for(int i=0;i<n;i++)
{
v.push_back(make_pair(p[i].first,p[i].second));    
dp[i]=1;
}

sort(v.begin(),v.end());

for(int i=0;i<n;i++)
{
    for(int j=0;j<i;j++)
    {
        if(v[i].first>v[j].second&&dp[j]>=dp[i])
        {
            dp[i]=dp[j]+1;
            if(ans<dp[i])
            ans=dp[i];
        }
        
    }
}

return ans;

}