#include<bits/stdc++.h>
using namespace std;



class Solution {
public:
    void deleteMid(stack<int>&s, int sizeOfStack)
    {
        // code here.. 
        stack<int> t;
        while(s.size()-t.size()>1)
        {
            t.push(s.top());
            s.pop();
        }
        

        s.pop();
        
        while(t.size()>0)
        {
            s.push(t.top());
            t.pop();
        }
 
        
    }
    
};

// { Driver Code Starts.
int main() {
    int t;
    cin>>t;
    
    while(t--)
    {
        int sizeOfStack;
        cin>>sizeOfStack;
        
        stack<int> myStack;
        
        for(int i=0;i<sizeOfStack;i++)
        {
            int x;
            cin>>x;
            myStack.push(x);    
        }

            Solution ob;
            ob.deleteMid(myStack,myStack.size());
            while(!myStack.empty())
            {
                cout<<myStack.top()<<" ";
                myStack.pop();
            }
        cout<<endl;
    }   
    return 0;
}
