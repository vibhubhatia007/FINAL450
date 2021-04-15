#include<bits/stdc++.h>

using namespace std;
 
int main() {
  
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
	string s;
	cin>>s;
    vector<int> pos; 
    for (int i = 0; i < s.length(); ++i) 
        if (s[i] == '[') 
            pos.push_back(i); 
  
    int count = 0; 
    int p = 0;  
    long sum = 0; 
  
    for (int i = 0; i < s.length(); ++i) 
    { 
 
        if (s[i] == '[') 
        { 
            ++count; 
            ++p; 
        } 
        else if (s[i] == ']') 
            --count;
        if (count < 0) 
        { 
            sum += pos[p] - i; 
            swap(s[i], s[pos[p]]); 
            ++p; 
            count = 1; 
        } 
    } 
   cout<<sum<<"\n"; 
}
}