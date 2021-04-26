#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    
    int get(int s,int n){
        int quot=(s-1)/n;
        int rem=(s-1)%n;
        int row=n-quot-1;
        int col=row%2!=(n%2) ? rem : n-1-rem;
        return row*n+col;
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> vis(n*n+1,0);
        queue<int> que;
        que.push(1);
        vis[1]=1;
        int ans=-1;
        while(!que.empty()){
            ans++;
            int n1=que.size();
            while(n1--){
                int s=que.front();
                que.pop();
                if(s==(n*n)) return ans;
                for(int i=1;i<=6;i++){
                    if((s+i)<=(n*n)){
                        int ns=get(s+i,n);
                        int x=ns/n;
                        int y=ns%n;
                        int fis=board[x][y]==-1 ? (s+i) : (board[x][y]);
                            if(!vis[fis]){
                                vis[fis]=1;
                                que.push(fis);
                            }
                    }
                }
            }
        }
        return -1;
    }
};