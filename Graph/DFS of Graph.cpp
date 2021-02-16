#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
	vector<int>dfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    stack <int> s;
	    unordered_map<int,int> vis;
	    s.push(0);
	    vector<int> v;
	    v.push_back(0);
	    vis[0]=1;
	    while(s.size()>0)
	    {
	        int x=s.top();
	       // v.push_back(x);
	        if(adj[x].size()==0)
	        s.pop();
	        else
	        {
	            if(vis[adj[x][0]]==0)
	            {
	            v.push_back(adj[x][0]);
	            s.push(adj[x][0]);
	            vis[adj[x][0]]=1;
	            adj[x].erase(adj[x].begin());
	            
	            }
	            else
	            {
	             adj[x].erase(adj[x].begin());
	            }
	        }
	    }
	    
	    return v;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
    	cin >> V >> E;

    	vector<int> adj[V];

    	for(int i = 0; i < E; i++)
    	{
    		int u, v;
    		cin >> u >> v;
    		adj[u].push_back(v);
    		adj[v].push_back(u);
    	}
        // string s1;
        // cin>>s1;
        Solution obj;
        vector<int>ans=obj.dfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  