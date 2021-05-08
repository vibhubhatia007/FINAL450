#include <bits/stdc++.h>
using namespace std;


bool cmp(int a,int b)
{
    return a>b;
}

int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    cin>>t;
    while(t--)
    {
        int m,n;
        cin>>m>>n;
        int a1[m-1];
        int a2[n-1];
        for(int i=0;i<m-1;i++)
        {
            cin>>a1[i];
        }
        for(int j=0;j<n-1;j++)
        {
            cin>>a2[j];
        }



        sort(a1,a1+m-1,cmp);
        sort(a2,a2+n-1,cmp);


        long long int res = 0;
        int h=1;int v=1;
        int i=0;int j=0;
        while(i<m-1&&j<n-1)
        {
            if(a1[i]>a2[j])
            {
                res += a1[i]*v;
                i++;
                h++;
            }
            else
            {
                res += a2[j]*h;
                v++;
                j++;
            }

            // cout<<res<<"\n";
        }

       long long int total =0;
        while(i<m-1)
            total = total + a1[i++];
        res = res + total*v;


        total = 0;
        while(j<n-1)
            total = total + a2[j++];
        res = res + total * h;


        cout<<res<<"\n";


    }

} 
