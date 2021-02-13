#include<bits/stdc++.h>
using namespace std;

int longestSubsequence(int, int[]);

int main()
{
    //taking total testcases
    int t,n;
    cin>>t;
    while(t--)
    {
        //taking size of array
        cin>>n;
        int a[n];
        
        //inserting elements to the array
        for(int i=0;i<n;i++)
            cin>>a[i];

        //calling method longestSubsequence()
        cout << longestSubsequence(n, a) << endl;
    }
}

int longestSubsequence(int n, int a[])
{
   
   if(n==0)
   return 0;

   vector<int> ans;
   ans.push_back(a[0]);
   
   for(int i=1;i<n;i++)
   {
       if(a[i]>ans[ans.size()-1])
       {
           ans.push_back(a[i]);
       }
       else
       {
           int x=lower_bound(ans.begin(),ans.end(),a[i])-ans.begin();
           ans[x]=a[i];
       }
   }
   
   return ans.size();
   
}