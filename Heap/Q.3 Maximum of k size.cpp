///method -1 : Heap //////

#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        priority_queue<pair<int,int>> q;
        vector<int> ans;
        
        for(int i=0;i<nums.size();i++)
        {
            while(q.size()>0&&i-q.top().second>=k)
                q.pop();
            
            q.push({nums[i],i});
                
            if(i>=k-1)
                ans.push_back(q.top().first);
        }
        
        return ans;
    }
};


//// method-2 : Using dequeue //////


#include<bits/stdc++.h>

using namespace std;

int main() {
int t;
cin>>t;
while(t--)
{
    long long int n;long long int k;
    cin>>n>>k;
    long long int a[n];
    set<long long int> s;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    deque<long long int>  q;int i;
    for(i=0;i<k;i++)
    {
        while((!q.empty())&&a[i]>=a[q.back()])
        q.pop_back();
        
        q.push_back(i);
    }
    for(;i<n;i++)
    {
        cout<<a[q.front()]<<" ";
        
        while((!q.empty())&&i-q.front()>=k)
         q.pop_front();
         
        while((!q.empty())&&a[i]>=a[q.back()])
        q.pop_back();
        
         q.push_back(i);
    }
    cout<<a[q.front()]<<"\n";
}
}