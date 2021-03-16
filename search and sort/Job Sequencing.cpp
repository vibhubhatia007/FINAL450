
#include<bits/stdc++.h>
using namespace std; 

struct Job 
{ 
    int id;	
    int dead; 
    int profit; 
}; 


bool cmp(pair<int,int>  p1,pair<int,int>  p2)
{
    if(p1.second > p2.second)
    return true;
    else
    return false;
}

pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(arr[i].dead,arr[i].profit));
    }
    sort(v.begin(),v.end(),cmp);
    int c=0;int p=0;
    unordered_map<int,int> m;
    for(int i=0;i<n;i++)
    {
       for(int j=v[i].first;j>=1;j--)
       {
           if(m[j]==0)
           {
               m[j]++;
               c++;
               p=p+v[i].second;
               break;
           }
       }
    }
    pair<int,int> ans;
    ans.first=c;
    ans.second=p;
    
    return ans;
} 



int main() 
{ 
    int t;

    cin >> t;
    
    while(t--){
        int n;
        
        cin >> n;
        Job arr[n];
        
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}
