#include<bits/stdc++.h>
using namespace std;
#define ll long long

long long int maximizeSum(long long int a[], int n, int k);

int main()
 {
     int t;
     cin>>t;
     while(t--)
     {
         int n, k;
         cin>>n>>k;
         long long int a[n+5];
         for(int i=0;i<n;i++)
         cin>>a[i];
         
         cout<<maximizeSum(a, n, k)<<endl;
     }
	
	return 0;
}





long long int maximizeSum(long long int a[], int n, int k)
{
    // Your code goes here
    long long int s=0;
    sort(a,a+n);
    int i=0;
    while(k>0 && a[i]<0 && i<n)
    {
        a[i]=a[i]*-1;
        i++;
        k--;
    }
    sort(a,a+n);
    long long int ans=0;
    for(int i=1;i<n;i++)
    {
        ans=ans+a[i];
    }
    if(k>0&&k%2==1)
    {
        ans=ans-a[0];
    }
    else
    ans=ans+a[0];
    
    return ans;
}