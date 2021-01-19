
#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int countSquares(int N) {
        int ans=(int)sqrt(N);
        double ans1=sqrt(N);
        
        if(ans==ans1)
        ans--;
        
        
        return ans;
        
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        
        cin>>N;

        Solution ob;
        cout << ob.countSquares(N) << endl;
    }
    return 0;
} 