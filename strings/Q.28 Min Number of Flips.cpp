#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;int c=0,c1=0;int e1=0,e=0,o=0,o1=0;
	    for(int i=0;i<s.length();i=i+2)
	    {
	        if(s[i]=='0')
	        e++;
	        if(s[i]=='1')
	        e1++;
	        if(s[i+1]=='0'&&(i+1)<s.length())
	        o++;
	        if(s[i+1]=='1'&&(i+1)<s.length())
	        o1++;
	    }
	 c=e+o1;
	 c1=e1+o;
	 int n=s.length();
	 if(c<c1)
	  c=c1;
	  cout<<n-c<<"\n";
	}
    
}