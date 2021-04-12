#include <bits/stdc++.h>

using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    int k;
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    cin>>k;
	   queue <int> q;int c=0;
	     for(int i=0;i<n;i++)
	    {
	       if(a[i]<0)
	       {
	         q.push(i);
	       }
	       c++;
	       if(c>=k)
	       {
	           if(q.size()==0)
	           cout<<"0 ";
	           else if(i-q.front()<k)
	           cout<<a[q.front()]<<" ";
	           else
	           {
	               while(q.size()!=0&&i-q.front()>=k)
	               {
	                   q.pop();
	               }
	                if(q.size()==0)
	               cout<<"0 ";
	               else if(i-q.front()<k)
	               cout<<a[q.front()]<<" ";
	           }
	          
	       }
	       
	    }
	    cout<<"\n";
	}
}