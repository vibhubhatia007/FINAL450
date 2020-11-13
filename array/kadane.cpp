#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int a[], int n){
    
    int cur=0;int max=0;
    
    for(int i=0;i<n;i++)
    {
        cur=cur+a[i];
        
        if(cur>max)
        max=cur;
        
        if(cur<0)
        cur=0;
    }

    return max;

    
}


int main()
{
    int t,n;
    
    cin>>t; 
    while(t--) 
    {
        
        cin>>n;
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; 
        
        cout << maxSubarraySum(a, n) << endl;
    }
}