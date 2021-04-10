
#include<bits/stdc++.h>
using namespace std;


class Solution{
    public:
    // n: input to count the number of set bits
    //Function to return sum of count of set bits in the integers from 1 to n.
    int countSetBits(int n)
    {
        // Your logic here
        
        if(n<=0)
        return 0;
        
        int power = 0;
        
        
        while(1<<power <= n)
        {
            power++;
        }
        power -- ;
        
        int nearest = power * (1  << (power-1));
        int remaining = n - (1 << power) + 1;
        int rest = n - (1 << power);
        
        return nearest+remaining+countSetBits(rest);
        
    }
};


int main()
{
	 int t;
	 cin>>t;
	 while(t--) 
	 {
	       int n;
	       cin>>n; 
	       Solution ob;
	       cout << ob.countSetBits(n) << endl;
	  }
	  return 0;
}


/// SOLUTION 2 ///////////////


    bool isPowerofTwo(long long n){
         
        
        if(n==0)
        return false;
        
        while(n>1)
        {
            if(n&1)
            return false;
            
            n = n>>1;
        }
        
        return true;
        
        
    }
