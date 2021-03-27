#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	
	
	int isPlaindrome(string s)
	{
	     if(s.length()<=1)
	      return true;
	   else
	   {
	       int n=s.length()-1;
	       if(s[0]==s[n])
	       {
	       s=s.substr(1,n-1);
	       return isPlaindrome(s);
	       }
	       else
	       {
	           return false;
	       }
	   }
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

   		cout << ob.isPlaindrome(s) << "\n";
   	}

    return 0;
}  