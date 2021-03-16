#include <iostream>
#include<bits/stdc++.h>
 
using namespace std;
 
 
 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
   
    int n;
	cin>>n;int t;
	int a[n];
	vector<int> v;
	for(int i=0;i<n;i++)
	{
		cin>>t;
		v.push_back(t);
	}
	sort(v.begin(), v.end());
	a[0]=v[0];
	for(int i=1;i<n;i++)
	{
		a[i]=a[i-1]+v[i];
	}
	int q;
	cin>>q;
	while(q--)
	{
		int p;int ans1;
		cin>>p;
		if(p>=v[n-1])
		ans1=n-1;
		else if(p<v[0])
		ans1=-1;
		else 
		{vector<int>::iterator upper;
		upper=upper_bound(v.begin(), v.end(), p);
		ans1=upper-v.begin()-1;}
		if(ans1==-1)
		cout<<"0 0\n";
		else
		cout<<ans1+1<<" "<<a[ans1]<<"\n"; 
 
	}
} 