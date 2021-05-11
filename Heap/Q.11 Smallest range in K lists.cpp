
#include<iostream>
#include<limits.h>
using namespace std;
#define N 1000

pair<int,int> findSmallestRange(int arr[][N], int n, int k);

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
	    rangee = findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}


#include <queue>


pair<int,int> findSmallestRange(int a[][N], int n, int k)
{

      pair<int,int> ans;
       priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> q;
      
      int minRange = INT_MAX;
      int high = 0;int low;
      for(int i=0;i<k;i++)
      {
          if(a[i][0]>high)
          {
              high= a[i][0];
          }
          q.push({a[i][0],{i,0}});
      }
      low=q.top().first;
      ans.first = low;
      ans.second = high;
      while(q.size()==k)
      {
            auto it=q.top();
            q.pop();
            
            int row=it.second.first;
            int col=it.second.second;
            int val=a[row][col];
            
            if(col+1<n){
                q.push({a[row][col+1],{row,col+1}});
                high=max(high,a[row][col+1]);
                int x=q.top().second.first;
                int y=q.top().second.second;
                low = a[x][y];
                if(high-low<ans.second-ans.first){
                    ans.first=low;
                    ans.second=high;
                }
            }
           
      }
      
      return ans;
      
}