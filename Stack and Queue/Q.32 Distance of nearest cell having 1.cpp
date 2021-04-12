#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int valid(int i,int j,vector<vector<int>>& grid)
    {
        if(i<grid.size()&&j<grid[i].size()&&i>=0&&j>=0)
        return 1;
        else
        return 0;
    }

	vector<vector<int>>nearest(vector<vector<int>>grid){
	    
	    queue<pair<int,pair<int,int>>> q;
        
        for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(grid[i][j]==1)
                q.push({1,{i,j}});
            }
        }
        
        int ans=0;
        
        while(q.size()>0)
        {
            int c=q.front().first;
            int i=q.front().second.first;
            int j=q.front().second.second;
            q.pop();
            if(valid(i+1,j,grid)&&grid[i+1][j]==0)
            {
                grid[i+1][j]=c+1;
                q.push({c+1,{i+1,j}});
            }
            if(valid(i,j+1,grid)&&grid[i][j+1]==0)
            {
                grid[i][j+1]=c+1;
                q.push({c+1,{i,j+1}});
            }
            if(valid(i-1,j,grid)&&grid[i-1][j]==0)
            {
                grid[i-1][j]=c+1;
                q.push({c+1,{i-1,j}});
            }
             if(valid(i,j-1,grid)&&grid[i][j-1]==0)
            {
                grid[i][j-1]=c+1;
                q.push({c+1,{i,j-1}});
            }
           
        }
        
        
          for(int i=0;i<grid.size();i++)
        {
            for(int j=0;j<grid[i].size();j++)
            {
                if(1)
                {
                   grid[i][j]=grid[i][j]-1;
                }
            }

        }
        
        return grid;
    
	    
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  