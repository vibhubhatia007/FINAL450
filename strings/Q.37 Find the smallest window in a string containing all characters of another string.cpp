#include<bits/stdc++.h>
using namespace std;



string smallestWindow (string s, string t){
    
          if(t.length()>s.length()){
            return "-1";
        }
        int hashPat[256]={0};
        int hashStr[256]={0};
        for(auto x:t){
            hashPat[x]++;
        }
        int startIdx=-1;
        int minLen=INT_MAX;
        int j=0;
        int i=0;
        int count=0;
        while(j<s.length()){
            hashStr[s[j]]++;
            if(hashStr[s[j]]<=hashPat[s[j]]){
                count++;
            }
            if(count==t.length()){
                while(hashStr[s[i]]>hashPat[s[i]] || hashPat[s[i]]==0){
                    if(hashStr[s[i]]>hashPat[s[i]]){
                        hashStr[s[i]]--;
                    }
                    i++;
                }
                if(minLen>(j-i+1)){
                    minLen=(j-i+1);
                    startIdx=i;
                }
            }
            j++;
        }
        if(minLen==INT_MAX){
            return "-1";
        }
        return s.substr(startIdx,minLen);
}


int main()
 {
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        cin>>s;
        string pat;
        cin>>pat;
        
        cout<<smallestWindow(s, pat)<<endl;
        
    }
	return 0;
} 