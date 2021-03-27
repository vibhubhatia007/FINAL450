#include <bits/stdc++.h>

using namespace std;

 string longestPalindrome(string s) {
        
        int n=s.length();
        string odd;string even;
        int x1,x2;string ans="";
        
        for(int i=0;i<n;i++)
        {
            odd=s[i];even="";
            x1=i-1;x2=i+1;
            while(x1>=0&&x2<n&&s[x1]==s[x2])
            {
                odd=s[x1]+odd+s[x2];
                x1--;x2++;
            }
            
             if(odd.length()>ans.length())
                ans=odd;
            if(ans.length()==n)
                break;
            
            x1=i;x2=i+1;
            while(x1>=0&&x2<n&&s[x1]==s[x2])
            {
                
                even=s[x1]+even+s[x2];
                x1--;x2++;
            }
            
           
            if(even.length()>ans.length())
                ans=even;
            if(ans.length()==n)
                break;
        }
        
        
        return ans;
        
    }

int main() {
	//code
	
	int t;
	cin>>t;
	while(t--)
	{
	    string s;
	    cin>>s;
	    cout<< longestPalindrome(s)<<"\n";
	}
	
	
	return 0;
}