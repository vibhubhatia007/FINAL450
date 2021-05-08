#include <bits/stdc++.h>
using namespace std;


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output1.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    int cae=0;
    while(t--)
    {
     cae++;
     long long int n,k,b,t;
     cin>>n>>k>>b>>t;
     long long int dist[n];
     long long int vel[n];
        for(int i=0;i<n;i++)
     {
        cin>>dist[i];
     }
     for(int i=0;i<n;i++)
     {
        cin>>vel[i];
     }
  

     long long int possible = 0;
     long long int notpossible = 0;
     long long int ans =0;
     for(int i=n-1;i>=0;i--)
     {
        long long int dist_req = b - dist[i];
        long long int dist_pos = vel[i]*t;
        if(dist_pos>=dist_req)
        {
            possible++;
            if(notpossible>0)
                ans = ans + notpossible;
        }
        else
            notpossible++;

        if(possible>=k)
            break;

     }

     cout<<"Case #"<<cae<<": ";
     if(possible>=k)
        cout<<ans<<"\n";
    else
        cout<<"IMPOSSIBLE\n";

    }

} 
