
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

     

    void BFS(vector<vector<char>>& grid,int x,int y,vector<vector<int>>& vis)
    {
        int row[] = { -1, -1, -1, 0, 0, 1, 1, 1 };
        int col[] = { -1, 0, 1, -1, 1, -1, 0, 1 };
        
        int r = grid.size();
        int c = grid[0].size();
        
        vis[x][y] = 1;
        queue<pair<int,int>> q;
        q.push({x,y});
        while(q.size()>0)
        {
           int i = q.front().first;
           int j = q.front().second;
           q.pop();
 
        for (int k = 0; k < 8; k++) {
            if ((i + row[k] >= 0) && (i + row[k] < grid.size()) &&
               (j + col[k] >= 0) && (j + col[k] < grid[0].size()) &&
               (grid[i + row[k]][j + col[k]]=='1' && vis[i + row[k]][j + col[k]]==0)) {
             vis[i + row[k]][j + col[k]] = 1;
             q.push(make_pair(i + row[k], j + col[k]));
            }
        }
        
        }
        
    }

    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int r = grid.size();
        int c = grid[0].size();
        vector<vector<int>> vis( r , vector<int> (c, 0)); 
         for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                vis[i][j]==0;
            }
            
        }
        
        int ans=0;
        
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(vis[i][j]==0&&grid[i][j]=='1')
                {BFS(grid,i,j,vis);
                ans++;}
            }
        }
        

        return ans;
        
    }
        
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.numIslands(grid);
		cout << ans <<'\n';
	}
	return 0;
}  