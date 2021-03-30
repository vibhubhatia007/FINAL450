
#include <bits/stdc++.h>
using namespace std;




class Solution{
public:
    int findMin(int a[], int n){
        
    int l=0;int h=n-1;
      while(l<h)
    {
        int mid=(l+h)/2;
        
        if(a[mid]>=a[h])
        l=mid+1;
        else
        h=mid;
    }

    
    return a[l];
    }
};

// { Driver Code Starts.


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int i,a[n];
		for(i=0;i<n;i++)
		{
			cin>>a[i];
		}
		Solution ob;
		cout<<ob.findMin(a, n)<<endl;
	}
	return 0;
}  