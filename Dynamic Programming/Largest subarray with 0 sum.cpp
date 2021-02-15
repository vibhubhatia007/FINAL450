#include <bits/stdc++.h>
using namespace std;

int maxLen(int A[], int n);

int main() {
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];
        cout << maxLen(A, N) << endl;
    }
}

int maxLen(int a[], int n) {
    unordered_map<int,int> m;
    int s=0;int ans=0;
    m[0]=0;int x;
    for(int i=0;i<n;i++)
    {
        s=s+a[i];
        if(s==0)
        x=i+1;
        else
        {
            if(m[s]==0)
            {
                m[s]=i+1;x=0;
                
            }
            else
            {
                x=i+1-m[s];
            }
        }
        
        if(x>ans)
        ans=x;
    }
    
    return ans;
}