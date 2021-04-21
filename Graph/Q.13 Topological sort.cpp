#include <bits/stdc++.h>
using namespace std;


class Solution{
	public:
	
	void dfs(vector<int> adj[],int x,vector<bool> &visited,stack<int> &s){
	visited[x]=true;
	
	for(int i=0;i<adj[x].size();i++)
	{
	    if(visited[adj[x][i]]==false)
	    dfs(adj,adj[x][i],visited,s);
	}
	
	s.push(x);
	
	}
	
	vector<int> topoSort(int V, vector<int> adj[]) {
	    vector<bool> visited(V,false);
	    stack<int> s;vector<int> ans;
	    
	    for(int i=0;i<V;i++)
	    {
	        if(visited[i]==false)
	        {
	            dfs(adj,i,visited,s);
	        }
	    }
	    
	    while(s.size()>0)
	    {
	        ans.push_back(s.top());
	        s.pop();
	    }
	    
	    return ans;
	}
};

int check(int V, vector <int> &res, vector<int> adj[]) {
    vector<int> map(V, -1);
    for (int i = 0; i < V; i++) {
        map[res[i]] = i;
    }
    for (int i = 0; i < V; i++) {
        for (int v : adj[i]) {
            if (map[i] > map[v]) return 0;
        }
    }
    return 1;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N, E;
        cin >> E >> N;
        int u, v;

        vector<int> adj[N];

        for (int i = 0; i < E; i++) {
            cin >> u >> v;
            adj[u].push_back(v);
        }
        
        Solution obj;
        vector <int> res = obj.topoSort(N, adj);

        cout << check(N, res, adj) << endl;
    }
    
    return 0;
}  