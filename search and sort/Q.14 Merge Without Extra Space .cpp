#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
	void merge(int a1[], int a2[], int n, int m) {
	    int gap = (m+n)/2;
	    int i=0;int j=gap;
	    while(gap>=1)
	    {
	        
	        while(j<m+n)
	        {
	            if(i<n&&j<n)
	            {
	                if(a1[i]>a1[j])
	                {
	                    swap(a1[i],a1[j]);
	                }
	            }
	            else if(i<n&&j<m+n)
	            {
	                if(a1[i]>a2[j-n])
	                {
	                    swap(a1[i],a2[j-n]);
	                }
	                
	            }
	            else if(i<m+n&&j<m+n)
	            {
	                if(a2[i-n]>a2[j-n])
	                {
	                    swap(a2[i-n],a2[j-n]);
	                }
	            }
	            
	            i++;
	            j++;
	        }
	        
	        if(gap==1)
	        break;
	       
	        if(gap&1)
	        gap=gap/2+1;
	        else
	        gap=gap/2;
	        i=0;
	        j=gap;
	        
	    }
	    
	  
	    
	    
	}
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int arr1[n], arr2[m];
        for (i = 0; i < n; i++) {
            cin >> arr1[i];
        }
        for (i = 0; i < m; i++) {
            cin >> arr2[i];
        }
        Solution ob;
        ob.merge(arr1, arr2, n, m);
        for (i = 0; i < n; i++) {
            cout << arr1[i] << " ";
        }
        for (i = 0; i < m; i++) {
            cout << arr2[i] << " ";
        }
        cout << "\n";
    }
    return 0;
}  