#include<bits/stdc++.h>
using namespace std;

vector<long long int> productExceptSelf(vector<long long int>&, int );


int main()
 {
    int t;  // number of test cases
    cin>>t;
    while(t--)
    {
        int n;  // size of the array
        cin>>n;
        vector<long long int> arr(n),vec(n);
        
        for(int i=0;i<n;i++)    // input the array
        {
            cin>>arr[i];
        }
        
        vec = productExceptSelf(arr,n);   // function call
        
        for(int i=0;i<n;i++)    // print the output
        {
            cout << vec[i] << " ";
        }
        cout<<endl;
    }
	return 0;
}

vector<long long int> productExceptSelf(vector<long long int>& a, int n) {
   
    //code here        
    vector<long long int> v(1);v[0]=1;
     if(n==1)
     return v;
    
    long long int p[n],s[n];
    p[0]=a[0];
      for(int i=1;i<n;i++)
    {
        p[i]=p[i-1]*a[i];
    }
    s[n-1]=a[n-1];
    for(int i=n-2;i>=0;i--)
    {
        s[i]=s[i+1]*a[i];
    }
    a[0]=s[1];
    a[n-1]=p[n-2];
    
    for(int i=1;i<n-1;i++)
    {
        a[i]=p[i-1]*s[i+1];
    }
    
    
    return a;
}
