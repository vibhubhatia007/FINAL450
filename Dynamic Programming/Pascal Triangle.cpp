#include <bits/stdc++.h>

using namespace std;
#define ll long long

class Solution{
public:
    vector<ll> nthRowOfPascalTriangle(int n,ll m=1000000007) {
        // code here
        ll dp[n][n];
        vector<ll> ans;
        for(ll i=0;i<n;i++)
        {
            for(ll j=0;j<=i;j++)
            {
                if(j==0||i==j)
                dp[i][j]=1;
                else
                dp[i][j]=((dp[i-1][j]%m)+(dp[i-1][j-1]%m)%m);
            }
        }
        
        int i=n-1;
        for(int j=0;j<=i;j++)
        ans.push_back(dp[i][j]%m);
        
        return ans;
    }
};


void printAns(vector<ll> &ans) {
    for (auto &x : ans) {
        cout << x << " ";
    }
    cout << "\n";
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        Solution ob;
        auto ans = ob.nthRowOfPascalTriangle(n);
        printAns(ans);
    }
    return 0;
}
