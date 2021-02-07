#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findPosition(int n) {
      double x1=log2(n);
      int x2=log2(n);
      if(x1==x2&&n!=0)
      {
          return 1+log2(n);
      }
      else
      return -1;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;

        cin>>N;

        Solution ob;
        cout << ob.findPosition(N) << endl;
    }
    return 0;
}  