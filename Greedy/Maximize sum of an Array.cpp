#include <bits/stdc++.h>
using namespace std;


int main() {
int t;
cin>>t;
while(t--)
{
    
    long long int n;
    cin>>n;
    long long int a[n];
    for(long long int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    sort(a,a+n);
    long long int s=0;
     for(long long int i=0;i<n;i++)
    {
    s=s+i*a[i];
    }
    cout<<s%1000000007<<"\n";
}
}