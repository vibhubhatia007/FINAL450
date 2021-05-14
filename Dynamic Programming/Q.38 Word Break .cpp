// { Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

int wordBreak(string A, vector<string> &B);

// User code will be pasted here

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        cout<<wordBreak(line, dict)<<"\n";
    }
}


bool contains(string s, vector<string> &b)
{
    for(int i=0;i<b.size();i++)
    {
        if(s==b[i])
        return true;
    }
    
    return false;
}

int wordBreak(string a, vector<string> &b) {
    //code here
    int n=a.size();
    if(n==0)
    return true;
    
    vector<bool> dp(n+1,0);
    vector<int> match;
    match.push_back(-1);
    
    for(int i=0;i<n;i++)
    {
        int f=0;
        int size=match.size();
        for(int j=size-1;size>=0;size--)
        {
            string s=a.substr(match[j]+1,i-match[j]);
            if(contains(s,b))
            {
                f=1;
                break;
            }
            
        }
        
        if(f==1)
        {
            dp[i]=1;
            match.push_back(i);
        }
    }
    
    return dp[n-1];
    
}