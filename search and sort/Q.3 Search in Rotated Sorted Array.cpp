#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int pivot(vector<int> a)
    {
        
        int l=0;
        int r=a.size()-1;
        
        while(l<r)
        {
            int mid=(r+l)/2;
            
            if(a[mid]>a[r])
                l=mid+1;
            else 
                r=mid;
        }
        
        return l;
    }
    
    int search(vector<int> a,int l,int r,int target)
    {
        while(l<=r)
        {
            int mid=(r+l)/2;
            if(a[mid]==target)
                return mid;
            else if(a[mid]<target)
                l=mid+1;
            else
                r=mid-1;
        }
        return -1;
    }
    
    int search(vector<int>& a, int target) {
        int n=a.size();
        int p = pivot(a);
        int x=search(a,0,p-1,target);
        int y=search(a,p,n-1,target);
        x=max(x,y);
        return x;
        
        
    }
};