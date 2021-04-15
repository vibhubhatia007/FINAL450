#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.size() == 0)
		return "";
        
        int i=0;
        while(1){
            int c=1;
            char ch=' ';
        for(int k=0;k<strs.size();k++)
        {
            string x =strs[k];
            if(x.length()<=i)
            {c=0;break;}
            if(ch==' ')
               ch=x[i];
             if(x[i]!=ch)
               {c=0;break;}
               
        }
               
               if(c==1)
               i++;
               else
               break;
        }
               
               string s = strs[0].substr(0,i);
               return s;
    }
};