#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:
    vector <int> dijkstra(int v, vector<vector<int>> adj[], int s) {
        // Code here
        vector<int> dist(v,INT_MAX);
        priority_queue< pair<int, int>, vector<pair<int,int> >,greater<pair<int, int> > > q;
        q.push(make_pair(0,s));
        int parent[v];
        dist[s]=0;
        
        
        while(q.size()>0)
        {
            int x=q.top().second;
            int d=q.top().first;
            q.pop();
            for(auto it = adj[x].begin(); it != adj[x].end(); it++)
		{
			int v1 = (*it)[0];
			int w = (*it)[1];
            
			if(dist[v1] > dist[x] + w)
			{
				dist[v1] = dist[x]+w;
				q.push(make_pair(dist[v1],v1));
				parent[v1] = x;
			}
		}
        }
        
   return dist;
        
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
        int S;
        cin>>S;
        
        Solution obj;
    	vector<int> res = obj.dijkstra(V, adj, S);
    	
    	for(int i=0; i<V; i++)
    	    cout<<res[i]<<" ";
    	cout<<endl;
    }

    return 0;
}