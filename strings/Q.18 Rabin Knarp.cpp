#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
        vector <int> search(string pat, string txt)
        {
            int M = pat.length();
            int N = txt.length();
            int h=1;
            int p=0;
            int t=0;
            int q=101;
            int d= 256;
            
            vector<int> ans;
            
            int i,j;
        for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 
  
 
    for (i = 0; i < M; i++) 
    { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 
  

    for (i = 0; i <= N - M; i++) 
    { 

        if ( p == t ) 
        { 
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 
  
            if (j == M) 
               ans.push_back(i+1);
        } 
  
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 
            if (t < 0) 
            t = (t + q); 
        } 
            
    }
    
    if(ans.size()==0)
    ans.push_back(-1);
        
    return ans;
        }

};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string S, pat;
        cin >> S >> pat;
        Solution ob;
        vector <int> res = ob.search(pat, S);
        for (int i : res) cout << i << " ";
        cout << endl;
    }
    return 0;
}
