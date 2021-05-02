// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++


struct cmp
{
    int operator() (const pair<int,pair<int,int>> p1, const pair<int,pair<int,int>> p2)
    {
        return p1.first > p2.first ;
    }
};


class Solution {
  public:
    vector<vector<int>> sortedMatrix(int N, vector<vector<int>> arr) {
        // code here
    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp >q;
    
    for(int i=0;i<N;i++)
    {
        q.push({arr[i][0],{i,0}});
    }
    
    while(q.size()>0)
    {
        ans.push_back(q.top().first);
        int r=q.top().second.first;
        int c=q.top().second.second;
        c++;
        if(c<N)
        q.push({arr[r][c],{r,c}});
        q.pop();
        
    }
    
    int k=0;
    for(int i=0;i<N;i++)
    {
        for(int j=0;j<N;j++)
        {
            arr[i][j]=ans[k++];
        }
    }
    
    return arr;
    
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<vector<int>> v(N, vector<int>(N));
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++) cin >> v[i][j];
        Solution ob;
        v = ob.sortedMatrix(N, v);
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) cout << v[i][j] << " ";
            cout << "\n";
        }
    }
} 