#include<bits/stdc++.h>
using namespace std;

bool compare(pair<int,int> &p1, 
             pair<int, int> &p2) 
{ 
    if (p1.second == p2.second) 
        return p1.first < p2.first; 
    return p1.second > p2.second; 
} 

int main() {
int t;
cin>>t;
while(t--)
{int c=0;
 int n;
 cin>>n;
 unordered_map<string,int> m;
 while(n--)
 {
     string s1;
     cin>>s1;
     m[s1]++;
 }
 int s=m.size();
 pair<string , int> p[s]; 
  
int i = 0; 
    for (auto it = m.begin(); it != m.end(); ++it) 
        p[i++] = make_pair(it->first, it->second); 
 
int max1=0;
for(int i=0;i<s;i++)
{
    if(p[i].second>max1)
    max1=p[i].second;
}
int max2=0;int x;
for(int i=0;i<s;i++)
{
    if(p[i].second>max2&p[i].second!=max1)
    {max2=p[i].second;x=i;}
} 

cout<<p[x].first<<"\n";
}
}