#include<bits/stdc++.h>
using namespace std;


int main() {
int t;
cin>>t;
while(t--)
{
    string s;
    cin>>s;
    int m[150]={0};
    int i;
    for(i=0;i<s.length();i++)
    {
        m[s[i]]++;
    }
  
    int j=s.length()-1;
       while(m[s[j]]>1)
    {
        m[s[j]]--;
        j--;
    }
    i=0;
    while(m[s[i]]>1&&i<=j)
    {
        m[s[i]]--;
        i++;
    }
     int min=j-i+1;
    int t1=i,t2=j;
    while(j<s.length())
    {
        
        j++;
        m[s[j]]++;
        while(m[s[i]]>1&&i<=j)
        {
             m[s[i]]--;
            i++;
        }
        if(j-i+1<min)
        {min=j-i+1;t1=i;t2=j;}
    }
  
    cout<<min<<"\n";
}
}