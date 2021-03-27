#include <string.h>
#include<bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    string s;
    int n;
    cin>>s;
    n=s.length();
    unordered_map<char,int> m;
    string ans="";
    for(int i=0;i<n;i++)
    {
        if(m[s[i]]==0)
        ans=ans+s[i];
        m[s[i]]++;
    }
    cout<<ans<<"\n";
}
}