#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++)
    {
    	cin>>a[i];
    }
    int i=0;
    int j=n-1;
    int t;
    while(i<j)
    {
    	t=a[i];
    	a[i]=a[j];
    	a[j]=t;
    	i++;
    	j--;
    }
    for(int i=0;i<n;i++)
    {
    	cout<<a[i]<<" ";
    }

} 


