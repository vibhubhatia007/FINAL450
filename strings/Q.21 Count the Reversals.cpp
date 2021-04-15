#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    string s1;
	    cin>>s1;
	    stack <char> s;
	    int e=0;int o=0;
	    if(s1.length()%2==1)
	    {
	        cout<<"-1";
	    }
	    else
	    {
	        for(int i=0;i<s1.length();i++)
	        {
	            if(s1[i]=='{')
	            {
	                s.push(s1[i]);e++;
	            }
	            else 
	            {
	                if(s.size()>0&&s.top()=='{')
	                {
	                    s.pop();e--;
	                }
	                else
	                {
	                    s.push(s1[i]);o++;
	                }
	            }
	        }
	        int ans=((e+1)/2)+((o+1)/2);
	        cout<<ans;
	    }
	    cout<<"\n";
	}
}

/////Method: 2//////////

int countRev (string s)
{
    
    stack<char> st;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='{')
        st.push(s[i]);
        else
        {
            if(st.size()!=0&&st.top()=='{')
            st.pop();
            else
            st.push(s[i]);
        }
    }
    
    int e=0;int o=0;
    
    if(st.size()==0)
    return 0;
    else if(st.size()%2==1)
    return -1;
    else
    {
        
        while(st.size()>0)
        {
            if(st.top()=='{')
            e++;
            else
            o++;
            
            st.pop();
        }
    }
    
    return ((e+1)/2 + (o+1)/2 );
    
    
    
}