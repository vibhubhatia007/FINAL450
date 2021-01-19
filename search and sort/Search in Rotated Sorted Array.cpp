#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& a, int target) {
        
        if(a.size()==0)
            return -1;
        
        int n=a.size()-1;int mid;
        int start=0;int end=n;
        

        while(start<end)
        { 
            mid=start+((end-start)/2);
            if(a[mid]>a[end])
            {start=mid+1;}
            else
            {end=mid;}
        }
        
   
        if(a[mid]<=target&&target<=a[n])
        {
            start=mid;end=n;
        }
        else
        {
            start=0;end=mid-1;
        }
        
      
        while(start<=end)
        {
            mid=start+((end-start)/2);
            // if(start==end&&a[mid]!=target)
            //     break;
            if(a[mid]==target)
                return mid;
            else if(a[mid]<target)
                start=mid+1;
            else
                end=mid-1;
        }
        
        return -1;
        
    }
};