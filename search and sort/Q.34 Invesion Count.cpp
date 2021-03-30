#include <bits/stdc++.h>
using namespace std;


long long int merge(long long int a[],long long  l,long long int mid,long long int r){
    long long int inv=0;
    long long int n1=mid-l+1;
    int n2=r-mid;
    int a1[n1];
    int a2[n2];
    for(int i=0;i<n1;i++)
    {
        a1[i]=a[l+i];
    }
    for(int i=0;i<n2;i++)
    {
        a2[i]=a[mid+i+1];
    }
    int i=0;int j=0;int k=l;
    while(i<n1 && j<n2)
    {
        if(a1[i]<=a2[j])
        {
            a[k]=a1[i];
            i++;k++;
        }
        else
        {
            a[k]=a2[j];
            inv=inv+(n1-i);
            k++;j++;
        }
        
    }
          while(i<n1){
            a[k]=a1[i];
            k++;i++;
        }
        
        while(j<n2)
        {
            a[k]=a2[j];
            j++;k++;
        }
        
        
        return inv;
}

long long int mergesort(long long int a[],long long int l,long long int r)
{
    long long int inv=0;
    if(l<r)
    {
        int mid=l+ ((r-l)/2);
        inv=inv+mergesort(a,l,mid);
        inv=inv+mergesort(a,mid+1,r);
        inv=inv+merge(a,l,mid,r);
        
        
    }
    
    return inv;
}

long long int inversionCount(long long int a[], long long n)
{
   long long int ans= mergesort(a,0,n-1);
   return ans;
}


int main() {
    
    long long T;
    cin >> T;
    
    while(T--){
        long long N;
        cin >> N;
        
        long long A[N];
        for(long long i = 0;i<N;i++){
            cin >> A[i];
        }
        
        cout << inversionCount(A,N) << endl;
    }
    
    return 0;
}