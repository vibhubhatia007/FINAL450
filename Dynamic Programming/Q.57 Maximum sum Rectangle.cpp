#include<iostream>
#include <bits/stdc++.h>

using namespace std;


int solve(int a[],int n)
{
    int cur=0;int m=0;
    
    for(int i=0;i<n;i++)
    {
        cur=cur+a[i];
        
        if(cur>m)
        m=cur;
        
        if(cur<0)
        cur=0;
    }
    
    return m;
}

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int r,c;
         cin>>r>>c;
         int a[r+1][c];
         for(int j=0;j<c;j++)
         {
             a[0][j]=0;
         }
         for(int i=1;i<=r;i++)
         {
             for(int j=0;j<c;j++)
             {
                 cin>>a[i][j];
             }
         }

        for(int i=1;i<=r;i++)
        {
            for(int j=0;j<c;j++)
            {
                a[i][j]=a[i][j]+a[i-1][j];
            }
        }
        
        int x[c]={0};int ans=0;
        
        for(int r1=0;r1<r;r1++)
        {
            for(int r2=r1+1;r2<=r;r2++)
            {
                for(int i=0;i<c;i++)
                {
                    x[i]=a[r2][i]-a[r1][i];
                }
                if(ans<solve(x,c))
                {
                    ans=solve(x,c);
                }
                
            }
        }
        
        cout<<ans<<"\n";
         
     }
}