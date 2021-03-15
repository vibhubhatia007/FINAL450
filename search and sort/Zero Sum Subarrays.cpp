#include<bits/stdc++.h>
using namespace std;

#define ll long long 
ll findSubarray(vector<ll> , int );

int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; 
       
        vector<ll> arr(n,0);
        
        for(int i=0;i<n;i++)
            cin>>arr[i]; 
        
        cout << findSubarray(arr,n) << "\n";
    }
	return 0;
}

ll findSubarray(vector<ll> a, int n ) {

    
   for(int i=1;i<n;i++)
   {
       a[i]=a[i-1]+a[i];
   }
   
   unordered_map<int,int> m;
   long long int ans=0;
   
   for(int i=0;i<n;i++)
   {
       m[a[i]]++;
       ans=ans+m[a[i]]-1;
       
       if(a[i]==0)
       ans++;
       
   }
   
   return ans;
}
