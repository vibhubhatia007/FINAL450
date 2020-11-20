#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;int k;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int ans=100000;
	    if(a[0]>k)
	    ans=1;
	    for(int i=1;i<n;i++)
	    {
	        a[i]=a[i]+a[i-1];
	        if(a[i]>k && i+1<ans)
	        ans=i+1;
	    }
	    for(int i=0;i<n-1;i++)
	    {
	        for(int j=i+1;j<n;j++)
	        {
	            if(a[j]-a[i]>k)
	            {
	                if(j-i<ans)
	                ans=j-i;
	            }
	        }
	    }
	    
	    cout<<ans<<"\n";
	}
	
}