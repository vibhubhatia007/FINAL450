#include <iostream>
#include <bits/stdc++.h>
using namespace std;


int main() {
	int t1;
	cin>>t1;
	while(t1--)
	{
	    int n;int t;
	    cin>>n>>t;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    
	    sort(a,a+n);
	    
	    int i=0;int j=0;int dif;
	    while(1)
	    {
	        dif=a[i]-a[j];
	        if(dif==t)
	        {break;}
	        else if(dif<t)
	        i++;
	        if(dif>t)
	        j++;
	        
	        if(i==n-1&&dif<t)
	        break;
	        if(i==n-1&&j==n-1)
	        break;
	        
	    }
	    if(dif==t)
	    cout<<"1\n";
	    else
	    cout<<"-1\n";
	}
	
}