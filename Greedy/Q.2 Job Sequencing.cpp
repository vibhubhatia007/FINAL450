#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;	 // Job Id 
    int dead; // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
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
    // your code here
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
    //testcases
    cin >> t;
    
    while(t--){
        int n;
        
        //size of array
        cin >> n;
        Job arr[n];
        
        //adding id, deadline, profit
        for(int i = 0;i<n;i++){
                int x, y, z;
                cin >> x >> y >> z;
                arr[i].id = x;
                arr[i].dead = y;
                arr[i].profit = z;
        }
        //function call
        pair<int,int> ans = JobScheduling(arr, n);
        cout<<ans.first<<" "<<ans.second<<endl;
    }
	return 0; 
}
