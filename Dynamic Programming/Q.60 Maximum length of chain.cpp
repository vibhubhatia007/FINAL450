#include <bits/stdc++.h>

using namespace std;


class Solution {
public:
    int findLongestChain(vector<vector<int>>& p) {

int n=p.size();
vector<pair<int,int> > v;
int dp[n];int ans=1;

for(int i=0;i<n;i++)
{
v.push_back(make_pair(p[i][0],p[i][1]));    
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
};