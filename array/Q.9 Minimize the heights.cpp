#include<bits/stdc++.h>
using namespace std;

int main()
{
int t;
cin>>t;
while(t--)
{
    int k;
    cin>>k;
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    int mid=a[0]+a[n-1];
    int x=a[n-1]-a[0];
    mid=mid/2;
    for(int i=0;i<n;i++)
    {
       if(a[i]<=mid)
       a[i]=a[i]+k;
       else
       a[i]=a[i]-k;
    }
    sort(a,a+n);
    if(a[n-1]-a[0]<x)
    cout<<a[n-1]-a[0]<<"\n";
    else
    cout<<x<<"\n";
}
}