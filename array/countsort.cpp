#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	     int c1=0,c2=0,c3=0;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	        if(a[i]==0)
	        c1++;
	        if(a[i]==1)
	        c2++;
	        if(a[i]==2)
	        c3++;
	    }
	   while(c1--)
	   {cout<<"0 ";}
	   while(c2--)
	   {cout<<"1 ";}
	   while(c3--)
	   {cout<<"2 ";}
	   
	   cout<<"\n";
	}
}
