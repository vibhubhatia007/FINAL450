#include <bits/stdc++.h>
using namespace std;


class Solution {
  public:
    int findPosition(int n) {
        // code here
        
        if(n==0)
        return -1;
        int N = 1;
        
        while(n>1)
        {
            if(n&1)
            return -1;
            
            n = n>>1;
            N++;
        }
    
        
        return N;
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