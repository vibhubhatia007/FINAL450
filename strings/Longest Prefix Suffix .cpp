 
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:		

		
	int lps(string s)
	{
	  int n=s.length();
	  int i=0;
	  int j=n-1;
	  string pre="";string post="";
	  int ans=0;
	  
	  while(i<n-1&&j>0)
	  {
	      pre=pre+s[i];
	      post=s[j]+post;
	      i++;
	      j--;
	      if(pre==post)
	      {
	       ans=max(ans,i);
	      }
	    
	     
	  }
	  
	    
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
   		string str;
   		cin >> str;

   		Solution ob;

   		cout << ob.lps(str) << "\n";
   	}

    return 0;