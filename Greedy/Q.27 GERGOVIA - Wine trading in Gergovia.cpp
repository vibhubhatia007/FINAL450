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

       
        while(1)
        {
        long long int n;
        cin>>n;
        if(n==0)
        break;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long int dk=0;long long int ck=0;
         for(int i=0; i<n; i++){
            dk+=a[i];
            ck+=abs(dk);
        }
        cout<<ck<<"\n";
        }
}