#include<bits/stdc++.h>

using namespace std;

class StackQueue{
private:
    stack<int> s1;
    stack<int> s2;
public:
    void push(int B);
    int pop();

};
int main()
{

    int T;
    cin>>T;
    while(T--)
    {
        StackQueue *sq = new StackQueue();

        int Q;
        cin>>Q;
        while(Q--){
        int QueryType=0;
        cin>>QueryType;
        if(QueryType==1)
        {
            int a;
            cin>>a;
            sq->push(a);
        }else if(QueryType==2){
            cout<<sq->pop()<<" ";

        }
        }
        cout<<endl;
    }


}


void StackQueue :: push(int x)
 {
        // Your Code
        s1.push(x);
 }

/*The method pop which return the element poped out of the queue*/
int StackQueue :: pop()
{
        // Your Code   
        int ans;
        if(s1.size()==0)
        return -1;
        else if(s1.size()==1)
        {
            ans=s1.top();
            s1.pop();
        }
        else
        {
            int t1,t2;
            while(s1.size()>1)
            {
                t1=s1.top();
                s2.push(t1);
                s1.pop();
            }
            ans=s1.top();
            s1.pop();
            while(s2.size()>0)
            {
                t2=s2.top();
                s1.push(t2);
                s2.pop();
            }
        }
        return ans;
}
