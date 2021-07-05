#include <bits/stdc++.h>
using namespace std;

class Solution{
public:

        int ld[40]={0};
        int rd[40]={0};
        int cl[40]={0};


 
    bool solve(vector<vector<int>>& board,int col,vector<vector<int>>& result) 
    {
        int n = board.size();
        if(col==n)
        {
            vector<int> v;
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(board[i][j]==1)
                    v.push_back(j+1);
                }
            }
            result.push_back(v);
            return true;
        }
        
        bool res;
        for(int i=0;i<n;i++)
        {
            if(ld[i - col + n - 1] ==0 && rd[i + col] ==0 && cl[i] == 0)
            {
                ld[i - col + n - 1] = 1;rd[i + col] = 1; cl[i] = 1;
                board[i][col]=1;
                res=solve(board,col+1,result)||res;
                ld[i - col + n - 1] = 0; rd[i + col] = 0;cl[i] = 0;
                board[i][col]=0;
                
            }
        }
        
        return res;
    }

    vector<vector<int>> nQueen(int n) {
        // code here

        vector<vector<int>> board(n, vector<int>(n, 0));
        vector<vector<int>> result;
        if(n==1)
        return {{1}};
        else if(n<=3)
        return result;
        solve(board,0,result);
        sort(result.begin(),result.end());
        return result;
        
        
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        
        Solution ob;
        vector<vector<int>> ans = ob.nQueen(n);
        if(ans.size() == 0)
            cout<<-1<<"\n";
        else {
            for(int i = 0;i < ans.size();i++){
                cout<<"[";
                for(int u: ans[i])
                    cout<<u<<" ";
                cout<<"] ";
            }
            cout<<endl;
        }
    }
    return 0;
} 