#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    vector <int> v;
	    v.push_back(1);
	    
	    for(int i=2;i<=n;i++)
	    {
	        int x=v[0]*i;
	        v[0]=x%10;
	        x=x/10;
	        int j=1;
	        while(j<v.size())
	        {
	            x=(v[j]*i)+x;
	            v[j]=x%10;
	            x=x/10;
	            j++;
	        }
	        while(x!=0)
	        {
	           v.push_back(x%10);
	           x=x/10;
	        }
	    }
	    
	    
	    reverse(v.begin(),v.end());
	    
	    for(int i=0;i<v.size();i++)
	    {
	        cout<<v[i];
	    }
	    cout<<"\n";
	}
}