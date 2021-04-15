#include <bits/stdc++.h>
using namespace std;

int romanToDecimal(string &);

int main() {
    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        cout << romanToDecimal(s) << endl;
    }
}
int val(char c)
{
    if(c=='I')
    return 1;
     if(c=='V')
    return 5;
     if(c=='X')
    return 10;
     if(c=='L')
    return 50;
     if(c=='C')
    return 100;
     if(c=='D')
    return 500;
     if(c=='M')
    return 1000;
    
}

int romanToDecimal(string &s) {
    int ans=val(s[s.length()-1]);
   for(int i=s.length()-2;i>=0;i--)
   {
       if(val(s[i])>=val(s[i+1]))
       {
           ans=ans+val(s[i]);
       }
       else
       {
           ans=ans-val(s[i]);
       }
   }
   
   return ans;
}