#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    long long int countBT(int h,long long int m=1000000007) { 
       long long int dp[h+1];
       dp[0]=1;dp[1]=1;
       for(int i=2;i<=h;i++)
       {
           dp[i-1]=dp[i-1]%m;
           dp[i-2]=dp[i-2]%m;
           dp[i]=((dp[i-1]*dp[i-2])%m)+((dp[i-2]*dp[i-1])%m)+((dp[i-1]*dp[i-1])%m);
           dp[i]=dp[i]%m;
       }
       
       return dp[h];
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int h;
        cin >> h;
        Solution ob;
        cout<<ob.countBT(h)<<endl;  
    }
    return 0;
}