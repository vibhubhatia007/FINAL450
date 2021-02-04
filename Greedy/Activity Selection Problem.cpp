#include <bits/stdc++.h>

using namespace std;

int maxMeetings(int *, int *, int);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        int start[n], end[n];
        for (int i = 0; i < n; i++) cin >> start[i];

        for (int i = 0; i < n; i++) cin >> end[i];

        int ans = maxMeetings(start, end, n);
        cout << ans << endl;
    }
    return 0;
}



bool cmp(pair<int,int> p1,pair<int,int> p2)
{
    return p1.second<p2.second ;
}

int maxMeetings(int start[], int end[], int n) {
    vector<pair<int,int> > v;
    for(int i=0;i<n;i++)
    {
        v.push_back(make_pair(start[i],end[i]));
    }
    sort(v.begin(),v.end(),cmp);
    
    int ans=1;int e=v[0].second;
    for(int i=1;i<n;i++)
    {
        if(v[i].first>e)
        {
            ans++;
            e=v[i].second;
        }
    }
    return ans;
}