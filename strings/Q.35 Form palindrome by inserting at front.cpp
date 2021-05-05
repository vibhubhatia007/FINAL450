
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    vector<int> lpsolve(string s)
    {
        int m = s.size();
        int len=0;
        vector<int> lps(m);
        lps[0]=0;
        int i=1;
        while(i<m)
        {
            if(s[i]==s[len])
            {
                len++;
                lps[i]=len;
                i++;
            }
            else
            {
                if(len!=0)
                len=lps[len-1];
                else
                {
                    lps[i]=0;
                    i++;
                }
            }
        }
        
        return lps;
    }
    
    int countMin(string str){

     string revStr = str;
    reverse(revStr.begin(), revStr.end());

    string concat = str + "$" + revStr;

    vector<int> lps = lpsolve(concat);

    return (str.length() - lps.back());
    
    }
};


int main(){
    int t;
    cin >> t;
    while(t--){
        string str;
        cin >> str;
        Solution ob;
        cout << ob.countMin(str) << endl;
    }
return 0;
}

