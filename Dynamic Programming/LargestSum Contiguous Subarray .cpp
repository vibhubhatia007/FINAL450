#include<bits/stdc++.h>
using namespace std;

int maxSubarraySum(int a[], int n){
   int max=a[0];
   for(int i=1;i<n;i++)
   {
       a[i]=a[i]+a[i-1];
       
       if(a[i]>max)
       max=a[i];
   }

   
   int maxsofar=a[n-1];
   
   for(int i=n-1;i>=0;i--)
   {
       if(maxsofar<a[i])
       {
           maxsofar=a[i];
       }
       if(maxsofar-a[i]>max)
       {
           max=maxsofar-a[i];
       }
      
   }
return max;
    
}

int main()
{
    int t,n;
    
    cin>>t; //input testcases
    while(t--) //while testcases exist
    {
        
        cin>>n; //input size of array
        
        int a[n];
        
        for(int i=0;i<n;i++)
            cin>>a[i]; //inputting elements of array
        
        cout << maxSubarraySum(a, n) << endl;
    }
}