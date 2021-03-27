#include<bits/stdc++.h>
using namespace std;

int main() 
{
	int t;
	cin>>t;
	while(t--)
	{
	    string s1,s2;
	    cin>>s1>>s2;
	    int n=s1.length();
	    int c=0;
	    string s;
	    s1=s1+s1;
	    if((s1).find(s2)!=string::npos&&n==s2.length())
	    c=1;
	    if(c==1)
	    {
	        cout<<"1\n";
	    }
	    else
	    {
	        cout<<"0\n";
	    }
	}
}