#include<bits/stdc++.h>
using namespace std;


int find3Numbers(int A[], int arr_size, int sum) 
{ 
	
	for (int i = 0; i < arr_size - 2; i++) {
		unordered_set<int> s; 
		int curr_sum = sum - A[i]; 
		for (int j = i + 1; j < arr_size; j++) { 
			if (s.find(curr_sum - A[j]) != s.end()) { 
				return 1; 
			} 
			s.insert(A[j]); 
		} 
	} 

	 
	return 0; 
} 



int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int k;
	    int n;
	    cin>>n>>k;
	    int a[n];
	    for(int i=0;i<n;i++)
	    {
	        cin>>a[i];
	    }
	    int c1=0,c2=0;
	    int  i,j;
cout<<find3Numbers(a,n,k)<<"\n";
	}
}