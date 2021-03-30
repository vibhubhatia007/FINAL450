#include <bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    long long int ans;
	    if(n==0)
	    ans=0;
	    if(n==1)
	    ans=a[0];
	    if(n==2)
	    ans=max(a[0],a[1]);
	    else
	    {
	        a[1]=max(a[0],a[1]);
	        for(int i=2;i<n;i++)
	        {
	            a[i]=max((a[i]+a[i-2]),(a[i-1]));
	            
	        }
	        
	        ans=a[n-1];
	    }
	    
	    cout<<ans<<"\n";
	    
	    
	}
}