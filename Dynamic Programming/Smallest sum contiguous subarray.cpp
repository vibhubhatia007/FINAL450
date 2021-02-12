#include <bits/stdc++.h>
using namespace std;

int sb(int arr[], int n, int x);

int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int n,x;
		cin>>n>>x;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		
		cout<<sb(a,n,x)<<endl;
	}
	return 0;
}



int sb(int a[], int n, int xk)
{
    // Your code goes here   
    vector<int> v;
    v.push_back(0);
    int x=0;
    for(int i=0;i<n;i++)
    {
        x=x+a[i];
        v.push_back(x);
    }
    int i=0;int j=0;
    int ans=INT_MAX;

    while(i<=n&&j<=n)
    {
        if(v[i]-v[j]<=xk)
        i++;
        else
        {
            if(i-j<ans)
            {ans=i-j;}
            j++;
        }
    }
    
    return ans;
}