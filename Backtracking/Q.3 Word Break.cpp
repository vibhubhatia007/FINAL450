
#include <bits/stdc++.h>
using namespace std;



class Solution{
public:

    bool contains(vector<string>& dict,int n,string s)
    {
        for(int i=0;i<n;i++)
        {
            if(dict[i]==s)
            return true;
        }
        
        
        return false;
    }
    
    void solve(vector<string>& dict,int n,string s,vector<string>& ans,string res,int ind)
    {
        if(ind==s.size())
        {
            res.resize(res.size() - 1);
            ans.push_back(res);
        }
        
        string x="";
        for(int i=ind;i<s.size();i++)
        {
            x=x+s[i];
            if(contains(dict,n,x))
            solve(dict,n,s,ans,res+x+" ",i+1);
        }
        
    }

    vector<string> wordBreak(int n, vector<string>& dict, string s)
    {
        // code here
        vector<string> ans;string res ="";
        solve(dict,n,s,ans,res,0);
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        vector<string> dict;
        string s;
        cin>>n;
        for(int i = 0;i < n;i++){
            cin>>s;
            dict.push_back(s);
        }
        cin>>s;
        
        Solution ob;
        vector<string> ans = ob.wordBreak(n, dict, s);
        if(ans.size() == 0)
            cout<<"Empty\n";
        else{
            sort(ans.begin(), ans.end());
            for(int i = 0;i < ans.size();i++)
                cout<<"("<<ans[i]<<")";
            cout<<endl;
        }
    }
    return 0;
}  