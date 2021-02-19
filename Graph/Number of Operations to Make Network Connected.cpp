#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    void dfs(vector<vector<int>> &adj,int x,vector<bool> &visited){
        
        visited[x]=true;
        
       for(int i=0;i<adj[x].size();i++){
           if(visited[adj[x][i]]==false)
               dfs(adj,adj[x][i],visited);
       }
           }
    int makeConnected(int n, vector<vector<int>>& a) {
        int c=0;
        if(a.size()+1<n)
        return -1;
        
      vector<vector<int>>adj(n);
      vector<bool> visited(n,false);
        
        
        
      for(int i=0;i<a.size();i++)
      {
          adj[a[i][0]].push_back(a[i][1]);
          adj[a[i][1]].push_back(a[i][0]);
      }
        
      for(int i=0;i<n;i++)
      {
          if(visited[i]==false)
          {
              c++;
              dfs(adj,i,visited);
          }
      }
        return c-1 ;
        
        
    }
};