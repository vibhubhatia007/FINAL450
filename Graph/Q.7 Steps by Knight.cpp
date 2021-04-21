#include<bits/stdc++.h>
using namespace std;


struct cell { 
    int x, y; 
    int dis; 
    cell() {} 
    cell(int x, int y, int dis) 
        : x(x), y(y), dis(dis) 
    { 
    } 
}; 

class Solution {
public:

    bool isInside(int x, int y, int N) 
    { 
      if (x >= 1 && x <= N && y >= 1 && y <= N) 
        return true; 
      return false; 
    } 
  

     
	int minStepToReachTarget(vector<int>&KnightPos, vector<int>&TargetPos, int n){
	 
    int dx[] = { -2, -1, 1, 2, -2, -1, 1, 2 }; 
    int dy[] = { -1, -2, -2, -1, 1, 2, 2, 1 }; 
    cell t; 
    int x, y; 
    bool visit[n+1][n+1]; 
  
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++) 
            visit[i][j] = false; 
  
    visit[KnightPos[0]][KnightPos[1]] = true; 
    
    queue<cell> q;
    q.push(cell(KnightPos[0], KnightPos[1], 0)); 
    
    while(q.size()>0)
    {
        t=q.front();
        q.pop();
        
        if(t.x==TargetPos[0]&&t.y==TargetPos[1])
        return t.dis;
        
        for(int i=0;i<8;i++)
        {
            x=t.x+dx[i];
            y=t.y+dy[i];
            if(isInside(x,y,n)&&visit[x][y]==false)
            {
                visit[x][y] = true; 
                q.push(cell(x,y,t.dis+1));
            }
        }
    }
    
         
	}
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
} 