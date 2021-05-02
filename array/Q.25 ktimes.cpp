#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;int k;
	    cin>>n>>k;
	    int a[n];int flag=1;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    unordered_map<int,int> m;
	    for(int i=0;i<n;i++)
	    {
	        m[a[i]]++;
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(m[a[i]]==k)
	        {
	            cout<<a[i]<<"\n";
	            flag=0;
	            break;
	        }
	    }
	    if(flag)
	    cout<<"-1\n";
	}
}