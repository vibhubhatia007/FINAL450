// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends

class Solution{
public:
    string chooseandswap(string s){
        // Code Here
        string a="";
        unordered_map<char,int> m;
        for(int i=0;i<s.size();i++)
        {
            if(m[s[i]]==0)
            {
                a=a+s[i];
                m[s[i]]++;
            }
        }
        
        string t = a;
        sort(t.begin(),t.end());
        int i;
        for(i=0;i<a.size();i++)
        {
            if(a[i]!=t[i])
            break;
        }
        char x=a[i];
        char y=t[i];
        
        for(i=0;i<s.size();i++)
        {
            if(s[i]==x)
            s[i]=y;
            else if(s[i]==y)
            s[i]=x;
        }
        
        return s;
    }
    
};



int main()
{
    Solution obj;
	int t;
	cin >> t;
	while(t--)
	{	
	    string a;
		cin >> a;
		cout << obj.chooseandswap(a) << endl;
	}
	return 0;
}
