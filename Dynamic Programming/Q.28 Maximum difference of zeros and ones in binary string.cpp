#include <bits/stdc++.h>
using namespace std;


class Solution{
public:	
	int maxSubstring(string s)
	{
	    int n=s.length();
	    int ans=-1;int c=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(s[i]=='0')
	        c=c+1;
	        else
	        c=c-1;
	        
	        if(c<0)
	        c=0;
	        
	        ans=max(ans,c);
	        
	      
	    }
	    
	    if(ans==0)
	    ans=-1;
	    
	    return ans;
	    
	}
};


int main() 
{
   	

   	ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cout.tie(NULL);
   
   	int t;
   	cin >> t;
   	while(t--)
   	{
   		string s;
   		cin >> s;

   	    Solution ob;

   		cout << ob.maxSubstring(s) << "\n";
   	}

    return 0;
}