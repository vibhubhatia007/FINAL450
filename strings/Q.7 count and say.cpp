#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string countAndSay(int n) {
        string s="1";
        if(n==1)
            return s;
        string t="";
        n--;
       while(n--)
       {
           int i=0;int c=0;
           while(i<s.length())
           {
               c=0;
               while(s[i+1]==s[i]&&i+1<s.length())
               {
                   c++;i++;
               }
               c++;
               t=t+to_string(c)+s[i];
               i++;
           }
           s=t;
           t="";
       }
        
       return s;
    }
};