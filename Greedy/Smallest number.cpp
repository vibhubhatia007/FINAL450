#include<bits/stdc++.h> 
using namespace std; 

class Solution{   
public:
    string smallestNumber(int s, int d){
     if(s>9*d)
    return "-1";
    else
    {
      int a[d];
      for(int i=0;i<d;i++)
      {
          a[i]=0;
      }
      a[0]=1;
      s=s-1;
      int i=d-1;
      while(s>0)
      {
          a[i]=a[i]+min(s,9);
          s=s-min(s,9);
          i--;
      }
      string ans="";
      for(int i=0;i<d;i++)
      cout<<a[i];
      
      return ans;
    }
    
    }
};


int main() 
{ 
    int t;
    cin>>t;
    while(t--)
    {
        int S,D;
        cin >> S >> D;
        Solution ob;
        cout << ob.smallestNumber(S,D) << endl;
    }
    return 0; 
}   