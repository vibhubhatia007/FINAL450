
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution{
  public:
    vector<int> duplicates(int a[], int n) {
        // code here
        
        vector<int> ans;
        
        for(int i=0;i<n;i++)
        {
            a[a[i]%n]+=n;
        }
        
        for(int i=0;i<n;i++)
        {
            if(a[i]>=2*n)
            ans.push_back(i);
        }
        
        if(ans.size()==0)
        ans.push_back(-1);
        
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) cin >> a[i];
        Solution obj;
        vector<int> ans = obj.duplicates(a, n);
        for (int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
