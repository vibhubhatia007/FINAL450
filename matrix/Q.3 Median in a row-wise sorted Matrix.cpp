#include <bits/stdc++.h>
using namespace std;



class Solution{   
public:
    int median(vector<vector<int>> &matrix, int r, int c){      
        
        int m = r;
        int n = c;
        
        int low = INT_MAX;
        int high = INT_MIN;
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]<low)
            low = matrix[i][0];
        }
        
        for(int i=0;i<m;i++)
        {
            if(matrix[i][c-1]>high)
            high = matrix[i][c-1];
        }
        
        int count = (r * c + 1) / 2;
        
        
        while(low<high)
        {
            int mid = low + ((high-low)/2);
            
            int c =0;
            for(int i=0;i<m;i++)
            c=c+(upper_bound(matrix[i].begin(),matrix[i].end(),mid)-matrix[i].begin());
            
            if(c<count)
            low=mid+1;
            else
            high=mid;
        }
        
        return high;
        
    }
};



int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int r, c;
        cin>>r>>c;
        vector<vector<int>> matrix(r, vector<int>(c));
        for(int i = 0; i < r; ++i)
            for(int j = 0;j < c; ++j)
                cin>>matrix[i][j];
        Solution obj;
        cout<<obj.median(matrix, r, c)<<endl;        
    }
    return 0;
}  