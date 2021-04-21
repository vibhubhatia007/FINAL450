#include <bits/stdc++.h>
using namespace std;


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    unordered_map<string,vector<pair<string,int>>> m;
    m["a"].push_back(make_pair("b",5));
    m["b"].push_back({"c",9});
    m["b"].push_back({"d",7});

    for(auto it=m.begin();it!=m.end();it++)
    {
        string source = it->first;
        vector<pair<string,int>> v= it->second;
        for(int i=0;i<v.size();i++)
        {
            cout<<"Edge from source "<<source<<" to "<<v[i].first<<" of length "<<v[i].second<<"\n";
            
        }
    }

    cout<<"\n";
    for(auto it : m)
    {
        
        for(auto it2 : it.second)
        {
            cout<<it.first<<" --> ";
            cout<<it2.first<<" length "<<it2.second<<"\n";
        }
    }

} 
