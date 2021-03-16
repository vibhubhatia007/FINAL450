#include<bits/stdc++.h>
using namespace std;


int findPages(int arr[], int n, int m);

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        cout << findPages(A, n, m) << endl;
    }
    return 0;
}


int check(int a[], int n, int k,int m){
    long long int s=1;long long int c=0;
   
   for(int i=0;i<n;i++)
   {
       c=c+a[i];
       if(c>k)
       {
           c=a[i];
           s++;
       }
       if(s>m)
       return 0;
   }
   
   return 1;
    
}

int findPages(int *a, int n, int m) {
    if(n<m)
    return -1;
    
   long long int s=0,e=0;
   for(int i=0;i<n;i++)
   {
       e=e+a[i];
       if(a[i]>s)
       s=a[i];
   }
   
   long long int mid;long long int ans=-1;
   while(s<=e)
   {
       mid=s+((e-s)/2);
       if(check(a,n,mid,m))
       {
           e=mid-1;
           ans=mid;
       }
       else
       s=mid+1;
   }
   
   return ans;
}
