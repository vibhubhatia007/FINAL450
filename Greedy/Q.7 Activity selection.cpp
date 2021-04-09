#include<bits/stdc++.h>
using namespace std;



class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    int activitySelection(vector<int> start, vector<int> end, int n)
    {
        // Your code here
        vector<pair<int,int>> v;
        for(int i=0;i<n;i++)
        {
            v.push_back(make_pair(end[i],start[i]));
        }
        
         sort(v.begin(), v.end());
        
        int x = 0;
        int count=1;
        for (int j = 1; j < v.size(); j++) {
            if (v[j].second >
                             v[x].first) {
                x = j;
                count++;
            }
        }
        
        return count;
    }
};

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> start(n), end(n);

        for(int i=0;i<n;i++)
            cin>>start[i];
        for(int i=0;i<n;i++)
            cin>>end[i];
        Solution ob;
        cout << ob.activitySelection(start, end, n) << endl;
    }
    return 0;
}
