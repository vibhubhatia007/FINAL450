
#include<bits/stdc++.h>
#define N 105
using namespace std;
void printArray(vector<int> arr, int size)
{
for (int i=0; i < size; i++)
	cout << arr[i] << " ";
}


struct cmp
{
    int operator() (const pair<int,pair<int,int>> p1, const pair<int,pair<int,int>> p2)
    {
        return p1.first > p2.first ;
    }
};


class Solution
{
    public:
    
    vector<int> mergeKArrays(vector<vector<int>> arr, int k)
    {

    vector<int> ans;
    priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, cmp >q;
    
    for(int i=0;i<k;i++)
    {
        q.push({arr[i][0],{i,0}});
    }
    
    while(q.size()>0)
    {
        ans.push_back(q.top().first);
        int r=q.top().second.first;
        int c=q.top().second.second;
        c++;
        if(c<k)
        q.push({arr[r][c],{r,c}});
        q.pop();
        
    }
    
    return ans;
    
    }
};



int main()
{
	int t;
	cin>>t;
	while(t--){
	    int k;
	    cin>>k;
	    vector<vector<int>> arr(N, vector<int> (N, 0));
	    for(int i=0; i<k; i++){
	        for(int j=0; j<k; j++)
	        {
	            cin>>arr[i][j];
	        }
	    }
	    Solution obj;
    	vector<int> output = obj.mergeKArrays(arr, k);
    	printArray(output, k*k);
    	cout<<endl;
    }
	return 0;
}

