#include<bits/stdc++.h>
using namespace std;

class Solution {
	public:
		string FirstNonRepeating(string A){
		     int mp[26]={0};
             queue<char> q;
             string ans;
             for (auto c : A)
             {
                mp[c-'a']++;
                q.push(c);
                while (!q.empty() && mp[q.front()-'a'] > 1)  
                q.pop();
                if (!q.empty())                         
                ans.push_back(q.front());
                else
                ans.push_back('#');
            }
        return ans;
		}

};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  