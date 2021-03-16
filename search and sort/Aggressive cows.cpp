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
        long long int n,cw;
        cin>>n>>cw;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        sort(a,a+n);

        long long int l=0;long long int ans;
        long long int m;
        long long int h=a[n-1];

        while(l<=h)
        {
            m=(l+h+1)/2;
            long long int s,c;
            s=0;c=1;
            for(int i=1;i<n && c<cw ;i++)
            {
                if(a[i]-a[s]>=m)
                {
                    c++;
                    s=i;
                }
            }
            if(c>=cw)
            {
                ans=m;
                l=m+1;
            }
            else
            {
                h=m-1;
            }
           
        }

        cout<<ans<<"\n";

    }     

} 
