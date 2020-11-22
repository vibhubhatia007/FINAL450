
#include <bits/stdc++.h>
using namespace std;

int findLongestConseqSubseq(int arr[], int n);
 

int main()
{
 int  t,n,i,a[100001];
 cin>>t;
 while(t--)
 {
  cin>>n;
  for(i=0;i<n;i++)
  cin>>a[i];
  cout<<findLongestConseqSubseq(a, n)<<endl;
 }
      
    return 0;
}

int findLongestConseqSubseq(int a[], int n)
{
    unordered_map<int,int> m;
    int ans=0;
    for(int i=0;i<n;i++)
    {
        m[a[i]]++;
    }
    for(int i=0;i<n;i++)
    {
        if(m[a[i]-1]==0)
        {
            int j=a[i]+1;
            while(m[j]>0)
            {
                j++;
            }
            if(j-a[i]>ans)
            ans=j-a[i];
        }
    }
    
    return ans;
  
}