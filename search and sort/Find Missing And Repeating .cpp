
#include <bits/stdc++.h>
using namespace std;



class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        int ans1,ans2;int x;
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0)
            x=arr[i];
            else
            x=arr[i]*-1;
            if(arr[x-1]<0)
            {ans1=x; }
            
            arr[x-1]=arr[x-1]*(-1);
        }
        
        for(int i=0;i<n;i++)
        {
            if(arr[i]>0&&i+1!=ans1)
            ans2=i+1;
        }
        
        arr[0]=ans1;
        arr[1]=ans2;
        
        
        return arr ;

    }
};


int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}  