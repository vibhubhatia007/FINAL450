#include<bits/stdc++.h>
using namespace std;


class Solution
{
    public:
    
        void compute(string pat, int M, int* lps)
        {
           
            int len = 0;
          
            lps[0] = 0; 
            int i = 1;
            while (i < M) {
                if (pat[i] == pat[len]) {
                    len++;
                    lps[i] = len;
                    i++;
                }
                else 
                {
                    if (len != 0) {
                        len = lps[len - 1];
                    }
                    else 
                    {
                        lps[i] = 0;
                        i++;
                    }
                }
            }
        }
        vector <int> search(string pat, string txt)
        {
        
            int M = pat.size();
            int N = txt.size();
          
            vector<int> ans;
          
            int lps[M];

            compute(pat, M, lps);
          
            int i = 0; 
            int j = 0; 
            while (i < N) {
                if (pat[j] == txt[i]) {
                    j++;
                    i++;
                }
          
                if (j == M) {
                    ans.push_back(i-M+1);
                    j = lps[j - 1];
                }
          
               
                else if (i < N && pat[j] != txt[i]) {
                    if (j != 0)
                        j = lps[j - 1];
                    else
                        i = i + 1;
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
