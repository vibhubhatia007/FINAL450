
#include <bits/stdc++.h>
using namespace std;


class Solution{
public:
    int pageFaults(int N, int C, int pages[]){
        // code here
        unordered_map<int,int> m;
        set<int> s;
        
        int page_faults = 0;
        for(int i=0;i<N;i++)
        {
            if(s.size()<C)
            {
                if(s.find(pages[i])==s.end())
                {
                    s.insert(pages[i]);
                    page_faults++;
                }
                m[pages[i]]=i;
            }
        
        else
        {
            if(s.find(pages[i])==s.end())
            {
                int min = INT_MAX;int page;
                for(auto it = s.begin();it!=s.end();it++)
                {
                    if(m[*it]<min)
                    {
                        min = m[*it];
                        page = *it;
                    }
                }
                s.erase(page);
                s.insert(pages[i]);
                page_faults++;
            }
            m[pages[i]]=i;
        }
        }
        return page_faults;
        
    }
};


int main(){
    int t;
    cin>>t;
    while(t--){
        int N, C;
        cin>>N;
        int pages[N];
        for(int i = 0;i < N;i++)
            cin>>pages[i];
        cin>>C;
        
        Solution ob;
        cout<<ob.pageFaults(N, C, pages)<<"\n";
    }
    return 0;
}