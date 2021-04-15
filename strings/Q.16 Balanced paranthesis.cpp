#include<bits/stdc++.h>

using namespace std;
 
int main() {
  
    int t;
     stack <char> s1;
    cin>>t;
    while(t--)
    {
	string s;
	cin>>s;
	int c=0;

	int l=s.length();
	for(int i=0;i<l;i++)
	{
	    if(s[i]=='['||s[i]=='('||s[i]=='{')
	    {
	        s1.push(s[i]);
	    }
	    else
	    {
	    if(!s1.empty()){
	    if((s1.top()=='['&&s[i]==']')||(s1.top()=='('&&s[i]==')')||(s1.top()=='{'&&s[i]=='}'))
	        {c++;s1.pop();}
	        else
	        break;
	    }
	    }
	}

	if(s1.empty()&&c==(l+1)/2)
	{
	    cout<<"balanced"<<"\n";
	}
	else
	{
	    cout<<"not balanced"<<"\n";
	}
//cout<<c<<"\n";
while(!s1.empty())
s1.pop();
}
}