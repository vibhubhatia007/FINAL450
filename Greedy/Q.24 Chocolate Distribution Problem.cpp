#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main() {
	long long int t;
	cin>>t;
	while(t--)
	{
	    long int n;
	    long long int a[n];
	    for(long int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    long long int k;
	    cin>>k;
	    long int s=0,e=k-1;long long int dif=INT_MAX;
	   while(e<n)
	   {
	       if(a[e]-a[s]<dif)
	       dif=a[e]-a[s];
	       e++;
	       s++;
	       
	   }
	    
	    cout<<dif<<"\n";
	}
}