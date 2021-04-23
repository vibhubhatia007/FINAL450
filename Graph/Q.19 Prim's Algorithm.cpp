#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:

    
    int spanningTree(int v, vector<vector<int>> adj[]) {

        vector<int> vis(v);
        
        
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
        
        for(int i=0;i<v;i++)
        {
            vis[i]=0;
        }
        
        q.push({0,0});
        

        
        int e = 0;int ans = 0;
        while(q.size()>0)
        {
            auto best = q.top();
            q.pop();
            
            int edge = best.second;
            int weight = best.first;
            
            if(vis[edge]==1)
            {
                continue;
            }
            
            ans = ans + weight ;
            vis[edge] = 1;
            
            vector<vector<int>> list =  adj[edge];
            for(int i=0;i<list.size();i++)
            {
                if(vis[list[i][0]]==0)
                {
                    q.push({list[i][1],list[i][0]});
                }
            }
            
        }
        
      
        return ans;
        
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}
