
#include<iostream>
#include<cstring>
using namespace std;
 

int countPS(string str);
 
int main()
{
   int t;
	cin>>t;
   while(t--)
	{
	string str;
cin>>str;
cout<<countPS(str)<<endl;
} 
}

int countPS(string str)
{
 int N = str.length(); 
    int cps[N+1][N+1]; 
    memset(cps, 0 ,sizeof(cps)); 
    for (int i=0; i<N; i++) 
        cps[i][i] = 1;
    for (int L=2; L<=N; L++) 
    { 
        for (int i=0; i<N; i++) 
        { 
            int k = L+i-1; 
            if (str[i] == str[k]) 
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] + 1; 
            else
                cps[i][k] = cps[i][k-1] + 
                            cps[i+1][k] - 
                            cps[i+1][k-1]; 
        } 
    } 
    return cps[0][N-1]; 
}
 
//////////Recursive DP////////


int countPS(int i, int j)
{
 
    if (i > j)
        return 0;
 
    if (dp[i][j] != -1)
        return dp[i][j];
 
    if (i == j)
        return dp[i][j] = 1;
 
    else if (str[i] == str[j])
        return dp[i][j]
               = countPS(i + 1, j) +
                countPS(i, j - 1) + 1;
 
    else
        return dp[i][j] = countPS(i + 1, j) +
                          countPS(i, j - 1) -
                          countPS(i + 1, j - 1);
}
 