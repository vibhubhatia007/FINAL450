#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
    int m,n;
    cin>>m>>n;
    int a[m][n];
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }
    int top,bot,left,right;
    top=0;
    bot=m-1;
    left=0;
    right=n-1;
    int c=0;
    while(c<m*n)
    {
        for(int i=left;i<=right;i++)
            {cout<<a[top][i]<<" ";c++;}
        top++;
        if(c==m*n)
        break;
        for(int i=top;i<=bot;i++)
           { cout<<a[i][right]<<" ";c++;}
        right--;
        if(c==m*n)
        break;
        for(int i=right;i>=left;i--)
            {cout<<a[bot][i]<<" ";c++;}
        bot--;
        if(c==m*n)
        break;
        for(int i=bot;i>=top;i--)
            {cout<<a[i][left]<<" ";c++;}
        left++;    
    }
    cout<<"\n";
}
}