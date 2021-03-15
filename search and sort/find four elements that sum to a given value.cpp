#include <bits/stdc++.h>

using namespace std;

vector<vector<int> > fourSum(vector<int> &a, int k);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        vector<vector<int> > ans = fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}

vector<vector<int> > fourSum(vector<int> &a, int t) {
    
     map< vector<int>, int > m ;

    
    
    int n=a.size();
    vector<vector<int>> v;
    vector<int> ans;
    if(n<4)
    return v;
    sort(a.begin(),a.end());
    for(int i=0;i<n-3;i++)
    {
        for(int j=i+1;j<n-2;j++)
        {
            int k=j+1;
            int l=n-1;
            while(k<l)
            {
            if(a[i]+a[j]+a[k]+a[l]==t)
            {
                vector<int> ans;
                ans.push_back(a[i]);
                ans.push_back(a[j]);
                ans.push_back(a[k]);
                ans.push_back(a[l]);
                if(m[ { a[i] , a[j] , a[k] , a[l] } ] == 0 )
               { v.push_back(ans);m[ { a[i] , a[j] , a[k] , a[l] } ] = 1 ;}
                ans.empty();
                k++;l--;
            }
            else if(a[i]+a[j]+a[k]+a[l]>t)
            l--;
            else
            k++;
            }
        }
    }
    
    return v;
}