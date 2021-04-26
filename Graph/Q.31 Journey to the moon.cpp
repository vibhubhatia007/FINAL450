#include<bits/stdc++.h>
using namespace std;



long long int journeyToMoon(long long int n, vector<vector<int>> astronaut) {
    
    vector<long long int> adj[n];
    for(long long int i=0;i<astronaut.size();i++)
    {
        long long int u = astronaut[i][0];
        long long int v = astronaut[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<long long int> vis(n);
    for(int i=0;i<n;i++)
    {
        vis[i]=0;
    }
    
    long long int ans = (n*(n-1))/2;
    long long int s;
    for(long long int i=0;i<n;i++)
    {
        s=0;
        if(vis[i]==0)
        {
            vis[i]=1;
            s=1;
            queue<long long int> q;
            q.push(i);
            while(q.size()>0)
            {
                int x =q.front();
                q.pop();
                vector<long long int> v = adj[x];
                for(long long int i=0;i<v.size();i++)
                {
                    if(vis[v[i]]==0){
                        vis[v[i]]=1;
                        q.push(v[i]);
                        s++;
                    }
                }
            }
        }
      
        cout<<ans<<" "<<i<<"\n";
        if(s>1)
        ans=ans-((s*(s-1))/2);
        
    }
    
    return ans;

}
