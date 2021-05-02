
#include <bits/stdc++.h>
using namespace std;


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& v, int target) {
        
        int i=0;int j=v[0].size()-1;
        while(i>=0&&i<v.size()&&j>=0&&j<v[i].size())
        {
            if(v[i][j]==target)
                return true;
            else if(v[i][j]<target)
                i++;
            else
                j--;
        }
      
            return false;
        
    }
};