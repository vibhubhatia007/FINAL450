#include<bits/stdc++.h> 

using namespace std;


class Solution {
public:
    int maxProfit(vector<int>& a) {
        int n=a.size();
        if(n<2)
            return 0;
        int max=a[n-1];int ans=0;
        for(int i=n-2;i>=0;i--)
        {
            if(max-a[i]>ans)
                ans=max-a[i];
            if(a[i]>max)
                max=a[i];
        }
        
        return ans;
    }
};