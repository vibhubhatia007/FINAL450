#include<bits/stdc++.h>
using namespace std;


int main() {
	int t;
	 string s;
	cin>>t;
	while(t--)
	{
        s="";
	    string ans[] = {"2","22","222", 
                    "3","33","333", 
                    "4","44","444", 
                    "5","55","555", 
                    "6","66","666", 
                    "7","77","777","7777", 
                    "8","88","888", 
                    "9","99","999","9999"
                   }; 
        while (s.length()==0 ) 
        getline(cin, s);
        for(int i=0;i<s.length();i++)
        {
            if(s[i]==' ')
            cout<<"0";
            else
            cout<<ans[((int)s[i]-65)];
        }
       
       cout<<"\n";
	}
}