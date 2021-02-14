#include<bits/stdc++.h>
#include <boost/multiprecision/cpp_int.hpp>
using boost::multiprecision::cpp_int;  
// https://www.geeksforgeeks.org/factorial-large-number-using-boost-multiprecision-library/
using namespace std;

cpp_int findCatalan(int);

int main() 
{
    //taking count of testcases
	int t;
	cin>>t;
	while(t--) {
	    
	    //taking nth number
	    int n;
	    cin>>n;
	    
	    //calling function findCatalan function
	    cout<< findCatalan(n) <<"\n";    
	}
	return 0;
}// } Driver Code Ends



cpp_int binomialCoeff(unsigned int n,
                                unsigned int k)
{
     cpp_int res = 1;
 

    if (k > n - k)
        k = n - k;
 
    for (int i = 0; i < k; ++i) {
        res *= (n - i);
        res /= (i + 1);
    }
 
    return res;
}


cpp_int findCatalan(int n) {
    //code here
    
     cpp_int c = binomialCoeff(2 * n, n);
 
    return c / (n + 1);
}