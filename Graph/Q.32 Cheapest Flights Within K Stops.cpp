#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
        
        queue<pair<int,pair<int,int>>> q;
        //distance,vetex,steps
        vector<int> dist(n, INT_MAX);
        dist[src]=0;
        K++;
        
        vector<vector<pair<int,int>>>graph(n);
        

        for(int i=0;i<flights.size();i++)
        {
            graph[flights[i][0]].push_back(make_pair(flights[i][1],flights[i][2]));
        }

        q.push({0,{src,0}});
        int ans=INT_MAX;
        
        while(q.size()>0)
        {
            int distance = q.front().first;
            int vertex = q.front().second.first;
            int steps = q.front().second.second;
            q.pop();
            if(steps<=K&&distance<ans&&vertex==dst)
            {
                ans=distance;
            }
            if(steps>=K)
                continue;
            
            vector<pair<int,int>> adj = graph[vertex];
            for(int i=0;i<adj.size();i++)
            {
                int v = adj[i].first;
                int w = adj[i].second;
                if(distance+w<dist[v])
                {
                    dist[v]=distance+w;
                    q.push({dist[v],{v,steps+1}});
                }
            }
            
        }
        
        if(dist[dst]==INT_MAX)
            return -1;
        else
        return dist[dst];
        
    }
};