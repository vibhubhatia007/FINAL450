#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int square(int n)
{
    if(n==1)
        return 1;

     if (n < 0)
        n = -n;

    int x = n >> 1;
 
    if (n & 1)
        return ((square(x) << 2) + (x << 2) + 1);
    else
        return (square(x) << 2);
}

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
        int n;
        cin>>n;
        cout<<square(n)<<"\n";
    }
}

