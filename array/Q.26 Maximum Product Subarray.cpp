
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	long long maxProduct(int *a, int n) {
	    int max1=1,min1=1,maxsofar=1;
	    int flag=0;
	    
	    for(int i=0;i<n;i++)
	    {
	        if(a[i]>0)
	        {
	            max1=max1*a[i];
	            min1=std::min(min1*a[i],1);
	            flag=1;
	        }
	        else if(a[i]==0)
	        {
	            max1=1;
	            min1=1;
	        }
	        else
	        {
	            int t=max1;
	            max1=std::max(min1*a[i],1);
	            min1=t*a[i];
	        }
	        
	        if(max1>maxsofar)
	        
	        maxsofar=max1;
	        
	         if(a[i]==-1&&a[i+1]==-1)
	         flag=1;
	         
	    }
	    
	    if(flag==0 && maxsofar==1)
	    return 0;
	    
	    return maxsofar;
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  