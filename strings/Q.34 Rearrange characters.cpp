
#include<bits/stdc++.h>
using namespace std;
const int MAX_CHAR = 26;

 // } Driver Code Ends
class Solution
{
    public:
    string rearrangeString(string s)
    {
        //code here
        unordered_map<char,int> m;
        int me=0;int n= s.size();
        
        
        for(int i=0;i<s.size();i++)
        {
            m[s[i]]++;
            if(me<m[s[i]])
            { me=m[s[i]];}
        }
        
       string ans="";
       priority_queue<pair<int,char>> q; 
       for(char ch='a';ch<='z';ch++)
       {
           q.push({m[ch],ch});
       }
        if(n-me<n/2)
           return "-1";
        else
        {
          while(q.size()>0&&ans.size()<n)
          {
              pair<int,char> p1;
              p1=q.top();
              q.pop();
              if(ans.size()==0||ans[ans.size()-1]!=p1.second)
              {
                  ans=ans+p1.second;
                  int f=p1.first-1;
                  if(f>0)
                      q.push({f,p1.second});
              }
              else
              {
                   pair<int,char> p2;
                   p2=q.top();
                   q.pop();
                   ans=ans+p2.second;
                   int f=p2.first-1;
                   if(f>0)
                      q.push({f,p2.second});
                   q.push(p1);
              }
          }
              return ans;
        }
    }
    
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    string str;
	    cin>>str;
	    Solution ob;
	    string str1=ob.rearrangeString(str);
	    int flag=1;
	    int c[26] = {0};
	    for(int i=0; i<str.length(); i++)
	        c[str[i]-'a']+=1;
	    int f = 0;
	    int x = (str.length()+1)/2;
	    for(int i=0; i<26; i++)
	    {
	        if(c[i]>x)
	            f = 1;
	    }
	    if(f)
	    {
	        if(str1=="-1")
	            cout<<0<<endl;
	        else
	            cout<<1<<endl;
	    }
	    else
	    {
    	    int a[26] = {0};
    	    int b[26] = {0};
    	    for(int i=0; i<str.length(); i++)
    	        a[str[i]-'a']+=1;
    	    for(int i=0; i<str1.length(); i++)
    	        b[str1[i]-'a']+=1;
    	        
    	    for(int i=0; i<26; i++)
    	        if(a[i]!=b[i])
    	            flag = 0;
    	    
    	    for(int i=0;i<str1.length();i++)
    	    {
    		    if(i>0)
    		        if(str1[i-1]==str1[i])
    			        flag=0;
    	    }
    	    if(flag==1)
    		    cout<<"1\n";
    	    else
    	        cout<<"0\n";
	    }
	}
    return 0;
}  // } Driver Code Ends