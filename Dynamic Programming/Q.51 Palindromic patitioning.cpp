#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int palindromicPartition(string str)
    {
        
        int n = str.length();
 
    int dp[n];
    bool P[n][n];
 
    int i, j, k, L; 

    for (i = 0; i < n; i++) {
        P[i][i] = true;
    }
 
    for (L = 2; L <= n; L++) {
        
        for (i = 0; i < n - L + 1; i++) {
            j = i + L - 1; 
 
            if (L == 2)
                P[i][j] = (str[i] == str[j]);
            else
                P[i][j] = (str[i] == str[j]) && P[i + 1][j - 1];
        }
    }
 
    for (i = 0; i < n; i++) {
        if (P[0][i] == true)
            dp[i] = 0;
        else {
            dp[i] = INT_MAX;
            for (j = 0; j < i; j++) {
                if (P[j + 1][i] == true && 1 + dp[j] < dp[i])
                    dp[i] = 1 + dp[j];
            }
        }
    }

    return dp[n - 1];
        
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        string str;
        cin>>str;
        
        Solution ob;
        cout<<ob.palindromicPartition(str)<<"\n";
    }
    return 0;
}  