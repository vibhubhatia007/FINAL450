#include<bits/stdc++.h> 
using namespace std; 



class Solution
{
public:
    int setBits(int n)
    {
        if(n==0)
        return 0;
        if(n%2==1)
        return 1+setBits(n/2);
        else
        return setBits(n/2);
    }
};

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin >> N;
        
        Solution ob;
        int cnt = ob.setBits(N);
        cout << cnt << endl;
    }
    return 0;
}
