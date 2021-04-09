#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    double  a1=((double)p1.first)/((double)p1.second);
    double  a2=((double)p2.first)/((double)p2.second);
    
    return a1<a2;
}


double fractionalKnapsack(int W, Item arr[], int n)
{
   vector<pair<int,int> > v;
   for(int i=0;i<n;i++)
   {
       v.push_back(make_pair(arr[i].value,arr[i].weight));
   }
   sort(v.begin(),v.end(),cmp);
   double w=(double) W;
   double ans=0;
   for(int i=n-1;i>=0;i--)
   {
       if(w>=v[i].second)
       {
           ans=ans+v[i].first;
           w=w-v[i].second;
       }
       else
       {
           if(w>0)
           {
               ans=ans+(w/v[i].second)*v[i].first;
               w=0;
           }
       }
   }
   
   return ans;
   
   
}

// { Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		cout<<fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}  