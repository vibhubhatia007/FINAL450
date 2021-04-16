#include<iostream>
#include<string.h>

using namespace std;
#define MAX_CHARS 256


#include<bits/stdc++.h>

class Solution{
  public:
    bool areIsomorphic(string s, string t)
    {
    int sl=s.length();
    int tl=t.length();
    if(sl!=tl)
    return false;
    map<char,char> m1;
    map<char,char> m2;
    for(int i=0;i<sl;i++)
    {
    m1[s[i]]=t[i];
    m2[t[i]]=s[i];
    }
    
        for(int i=0;i<sl;i++)
        {
            if(m1[s[i]]!=t[i] || m2[t[i]]!=s[i])
                return false;
        }
        return true;
    }
};


int main()
{
    int t;
    cin>>t;
    string s1,s2;
    while (t--) {
        cin>>s1;
        cin>>s2;
        Solution obj;
        cout<<obj.areIsomorphic(s1,s2)<<endl;
    }
    
    return 0;
}  