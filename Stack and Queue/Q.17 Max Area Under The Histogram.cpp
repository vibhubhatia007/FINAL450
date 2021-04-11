#include <bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    long long getMaxArea(long long a[], int n){

    stack<int> s;long long area=0;
    int i =0;long long  marea=0;
    while(i<n)
    {
        if(s.size()==0||a[i]>=a[s.top()])
        s.push(i++);
        else
        {
            int l =s.top();
            s.pop();
            if(s.size()==0)
            area = a[l] * i;
            else
            area = a[l] * (i-s.top()-1);
            
            if(area>marea)
            marea=area;
        }
    }
    while(s.size()>0)
    {
          int l =s.top();
            s.pop();
            if(s.size()==0)
            area = a[l] * i;
            else
            area = a[l] * (i-s.top()-1);
            
            if(area>marea)
            marea=area;
    }
    
    return marea;
    
   
    
    
}
};




int main()
 {
    long long t;

    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        
        long long arr[n];
        for(int i=0;i<n;i++)
            cin>>arr[i];
        Solution ob;
        cout<<ob.getMaxArea(arr, n)<<endl;
    
    }
	return 0;
}
 