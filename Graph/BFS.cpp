#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
	vector<int>bfsOfGraph(int V, vector<int> adj[]){
	    // Code here
	    queue <int> q;
	    unordered_map<int,int> m;
	    q.push(0);
	    vector<int> ans;
	    while(q.size()>0)
	    {
	        ans.push_back(q.front());
	        int x=q.front();
	        q.pop();
	        for(int i=0;i<adj[x].size();i++)
	        {
	            if(m[adj[x][i]]==0)
	            {
	            q.push(adj[x][i]);
	            m[adj[x][i]]++;
	            }
	        }
	        
	    }
	    
	    return ans;
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
    	}
        Solution obj;
        vector<int>ans=obj.bfsOfGraph(V, adj);
        for(int i=0;i<ans.size();i++){
        	cout<<ans[i]<<" ";
        }
        cout<<endl;
	}
	return 0;
}  