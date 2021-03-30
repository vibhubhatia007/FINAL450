#include <iostream>
using namespace std;
 
int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    while(1)
    {
        long long int n;
        cin>>n;
        if(n==0)
            break;
        long long int a[n];
        for(int i=0;i<n;i++)
        {
            cin>>a[i];
        }
        long long int m;
        cin>>m;
        long long int b[m];
        for(int i=0;i<m;i++)
        {
            cin>>b[i];
        }
        long long int s=0;
        long long int i=0;long long int j=0;
        long long int s1=0;long long int s2=0;
        while(i<n&&j<m)
        {
            if(a[i]<b[j])
                s1=s1+a[i++];
            else if(a[i]>b[j])
                s2=s2+b[j++];
            else
            {
                s=s+max(s1,s2)+a[i];
                i++;j++;s1=0;s2=0;
            }
        }
        while(i<n)
        {
            s1=s1+a[i++];
        }
        while(j<m)
        {
            s2=s2+b[j++];
        }
 
        s=s+max(s1,s2);
        cout<<s<<"\n";
 
    }
} 
 