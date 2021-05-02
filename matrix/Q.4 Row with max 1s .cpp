
#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	int rowWithMax1s(vector<vector<int> > a, int n, int m) {
	    int j=m-1;
	    while(a[0][j]==1&&j>=0)
	    {
	        j--;
	    }
	    int ans=0;
	    for(int i=1;i<n;i++)
	    {
	        if(a[i][j]==1)
	        {
	             while(a[i][j]==1&&j>=0) {j--; }
	             ans=i;
	           
	        }
	    }
	    if(j==m-1)
	    return -1;
	    
	    return ans;
	}

};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        vector< vector<int> > arr(n,vector<int>(m));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin>>arr[i][j];
            }
        }
        Solution ob;
        auto ans = ob.rowWithMax1s(arr, n, m);
        cout << ans << "\n";
    }
    return 0;
}