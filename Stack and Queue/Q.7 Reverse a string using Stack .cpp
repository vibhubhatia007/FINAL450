#include<bits/stdc++.h>
using namespace std;

void reverse(char *str, int len);
int main()
{
    long long int t;
    cin>>t;
    while(t--)
    {
        char str[10000];
        cin>>str;
        long long int len=strlen(str);
        reverse(str,len);
        cout<<str;
        cout<<endl;
    }
        return 0;
}


void reverse(char *str, int len)
{
    stack <char> s,s1;

int i=0;int t=len;
while(len--)
{
s.push(str[i++]);
}
int j=0;
while(!s.empty())
{
str[j++]=s.top();
s.pop();
}

}