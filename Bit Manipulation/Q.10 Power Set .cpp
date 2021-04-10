#include<bits/stdc++.h>
using namespace std;

class Solution{
	public:
	
	   void powerset(string s,vector<string> &v,int i=0,string cur="")
	   {
	       int n=s.length();
	       if(i==n)
	       {
	       if(cur.length()>0)
	       {
	           v.push_back(cur);
	       }
	       return ;
	           
	       }
	       
	       powerset(s,v,i+1,cur);
	       powerset(s,v,i+1,cur+s[i]);
	   }
	
		vector<string> AllPossibleStrings(string s){
		    // Code here
		    vector<string> v;
		    powerset(s,v);
		    sort(v.begin(),v.end());
		    
		    
		    return v;
		}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string s;
		cin >> s;
		Solution ob;
		vector<string> res = ob.AllPossibleStrings(s);
		for(auto i : res)
			cout << i <<" ";
		cout << "\n";

	}
	return 0;
}  