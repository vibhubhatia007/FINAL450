#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    int distinct(vector<vector<int>> M, int N)
    {
        set<int> s;
        
        unordered_map<int,int> m;
        for(int i=0;i<N;i++)
        {
            for(int j=0;j<N;j++)
            {
                if(m[M[i][j]]==i)
                m[M[i][j]]=i+1;
                
                
                if(m[M[i][j]]==N)
                s.insert(M[i][j]);
                
            }
        }
        
        return s.size();
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<vector<int>> M(N, vector<int>(N, 0));
        for(int i = 0;i < N*N; i++)
            cin>>M[i/N][i%N];
        
        Solution ob;
        cout<<ob.distinct(M, N)<<"\n";
    }
    return 0;
}  