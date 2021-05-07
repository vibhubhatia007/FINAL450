#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n,k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    sort(a,a+n);
	    int e;
	    if(n%(k+1)==0)
	    e=(n/(k+1));
	    else
	    e=(n/(k+1))+1;
	    int s1=0,s2=0;
	    int i=0,j=n-1;
	    while(e--)
	    {
	        s1=s1+a[i++];
	        s2=s2+a[j--];
	    }
	    cout<<s1<<" "<<s2<<"\n";
	}
}