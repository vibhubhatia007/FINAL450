#include<bits/stdc++.h>
using namespace std;


int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int c=0;
        long long int a[n],b[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }    
        b[0]=a[0];
        for(int i=1;i<n;i++)
        {
            b[i]=b[i-1]+a[i];
        }
        sort(b,b+n);
	for(int i=0;i<n;i++)
        {
            if(binary_search(b,b+i,b[i]))
            c=1;
            
        }
        if(binary_search(b,b+n,0))
            c=1;
        if(c==1)
        cout<<"Yes\n";
        else
        cout<<"No\n";
}
}