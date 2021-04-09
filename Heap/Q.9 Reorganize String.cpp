#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    string reorganizeString(string s) {
        
        unordered_map<char,int> m;
        int me=0;int n= s.size();
        
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            if(me<m[s[i]])
            { me=m[s[i]];}
        }
        
       string ans="";
       priority_queue<pair<int,char>> q; 
       for(char ch='a';ch<='z';ch++)
       {
           q.push({m[ch],ch});
       }
     
       if(n-me<n/2)
           return ans;
        else
        {
          while(q.size()>0&&ans.size()<n)
          {
              pair<int,char> p1;
              p1=q.top();
              q.pop();
              if(ans.size()==0||ans[ans.size()-1]!=p1.second)
              {
                  ans=ans+p1.second;
                  int f=p1.first-1;
                  if(f>0)
                      q.push({f,p1.second});
              }
              else
              {
                   pair<int,char> p2;
                   p2=q.top();
                   q.pop();
                   ans=ans+p2.second;
                   int f=p2.first-1;
                   if(f>0)
                      q.push({f,p2.second});
                   q.push(p1);
              }
          }
              return ans;
        }
    }
};