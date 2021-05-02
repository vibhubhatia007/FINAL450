#include <bits/stdc++.h>
using namespace std;
double MedianOfArrays(vector<int>& array1, vector<int>& array2);


int f(vector<int>&a, vector<int>&b, int req)
{
    int n=a.size(),m=b.size();
    int l=min(a[0],b[0]),r=max(a[n-1],b[m-1]);
    while(l<r)
    {
        int mid=(l+r)/2;
        int less=upper_bound(a.begin(),a.end(),mid)-a.begin();
        less+=upper_bound(b.begin(),b.end(),mid)-b.begin();
    
        if(less<req)
             l=mid+1;
        else r=mid;
    }
    
    return l;
}
double med(vector<int>&a)
{
    int n=a.size();
    if(n%2==1)return a[n/2];
    return (a[n/2]*1.0+a[n/2-1])/2;
}
double MedianOfArrays(vector<int>& a, vector<int>& b)
{

    int n=a.size(),m=b.size();
    if(n==0)return med(b);
    if(m==0)return med(a);
    if((n+m)%2==1)return f(a,b,(m+n+1)/2);
    return (f(a,b,(m+n+1)/2)*1.0+f(a,b,((m+n+1)/2)+1))/2;
}




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m;
        vector<int> array1(m);
        for (int i = 0; i < m; ++i)
            cin>>array1[i];
        cin>>n;
        vector<int> array2(n);
        for (int i = 0; i < n; ++i)
            cin>>array2[i];
        cout<<MedianOfArrays(array1, array2)<<endl;
    }
    return 0; 
}

