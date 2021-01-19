#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        int k;
        cin>>n>>k;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        
        int x,y;
        x=lower_bound(a.begin(),a.end(),k)-a.begin();
        y=upper_bound(a.begin(),a.end(),k)-a.begin();
        if(x>=n||y>=n)
        {
            cout<<"-1\n";
        }
        else
        {
        cout<<x<<" "<<y-1<<"\n";
        }
        
    }
}