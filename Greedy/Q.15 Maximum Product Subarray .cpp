
#include <bits/stdc++.h>

using namespace std;

class Solution{
public:

	long long maxProduct(int  *x, int size) {
	    
	    long long A[size];
	    
	    for(int i=0;i<size;i++)
	    {
	        A[i]=x[i];
	    }
	     if (size == 0) {
        return 0;
    }
    
    long long  maxherepre = A[0];
    long long  minherepre = A[0];
    long long maxsofar = A[0];
    long long  maxhere, minhere;
    
    for (int i = 1; i < size; i++) {
        maxhere = max(max(maxherepre * A[i], minherepre * A[i]), A[i]);
        minhere = min(min(maxherepre * A[i], minherepre * A[i]), A[i]);
        if(maxhere>maxsofar)
        maxsofar = maxhere;
        maxherepre = maxhere;
        minherepre = minhere;
    }
    
   
    
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