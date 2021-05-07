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
	    sort(a,a+n);
	    int i=0;int j=n-1;
	    vector<int> v;
	    while(i<j)
	    {
	        v.push_back(a[i++]);
	        v.push_back(a[j--]);
	    }
	    if(i==j)
	    v.push_back(a[i]);
	    int ans=0;
	    for(int i=1;i<n;i++)
	    {
	        ans=ans+abs(v[i]-v[i-1]);
	    }
	    ans=ans+abs(v[0]-v[n-1]);
	    
	    cout<<ans<<"\n";
	    
	}
}