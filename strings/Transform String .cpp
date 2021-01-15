#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
    int transform (string A, string B)
    {
        int c[150]={0};int x;
        int l1=A.length();
        int l2=B.length();
        
        for(int i=0;i<l1;i++)
        {
            x=(int)A[i];
            c[x]=c[x]+1;
        }
        for(int i=0;i<l2;i++)
        {
            x=(int)B[i];
            c[x]=c[x]-1;
        }
        for(int i=0;i<150;i++)
        {
            if(c[i]!=0)
            x=-1;
        }
        if(x==-1)
        return x;
        
        int i=l1;int j=l2;
        int ans=0;
        while(i>=0)
        {
            if(A[i]==B[j])
            {
                i--;
                j--;
            }
            else
            {
                i--;
                ans++;
            }
        }
        
        return ans;
    }
};


int main () 
{
    int t; cin >> t;
    while (t--)
    {
        string A, B; 
        cin >> A >> B;
        Solution ob;
        cout <<ob.transform (A, B) << endl;
    }
}  