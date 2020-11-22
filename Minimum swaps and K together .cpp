#include <iostream>
using namespace std;

int main() {
    
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        int a[n];int c1=0;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        int k;
        cin>>k;
        
         for(int i=0;i<n;i++)
        {
            if(a[i]<=k)
            c1++;
        }
        
        int ans=0;int c=0;
        
        for(int i=0;i<n;i++)
        {
            if(i<=c1-1)
            {
                if(a[i]<=k)
                c++;
            }
            else
            {
                if(a[i]<=k)
                c++;
                if(a[i-c1]<=k)
                c--;
            }
            
            
            if(c>ans)
            ans=c;
            
            
        }
        
       
        cout<<c1-ans<<"\n";
    }
}