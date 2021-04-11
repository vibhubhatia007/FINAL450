
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findMaxLen(string s) {
        // code here
        
        stack<int> st;
        st.push(-1);
        for(int i=0;i<s.size();i++)
        {
            if(s.size()==0)
            st.push(i);
            else
            {
                if(s[st.top()]=='('&&s[i]==')')
                st.pop();
                else
                st.push(i);
            }
        }
        
        st.push(s.size());
        
        
        if(st.size()==0)
        return s.size();
        
        int max=0;
        while(st.size()>1)
        {
            int x=st.top();
            st.pop();
            if(x-st.top()-1>max)
            max=x-st.top()-1;
        }
    
        
        return max;
        
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        string S;
        cin >> S; 
        Solution ob;
        cout << ob.findMaxLen(S) << endl;
    }
    return 0;
}
