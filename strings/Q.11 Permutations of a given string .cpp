#include<bits/stdc++.h>
using namespace std;

class Solution
{
	public:
	
	    void solve(string a,vector<string> &t,int l,int r)
	    {
	        if(l==r)
	        t.push_back(a);
	        else
	        {
	            for(int i=l;i<=r;i++)
	            {
	                swap(a[l],a[i]);
	                solve(a,t,l+1,r);
	                swap(a[l],a[i]);
	            }
	        }
	        
	        
	    }
	
		vector<string>find_permutation(string S)
		{
		    string ans="";vector<string> t;
		    solve(S,t,0,S.length()-1);
		    sort(t.begin(),t.end());
		    return t;
		}
};


int main(){
    int t;
    cin >> t;
    while(t--)
    {
	    string S;
	    cin >> S;
	    Solution ob;
	    vector<string> ans = ob.find_permutation(S);
	    for(auto i: ans)
	    {
	    	cout<<i<<" ";
	    }
	    cout<<"\n";
    }
	return 0;
}