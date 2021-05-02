
#include <bits/stdc++.h>
using namespace std;

class Solution
{
    public:    
       vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
        {
            int i=0;int j=0;int k=0;
            vector <int> ans;unordered_map<int,int> m1;
            while(i<n1&&j<n2&&k<n3)
            {
                int m=min(C[k],min(A[i],B[j]));
                if(m==A[i]&&m==B[j]&&C[k]==m)
                {
                    m1[m]++;
                    if(m1[m]==1)
                    ans.push_back(m);
                }
               
                if(m==A[i])
                i++;
                if(m==B[j])
                j++;
                if(m==C[k])
                k++;
            }
            
            return ans;
            
        }

};


int main ()
{
    int t; cin >> t;
    while (t--)
    {
        int n1, n2, n3; 
        cin >> n1 >> n2 >> n3;
        int A[n1];
        int B[n2];
        int C[n3];
        
        for (int i = 0; i < n1; i++) cin >> A[i];
        for (int i = 0; i < n2; i++) cin >> B[i];
        for (int i = 0; i < n3; i++) cin >> C[i];
        
        Solution ob;
        
        vector <int> res = ob.commonElements (A, B, C, n1, n2, n3);
        if (res.size () == 0) 
            cout << -1;
        for (int i = 0; i < res.size (); i++) 
            cout << res[i] << " "; 
        cout << endl;
    }
}  