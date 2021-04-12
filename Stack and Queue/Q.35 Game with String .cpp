// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function Template for C++

class Solution{
public:
    int minValue(string s, int k){
        // code here
        priority_queue<int> q;
        int c[26]={0};int n=s.size();
        for(int i=0;i<n;i++)
        {
            c[s[i]-'a']++;
        }
        
        for(int i=0;i<26;i++)
        {
            q.push(c[i]);
        }
        
        while(q.size()>0&&k--)
        {
            int x=q.top();
            q.pop();
            x--;
            q.push(x);
        }
        
        int ans=0;
        
        while(q.size()>0)
        {
            int x=q.top();
            q.pop();
            ans=ans+x*x;
        }
        
        return ans;
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        int k;
        cin>>s>>k;
        
        Solution ob;
        cout<<ob.minValue(s, k)<<"\n";
    }
}