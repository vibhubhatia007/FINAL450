#include<iostream>
#include<string.h>

using namespace std;

int PalinArray(int a[], int n);
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		cout<<PalinArray(a,n)<<endl;
	}
}

int check(int n)
{
    int t=n;
    int r=0;
    while(t!=0)
    {
        r=r*10+(t%10);
        t=t/10;
    }
    
    if(n==r)
    return 1;
    else
    return 0;
}

int PalinArray(int a[], int n)
{  
int ans=1;
for(int i=0;i<n;i++)
{
    ans=ans&check(a[i]);
}

return ans;

}