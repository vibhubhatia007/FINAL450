#include<bits/stdc++.h>
using namespace std;


int minJumps(int arr[], int n)
{

    int maxreach=arr[0];
    int steps=arr[0];
    int jumps=1;
    
    if(steps==0)
    return -1;
    
    for(int i=1;i<n;i++)
    {
        if(i==n-1)
        return jumps;
        
         maxreach=max(maxreach,i+arr[i]);
        
        steps--;
        
        if(steps==0||steps<0)
        {
            jumps++;
            if(i>=maxreach)
            return -1;
            else
            steps=maxreach-i;
        }
     
        
    }
    
    
    
}



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,i,j;
        cin>>n;
        int arr[n];
        for(int i=0; i<n; i++)
            cin>>arr[i];
            
        cout<<minJumps(arr, n)<<endl;
    }
    return 0;
}