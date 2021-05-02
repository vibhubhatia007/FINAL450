#include <iostream>
using namespace std;

void reverse(int a[],int l,int r)
{
    if(l>=r)
    return ;
    else
    {
        a[r]=a[l]+a[r];
        a[l]=a[r]-a[l];
        a[r]=a[r]-a[l];
        
        return reverse(a,l+1,r-1);
    }
}

void rotate(int a[],int n,int k)
{
    reverse(a,0,n-1);
    reverse(a,0,k-1);
    reverse(a,k,n-1);
}

int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    rotate(a,n,1);
	    for(int i=0;i<n;i++)
	    {
	        cout<<a[i]<<" ";
	    }
	    
	    cout<<"\n";
	}
}