#include<bits/stdc++.h> 
using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    int m,n;
    cin>>m>>n;
    int x;
    vector<int> v1,v2;
    while(m--)
    {
        cin>>x;
        v1.push_back(x);
    }
    while(n--)
    {
        cin>>x;
        v2.push_back(x);
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    int c=0;
    for(int i=0;i<v2.size();i++)
    {
        if(binary_search(v1.begin(),v1.end(),v2[i]))
        {
            c++;
        }
    }
    if(c==v2.size())
    {
        cout<<"Yes\n";
    }
    else
    cout<<"No\n";
}
}