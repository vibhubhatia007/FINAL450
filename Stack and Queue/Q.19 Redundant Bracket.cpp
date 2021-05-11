
#include <bits/stdc++.h>
using namespace std;


int braces(string A) {
    stack<int> s;
    for(int i=0;i<A.size();i++)
    {
     if(A[i]==')')
     {
         bool flag = false;
         while(s.size()>0&&s.top()!='(')
         {
             char ch = s.top();
             if(ch == '+' || ch == '-' || ch == '*' || ch == '/')
             flag = true;
            s.pop();
         }
         s.pop();
         if(flag == false)
         return 1;
     }
     else
     {
         s.push(A[i]);
     }
    }
    
    return 0;
    
}