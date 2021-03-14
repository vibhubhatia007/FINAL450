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
	    int a[n][n];
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<n;j++)
	        {
	            cin>>a[i][j];
	        }
	    }
	    
	    int c[n]={0};
	    
	    int cnt=0;
	    
	    while(cnt<n*n)
	    {
	        int m=INT_MAX;
	        for(int i=0;i<n;i++)
	        {
	            if(c[i]!=-1)
	            m=min(m,a[i][c[i]]);
	        }
	        
	        
	        for(int i=0;i<n;i++)
	        {
	            if(a[i][c[i]]==m&&i<n)
	            {
	            c[i]=c[i]+1;
	            cnt++;
	            if(c[i]==n)
	            {
	                c[i]=-1;
	            }
	            cout<<m<<" ";
	            }
	            
	        }
	        
	    }
	    
	    cout<<"\n";
	    
	}
}