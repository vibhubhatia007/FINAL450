#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int minimumDays(int S, int N, int M){
      if(N<M)
      return -1;
      else
      {
          if(S<=6||(6*N)>=(7*M))
          {
              if((S*M)%N==0)
              return (S*M)/N;
              else
              return ((S*M)/N)+1;
          }
          else
          {
              return -1;
          }
      }
    }
};

int main(){
    int t;
    cin>>t;
    while(t--){
        int S, N, M;
        cin>> S >> N >> M;
        
        Solution ob;
        cout<<ob.minimumDays(S, N, M)<<endl;
    }
    return 0;
}  