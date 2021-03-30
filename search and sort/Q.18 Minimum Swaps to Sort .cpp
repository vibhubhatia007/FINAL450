// C++ program to find minimum number of swaps
// required to sort an array
#include<bits/stdc++.h>
using namespace std;

int minSwaps(int A[], int N);

// Driver program to test the above function
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int a[n];
	    for(int i=0;i<n;i++)
	    cin>>a[i];
	    cout<<minSwaps(a,n)<<endl;
	}
}

// } Driver Code Ends


/* You are required to complete this method */

// return the minimum number of swaps required to sort the arra
int minSwaps(int a[], int n){
    /*Your code here */
   pair<int,int> v[n];
   
   for(int i=0;i<n;i++)
   {
       v[i].first=a[i];
       v[i].second=i;
   }
   
   sort(v,v+n);
   bool vis [n]={0};
   int ans=0;
   for(int i=0;i<n;i++)
   {
       if(vis[i]==1||v[i].second==i)
       continue;
       
        
       int j=i;int c=0;
       //summation of cylce size
       while(vis[j]==0)
       {
           vis[j]=1;// mark the node
           j=v[j].second;// get to the next node
           c++;// increase the cycle size
       }
       
       if(c>0)
       ans=ans+c-1;
   }
   
   
   return ans;
   
}
