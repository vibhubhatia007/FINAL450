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

int findLongestConseqSubseq(int arr[], int N)
{

 unordered_map<int,int> m;int n=N;
    for(int i=0;i<n;i++)
    {
        m[arr[i]]++;
    }
    int c=1;int max=0;
   sort(arr,arr+n);
   for(int i=0;i<n;i++)
   {
       if(arr[i+1]-arr[i]==1)
       c++;
       else if(arr[i+1]==arr[i])
       {}
       else
       c=1;
       if(c>max)
       max=c;
   }
   return max;
  }
  