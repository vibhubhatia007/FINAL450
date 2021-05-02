#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int r[n];int l[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    l[0]=a[0];r[n-1]=a[n-1];
	    int max=a[0];
	    for(int i=1;i<n;i++)
	    {
	       l[i]=max;
	       if(a[i]>max)
	       max=a[i];
	    }
	    max=a[n-1];
	    for(int i=n-2;i>=0;i--)
	    {
	        r[i]=max;
	        if(a[i]>max)
	        max=a[i];
	    }
	    int ans=0;
	    for(int i=1;i<=n-2;i++)
	    {
	        if(min(l[i],r[i])-a[i]>0)
	        ans=ans+min(l[i],r[i])-a[i];
	    }
	    cout<<ans<<"\n";
	}
}