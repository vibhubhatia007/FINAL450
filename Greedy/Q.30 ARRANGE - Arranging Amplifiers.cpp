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
    while(t--)
    {
     int n ;
     cin>>n;
     vector<int> v;
     int c1=0;int c=0;
     for(int i=0;i<n;i++)
     {
        int x;
        cin>>x;
        if(x==1)
        {
            c1++;
        }
        else
        {
            v.push_back(x);
            c++;
        }
     }
     sort(v.begin(),v.end());
     while(c1--)
     {
        cout<<"1 ";
     }
     if(c==2&&v[0]==2&&v[1]==3){
        cout<<v[0]<<" "<<v[1];
     }
     else{
        for(int i=v.size()-1;i>=0;i--)
        {
            cout<<v[i]<<" ";
        }
     }

     cout<<"\n";


    }

} 
