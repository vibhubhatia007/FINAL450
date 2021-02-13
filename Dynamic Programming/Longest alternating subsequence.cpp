#include<bits/stdc++.h>
using namespace std;


class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&a){
		    int n=a.size();
		     int inc=1;int dec=1;
		    for(int i=1;i<n;i++)
		    {
		        if(a[i]>a[i-1])
		        inc=dec+1;
		        else if(a[i]<a[i-1])
		        dec=inc+1;
		        
		    }
		  
		  return max(inc,dec);
		    
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  