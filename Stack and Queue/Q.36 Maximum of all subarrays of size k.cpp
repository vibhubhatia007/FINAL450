#include<bits/stdc++.h>

using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    long long int n;long long int k;
    cin>>n>>k;
    long long int a[n];
    set<long long int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    deque<long long int>  q;int i;
    for(i=0;i<k;i++)
    {
        while((!q.empty())&&a[i]>=a[q.back()])
        q.pop_back();
        
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<" ";
        
        while((!q.empty())&&i-q.front()>=k)
         q.pop_front();
         
        while((!q.empty())&&a[i]>=a[q.back()])
        q.pop_back();
        
         q.push_back(i);
    }
    cout<<a[q.front()]<<"\n";
}
}