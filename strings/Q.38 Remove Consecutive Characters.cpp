#include <bits/stdc++.h> 
using namespace std; 


class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        // code here.
        string ans="";
        ans=ans+s[0];
        char ch = s[0];
        for(int i=1;i<s.length();i++)
        {
            if(s[i]!=ch)
            {ans=ans+s[i];ch=s[i];}
        }
        
        return ans;
    }
};

int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        Solution ob;
        cout<<ob.removeConsecutiveCharacter(s)<<endl;
    }
} 

