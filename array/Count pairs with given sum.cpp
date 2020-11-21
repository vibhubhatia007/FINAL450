
#include <bits/stdc++.h>
using namespace std;


class Solution{   
public:
    int getPairsCount(int a[], int n, int k) {
        // code here
        unordered_map<int,int> m;
        int ans=0;
        for(int i=0;i<n;i++)
        {
          m[a[i]]++;
        }
        for(int i=0;i<n;i++)
        {
            if(k-a[i]!=a[i])
          ans=ans+m[k-a[i]];
          else
           ans=ans+m[k-a[i]]-1;
        }
        ans=ans/2;
        
        return ans;
        
    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k;
        cin >> n >> k;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.getPairsCount(arr, n, k);
        cout << ans << "\n";
    }
    
    return 0;
}