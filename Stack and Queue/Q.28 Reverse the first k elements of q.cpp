// { Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main(){
    int t;
    cin>>t;
    while(t-->0){
        int n,k;
        cin>>n>>k;
        queue<int> q;
        while(n-->0){
            int a;
            cin>>a;
            q.push(a);
        }
        queue<int> ans=modifyQueue(q,k);
        while(!ans.empty()){
            int a=ans.front();
            ans.pop();
            cout<<a<<" ";
        }
        cout<<endl;
    }
}


void reverse(queue<int>& q)
{
    if(q.size()==0)
    {
        return ;
    }
    int x =q .front();
    q.pop();
    reverse(q);
    q.push(x);
}

queue<int> modifyQueue(queue<int> q, int k)
{
    //add code here.
    queue<int> t;
    while(k>0&&q.size()>0)
    {
        t.push(q.front());
        q.pop();
        k--;
    }
    
    reverse(q);
    
    while(t.size()>0)
    {
        q.push(t.front());
        t.pop();
    }
    
    reverse(q);
    
    
    return q;
}