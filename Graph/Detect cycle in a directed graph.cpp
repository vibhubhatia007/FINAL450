#include<bits/stdc++.h>
using namespace std;



class Solution {
public:

    bool isCyclicUtil(int v, bool visited[], bool *recStack, vector<int> adj[]) 
{ 
    if(visited[v] == false) 
    { 
        visited[v] = true; 
        recStack[v] = true; 
  
        vector<int>::iterator i; 
        for(i = adj[v].begin(); i != adj[v].end(); ++i) 
        { 
            if ( !visited[*i] && isCyclicUtil(*i, visited, recStack, adj) ) 
                return true; 
            else if (recStack[*i]) 
                return true; 
        } 
  
    } 
    recStack[v] = false;  
    return false; 
} 
	bool isCyclic(int V, vector<int> adj[]) {
	   	// code here
	bool *visited = new bool[V]; 
    bool *recStack = new bool[V]; 
    for(int i = 0; i < V; i++) 
    { 
        visited[i] = false; 
        recStack[i] = false; 
    } 
  
    for(int i = 0; i < V; i++) 
        if (isCyclicUtil(i, visited, recStack, adj)) 
            return true; 
  
    return false; 
	}
};


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
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
    	cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}