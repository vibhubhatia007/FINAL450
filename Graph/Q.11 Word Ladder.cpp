#include<bits/stdc++.h>
using namespace std;


class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_map<string,vector<string>> adj;
         wordList.push_back(beginWord);
        for(int i =0;i<wordList.size();i++)
        {
            for(int j = i+1; j<wordList.size();j++)
            {
                string s1 = wordList[i];
                string s2 = wordList[j];
                int count = s1.size()-1;
                for(int k=0 ; k<s1.size() ; k++)
                {
                    if(s1[k]==s2[k])
                    {
                        count --;
                    }
                }
                
                if(count == 0)
                {
                  
                    adj[s1].push_back(s2);
                    adj[s2].push_back(s1);
                }
            }
            
        }
        unordered_map<string,int> vis;
        queue<pair<string,int>> q;
        vis[beginWord]= 1;
        q.push({beginWord,0});
        string top;
        while(q.size()>0)
        {
            top = q.front().first;
            int dis = q.front().second;
            q.pop();
            if(top  == endWord)
                return dis+1;
            
            vector<string> neb = adj[top];
            for(int i = 0 ; i < neb.size() ;i++)
            {
                if(vis[neb[i]] == 0)
                {
                    cout<<neb[i]<<" ";
                    q.push({neb[i],dis+1});
                    vis[neb[i]] = 1;
                }
            }
            cout<<"\n";
          
            
        }
        
     
            return 0;
        
    }
};