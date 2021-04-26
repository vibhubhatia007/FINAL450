#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
    
    vector <int> bellman_ford(int v, vector<vector<int>> adj, int src) {

        int MAX = 100000000;
        vector<int> dist(v);
        for(int i=0;i<v;i++)
        {
            dist[i]= MAX;
        }
        dist[src]=0;
        
        for(int i=0;i<v-1;i++)
        {
            for(int j=0;j<adj.size();j++)
            {
                int u = adj[j][0];
                int v = adj[j][1];
                int w = adj[j][2];
                
                if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
                {
                    dist[v]=dist[u]+w;
                }
                
            }
        }
        
        return dist;
        
        
        //check for negative cycle i.e,  if(dist[u]!=INT_MAX&&dist[u]+w<dist[v])
    }
};



int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj;
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1;
            t1.push_back(u);
            t1.push_back(v);
            t1.push_back(w);
            adj.push_back(t1);
        }
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.bellman_ford(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}
