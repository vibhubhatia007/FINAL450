#include<bits/stdc++.h>
using namespace std;


class Solution {
    public:
    int celebrity(vector<vector<int> >& a, int n) {
        
        stack<int> s;
        for(int i=0;i<n;i++)
        {
            s.push(i);
        }
        while(s.size()>1)
        {
            int x = s.top();
            s.pop();
            int y = s.top();
            s.pop();
            if(a[x][y]==1)
            s.push(y);
            else
            s.push(x);
        }
        
        int cand = s.top();
        
        for(int i=0;i<n;i++)
        {
            if(i!=cand&&a[i][cand]==0)
            return -1;
        }
        
        return cand;
    }
};


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}