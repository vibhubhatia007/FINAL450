
#include<bits/stdc++.h>
using namespace std;

int arr[] = {100, 1000, 100, 1000, 1};
int sum[10000];


int maxSumWO3Consec(int n)
{
	if(sum[n]!=-1)
	return sum[n];
	
	if(n==0)
	return sum[n] = 0;
	
	if(n==1)
	return sum[n] = arr[0];
	
	if(n==2)
	return sum[n] = arr[1]+arr[0];
	
	return sum[n] = max(max(maxSumWO3Consec(n-1),
					maxSumWO3Consec(n-2) + arr[n]),
					arr[n] + arr[n-1] + maxSumWO3Consec(n-3));
	
	
}


int main()
{
	
	int n = sizeof(arr) / sizeof(arr[0]);
	memset(sum,-1,sizeof(sum));
	cout << maxSumWO3Consec(n);

	return 0;
}
