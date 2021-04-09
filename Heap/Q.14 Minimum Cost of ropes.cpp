#include <bits/stdc++.h>
using namespace std;

long long minCost(long long arr[], long long n);
int main() {
    long long t;
    cin >> t;
    while (t--) {
        long long n;
        cin >> n;
        long long i, a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        cout << minCost(a, n) << endl;
    }
    return 0;
}



long long int  minCost(long long arr[], long long n) {
     priority_queue<long long, vector<long long >, greater<long long > > p;
     for(int i=0;i<n;i++)
     {
         p.push(arr[i]);
     }
     long long  sum=0;
     while(p.size()>1)
     {
         long long a=p.top();
         p.pop();
         long long b=p.top();
         p.pop();
         long long s=a+b;
         p.push(s);
          sum=sum+(a+b);
     }
     
     
     return sum;
}
