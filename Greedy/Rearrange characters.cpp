#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    unordered_map<char,int> m;
	    for(int i=0;i<s.length();i++)
	    {
	        m[s[i]]++;
	    }
	    int c=0;
	    while(c<s.length())
	    {
	    for(char ch='a';ch<='z';ch++)
	    {
	        if(m[ch]>=1)
	        {
	            cout<<ch;
	            m[ch]--;
	            c++;
	        }
	    }
	    }
	    cout<<"\n";
	}