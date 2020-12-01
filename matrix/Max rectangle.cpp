
#include <bits/stdc++.h>

using namespace std;
#define MAX 1000

int maxArea(int M[MAX][MAX], int n, int m);
int main() {
    int T;
    cin >> T;

    int M[MAX][MAX];

    while (T--) {
        int n, m;
        cin >> n >> m;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> M[i][j];
            }
        }
        cout << maxArea(M, n, m) << endl;
    }
}


int maxArea(int M[MAX][MAX], int n, int m) 
{
    int t,area,max_area=0;
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(M[i][j]==1)
            M[i][j]+=M[i-1][j];
        }
    }
     
    int m1=0;
    
    for(int i=0;i<n;i++)
    {
    stack<int> s;
    while(s.size()>0)
    {
        s.pop();
    }
    int j=0;
    while(j<m)
    {
        if(s.size()==0)
        {
            s.push(j++);
        }
        else if(M[i][j]>=M[i][s.top()])
        {
            s.push(j++);
        }
        else
        {
            
            t=s.top();
            s.pop();
            area=M[i][t];
            if(s.size()==0)
            area=area*(j);
            else
            area=area*(j-s.top()-1);
            
            if(area>max_area)
            max_area=area;
        }
    }
    
    while(s.size()>0)
    {
        
            t=s.top();
            s.pop();
            area=M[i][t];
            if(s.size()==0)
            area=area*(j);
            else
            area=area*(j-s.top()-1);
            
            if(area>max_area)
            max_area=area;
    }
   
    }
    
   return max_area;

}
