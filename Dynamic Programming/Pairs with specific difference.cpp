#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--)
    {
        int n;int k;
        cin>>n;
        int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        cin>>k;
        sort(a,a+n);
        int ans=0;
        int i=n-1;
        while(i>0)
        {
            if(a[i]-a[i-1]<k)
            {
                ans=ans+(a[i]+a[i-1]);
                i=i-2;
            }
            else
            {
                i--;
            }
        }
        
        cout<<ans<<"\n";
    }
}