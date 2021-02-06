#include<bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<int> singleNumber(vector<int> arr) 
    {
    unordered_map<int, int> mp; 
    int n=arr.size();
    vector<int> ans;
    for (int i = 0; i < n; i++) 
        mp[arr[i]]++; 
        
    for(int i=0;i<n;i++)
    {
        if(mp[arr[i]]==1)
        ans.push_back(arr[i]);
    }
    if(ans[0]>ans[1])
    {
        ans[0]=ans[0]+ans[1];
        ans[1]=ans[0]-ans[1];
        ans[0]=ans[0]-ans[1];
    }
    return ans;
    }
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
    	int n; 
    	cin >> n;
    	vector<int> v(2 * n + 2);
    	for(int i = 0; i < 2 * n + 2; i++)
    		cin >> v[i];
    	Solution ob;
    	vector<int > ans = ob.singleNumber(v);
    	for(auto i: ans)
    		cout << i << " ";
    	cout << "\n";
    }
	return 0;
}  