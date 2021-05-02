
#include<bits/stdc++.h>
using namespace std;


int minJumps( int arr[],  int n){
    
    long long int jumps[n];
    for(int i=0;i<n;i++)
    {
        jumps[i]=INT_MAX;
    }
    jumps[0]=0;
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(j+arr[j]>=i&&arr[j]!=INT_MAX)
            {
                jumps[i]=std::min(jumps[i],jumps[j]+1);
            }
        }
    }
    if(jumps[n-1]==INT_MAX)
    return -1;
    return jumps[n-1];
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