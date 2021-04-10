#include <bits/stdc++.h>
using namespace std;



class Solution{   
public:
    string solve(int arr[], int n) {
        // code here
        sort(arr,arr+n);
        // reverse(arr,arr+n);
        vector<int> n1;vector<int> n2;
        for(int i=n-1;i>=0;i--)
        {
            if(i%2==0)
            n1.push_back(arr[i]);
            else
            n2.push_back(arr[i]);
        }
        
        string ans="";int c=0;int i=0;string t;
        while(i<n1.size()&&i<n2.size())
        {
            int s=(n1[i]+n2[i]+c)%10;
            t=to_string(s);
            ans=ans+t;
            c=(n1[i]+n2[i]+c)/10;
            i++;
        }
        while(i<n1.size())
        {
            int s=(n1[i]+c)%10;
            t=to_string(s);
            ans=ans+t;
            c=(n1[i]+c)/10;
            i++;
        }
        while(c>0)
        {
            int s=(c)%10;
            string t=to_string(s);
            ans=ans+t;
            c=(c)/10;
        }
        
        reverse(ans.begin(),ans.end());
        i=0;
        while(ans[i]=='0')
        {i++;}
        
        ans=ans.substr(i);
        return ans;
    }
};

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int arr[n];
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.solve(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  