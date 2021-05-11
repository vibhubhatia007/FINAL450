#include <bits/stdc++.h>
using namespace std;


void insert(stack<int>& s,int x)
{
    if(s.size()==0)
        s.push(x);
    else
    {
        int a = s.top();
        s.pop();
        insert(s,x);
        s.push(a);
    }
} 

void rev(stack<int>& s)
{
    int x;
    if(s.size()==0)
    {
        return ;
    }
    x = s.top();
    s.pop();
    rev(s);
    insert(s,x);
}


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    stack<int> s;
    s.push(0);
    s.push(1);
    s.push(2);
    s.push(4);
    s.push(8);

    rev(s);

    while(s.size()>0)
    {
        cout<<s.top()<<"\n";
        s.pop();
    }


} 
