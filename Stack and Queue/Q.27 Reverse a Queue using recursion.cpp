
#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.

void reverse(queue<int>& q)
{
    int x;
    if(q.size()==0)
    {
        return ;
    }
    x = q.front();
    q.pop();
    reverse(q);
    q.push(x);
}

queue<int> rev(queue<int> q)
{
    // add code here.
   reverse(q);
   return q;
    
}