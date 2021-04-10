#include<bits/stdc++.h>
using namespace std;

int countBitsFlip(int a, int b){
    
    return __builtin_popcount(a^b);
    
}

int main()
{
	int t;
	cin>>t;
	while(t--) 
	{
		int a,b;
		cin>>a>>b; 

		cout<<countBitsFlip(a, b)<<endl;
	}
	return 0;
}  