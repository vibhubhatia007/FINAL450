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
    int min=INT_MAX;
    int max=INT_MIN;
    for (int i = 0; i < n; ++i)
    {
    	if(a[i]>max)
    		max=a[i];
    	if(a[i]<min)
    		min=a[i];
    }
    cout<<max<<" "<<min<<"\n";
} 

