#include<bits/stdc++.h>
using namespace std;


int countSetBits(int n)
{
    int x= log2(n)+1;
    int ans=0;
    for(int i=1;i<=x;i++)
    {
        int v =pow(2,i);
        int s= (n/v)*(v/2);
        if( (n%v) >  ((v/2) - 1) )
        {s = s + (n%v);
        s = s - ((v/2) - 1);}
        ans=ans+s;
        
        
    }
    
    return ans;
    
}


int main()
{
	 int t;
	 cin>>t;
	 while(t--)
	 {
	       int n;
	       cin>>n; 
	       
	       cout << countSetBits(n) << endl;
	  }
	  return 0;
}