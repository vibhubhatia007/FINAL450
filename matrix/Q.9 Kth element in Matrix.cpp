#include<bits/stdc++.h>
using namespace std;
#define MAX 1000
int mat[MAX][MAX];
int kthSmallest(int mat[MAX][MAX], int n, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
    
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                cin>>mat[i][j];
        int r;
        cin>>r;
        cout<<kthSmallest(mat,n,r)<<endl;
    }
      return 0;
}


int find(int mat[MAX][MAX],int mid,int N)
{
    int c=0;
    int i=0;int j=N-1;
    while(i<N&&j>=0)
    {
        while(mat[i][j]>mid)
        {
            j--;
        }
        
        c=c+j+1;
        i++;
    }
    
    return c;
}


int kthSmallest(int mat[MAX][MAX], int n, int k)
{
  int ans=0;
  int l=mat[0][0];
  int h=mat[n-1][n-1];
  while(l<=h)
  {
      int mid=(l+h)/2;
      int count = find(mat,mid,n);
      if(count>=k)
      {
          ans=mid;
          h=mid-1;
      }
      else
      {
          l=mid+1;
      }
  }
  
  return ans;
}
