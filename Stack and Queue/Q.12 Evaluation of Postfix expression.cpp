#include<bits/stdc++.h>
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    string s1;
    cin>>s1;
    stack <int> s;
    for(int i=0;i<s1.length();i++)
    {
        if(isdigit(s1[i]))
        {
            int x=(int)(s1[i]-48);
            s.push(x);
        }
        else
        {
            int a=s.top();
            s.pop();
            int b=s.top();
            s.pop();
            int c;
            if(s1[i]=='+')
            {
                c=a+b;
                s.push(c);
            }
            if(s1[i]=='*')
            {
                c=a*b;
                s.push(c);
            }
            if(s1[i]=='/')
            {
                c=b/a;
                s.push(c);
            }
            if(s1[i]=='-')
            {
                c=b-a;
                s.push(c);
            }
        }
    }
    cout<<s.top()<<"\n";
}
}