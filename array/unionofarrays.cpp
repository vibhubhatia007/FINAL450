#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    int m,n;
    cin>>m>>n;
    int a[m];int b[n];
    unordered_map<int,int> m1;
    int c=0;
    
    for(int i=0;i<m;i++)
    {
        cin>>a[i];
        m1[a[i]]++;
        if(m1[a[i]]==1)
        c++;
    }
    for(int i=0;i<n;i++)
    {
        cin>>b[i];
        m1[b[i]]++;
        if(m1[b[i]]==1)
        c++;
    }
 
    
    cout<<c<<"\n";
}
}