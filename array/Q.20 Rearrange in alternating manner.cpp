#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    long long int n;
	    cin>>n;
	    long long int x;
	    vector<long long int> v1,v2,v3;
	    deque <long long int> d;
	    for(int i=0;i<n;i++)
	    {
	        cin>>x;
	        v1.push_back(x);
	    }
	    for(int i=0;i<n;i++)
	    {
	        if(v1[i]>0||v1[i]==0)
	        {
	            v2.push_back(v1[i]);
	        }
	        if(v1[i]<0)
	        {
	            v3.push_back(v1[i]);
	        }
	      
	    }
	    long long int m1,m2;
	    m1=min(v2.size(),v3.size());
	    m2=max(v2.size(),v3.size());
	    for(int i=0;i<m1;i++)
	    {
	       cout<<v2[i]<<" "<<v3[i]<<" ";
	    }
	    for(int i=m1;i<m2;i++)
	    {
	        if(v2.size()>v3.size())
	       cout<<v2[i]<<" ";
	       else
	       cout<<v3[i]<<" ";
	    }
	    cout<<"\n";
	}
}