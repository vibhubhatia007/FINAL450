
#include<bits/stdc++.h>
using namespace std;


class Solution{
	public:

    
    int find(int i,vector<int>& parent)
    {
        if(parent[i]==-1)
        return i;
        
        return parent[i]=find(parent[i],parent);
    }
    
    bool add(int x,int y,vector<int>& parent,vector<int>& rank)
    {
        int s1 = find(x,parent);
        int s2 = find(y,parent);
        
        if(s1!=s2)
        {
            if(rank[s1]<rank[s2])
            {
                parent[s1]=s2;
                rank[s1]=rank[s1]+rank[s2];
            }
            else
            {
                parent[s2]=s1;
                rank[s2]=rank[s1]+rank[s2];
            }
            
            return true;
        }
        else
        {
            return false;
        }
    }
    
    int spanningTree(int v, vector<vector<int>> adj[]) {

        vector<int> parent(v);
        vector<int> rank(v);
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> q;
        
        for(int i=0;i<v;i++)
        {
            parent[i]=-1;
            rank[i]=1;
        }
        
        for(int i=0;i<v;i++)
        {
             vector<vector<int>> edge = adj[i];
             for(int j=0;j<edge.size();j++)
             {
                 q.push({edge[j][1],{i,edge[j][0]}});
             }
        }
        
        int e=0;int ans=0;
        while(q.size()>0&&e<v-1)
        {
            int u1 = q.top().second.first;
            int u2 = q.top().second.second;
            int w = q.top().first;
            
            if(add(u1,u2,parent,rank))
            {
                ans=ans+w;
                e++;
            }
            
            q.pop();
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

