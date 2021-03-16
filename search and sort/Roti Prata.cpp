#include <iostream>
#include <limits.h>

using namespace std;

bool solve(int a[],int mid,int n,int p)
{
    int c=0,sum=0;int j;
    for(int i=0;i<n;i++)
    {
        j=1;int t=0;
        while(1)
        {
            t=t+(j*a[i]);
            j++;
            if(t>mid)
            break;
            c++;
        }
        
        if(c>=p)
            break;

    }

    if(c>=p)
        return true;
    else
        return false;

}



int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--)
    {
        int p;
        cin>>p;
        int n;
        cin>>n;
        int a[n];int m=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
            m=min(m,a[i]);
        }
        int time=0;
        int j=0;int x=p+1;
        while(x--)
        {
            time=time+j*m;
            j++;
        }
        int ans;

        int low=1;
        int high=time;

        while(low<=high)
        {
            int mid=(low+high)/2;

            if(solve(a,mid,n,p))
            {
                ans=mid;
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        cout<<ans<<"\n";
    }
    
} 
