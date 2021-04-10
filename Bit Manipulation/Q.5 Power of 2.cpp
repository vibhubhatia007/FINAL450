#include <math.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        long long int n;
        cin>>n;
        double x=(double) log2(n);
        int x1=log2(n);
        double y=(double) x1;
        if(x==y)
        {
            cout<<"YES\n";
        }
        else
        {
            cout<<"NO\n";
        }
         
    }
  
}