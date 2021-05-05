
#include <bits/stdc++.h>
using namespace std;



class Solution{
    public:
    string findSubString(string s)
    {
        
        int target = 0;int n =s.size();
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==0)
            {
                target++;
                m[s[i]]++;
            }
        }
        
        m.clear();int ans=INT_MAX;int start,end;string y;

        int i=0;int j=0; int c=0;
        while(i<n&&j<n)
        {
           
            while(c<target&&i<n)
            {
                m[s[i]]++;
                if(m[s[i]]==1)
                {
                    c++;
                }
                i++;
            }
            
            // if(i-j<ans&&c>=target)
            // {ans=i-j;
            // start=j;
            // }
   
            
            while(c>=target&&j<n)
            {
                 if(i-j<ans&&c>=target)
                {ans=i-j;
                start=j;
                }
                 m[s[j]]--;
                 if(m[s[j]]==0)
                {
                    c--;
                   
                }
                j++;
               
            }
       
            
        }
       
        
        string x ;
        x = s.substr(start,ans);
        return x;
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {

        string str;
        cin >> str;
        Solution ob;
        cout << ob.findSubString(str).size() << endl;
    }
    return 0;
} 