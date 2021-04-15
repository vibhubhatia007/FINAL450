
#include <bits/stdc++.h>
using namespace std;


class Solution{
    public:
    
    
    int internalSearch(string needle, int row,
                   int col, vector<vector<char> > &hay,
                   int row_max, int col_max, int xx)
{
    int found = 0;
 
    if (row >= 0 && row <= row_max && col >= 0 &&
        col <= col_max && needle[xx] == hay[row][col])
    {
        char match = needle[xx];
        xx += 1;
 
        hay[row][col] = 0;
 
        if (needle[xx] == 0)
        {
            found = 1;
        }
        else
        {
 
         
            found += internalSearch(needle, row,
                                    col + 1, hay,
                                    row_max, col_max,xx);
            found += internalSearch(needle, row, col - 1,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row + 1, col,
                                    hay, row_max, col_max,xx);
            found += internalSearch(needle, row - 1, col,
                                    hay, row_max, col_max,xx);
        }
        hay[row][col] = match;
    }
    return found;
}
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        
     int found = 0;
     
    int r, c;
    
    int row_count = mat.size();
    int col_count = mat[0].size();
 
    for (r = 0; r < mat.size(); ++r)
    {
        for (c = 0; c < mat[0].size(); ++c)
        {
            found += internalSearch(target, r, c, mat,
                                     row_count - 1,
                                    col_count - 1, 0);
        }
    }
    return found;
        
    }
};



int main() {
    int t;
    cin >> t;
    while (t--) {
        int R, C;
        cin >> R >> C;
        vector<vector<char> > mat(R);
        for (int i = 0; i < R; i++) {
            mat[i].resize(C);
            for (int j = 0; j < C; j++) cin >> mat[i][j];
        }
        string target;
        cin >> target;
        Solution obj;
        cout<<obj.findOccurrence(mat,target)<<endl;
    }
}


////////method - 2///////////////




class Solution{
    public:
    
    
    int valid(int r,int c,vector<vector<char> > &mat)
    {
        if(r>=0&&c>=0&&r<mat.size()&&c<mat[r].size())
        return 1;
        else
        return 0;
    }
    
    int findOccurrence(vector<vector<char> > &mat, string target){
        
        queue<pair<int,pair<int,int>>> q;
        
        int n = target.size();int ans=0;
        
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[i].size();j++)
            {
                if(mat[i][j]==target[0])
                q.push({1,{i,j}});
            }
        }
        
        if(n==1)
        return q.size();
        
        while(q.size()>0)
        {
            int i = q.front().first;
            int r = q.front().second.first;
            int c = q.front().second.second;
            
            
            q.pop();
            
            if(valid(r+1,c,mat)&&mat[r+1][c]==target[i])
            {
                if(i==n-1)
                ans++;
                else
                q.push({i+1,{r+1,c}});
            }
            if(valid(r,c+1,mat)&&mat[r][c+1]==target[i])
            {
                if(i==n-1)
                ans++;
                else
                q.push({i+1,{r,c+1}});
            }

             if(valid(r-1,c,mat)&&mat[r-1][c]==target[i])
            {
                if(i==n-1)
                ans++;
                else
                q.push({i+1,{r-1,c}});
            }
             if(valid(r,c-1,mat)&&mat[r][c-1]==target[i])
            {
                if(i==n-1)
                ans++;
                else
                q.push({i+1,{r,c-1}});
            }
           
        }
        
        
        return ans;
    }
};