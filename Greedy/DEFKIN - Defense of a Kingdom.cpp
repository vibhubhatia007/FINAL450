#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
    int w,h;
    int n;
    cin>>w>>h>>n;
    vector<int> v1;vector<int> v2;
    v1.push_back(0);v1.push_back(w+1);
    v2.push_back(0);v2.push_back(h+1);
    int x1,x2;
    for(int i=0;i<n;i++)
    {
        cin>>x1>>x2;
        v1.push_back(x1);
        v2.push_back(x2);
    }
    int m1=0;int m2=0;
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    for(int i=1;i<n+2;i++)
    {
        if(v1[i]-v1[i-1]>m1)
            m1=v1[i]-v1[i-1];
    }
    for(int i=1;i<n+2;i++)
    {
        if(v2[i]-v2[i-1]>m2)
            m2=v2[i]-v2[i-1];
    }
    m1--;
    m2--;
    cout<<m1*m2<<"\n";
    }
} 