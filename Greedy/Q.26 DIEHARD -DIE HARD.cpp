#include <iostream>
#include<bits/stdc++.h>
using namespace std;


int main() 
{ 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int tc;
    cin>>tc;
    while(tc--)
    {
        int h,a;
        int t;
        cin>>h>>a;
        int ans=0;
         if(h==0||a==0)
        cout<<"0\n";
        else{
            t=1;
            h=h+3;
            a=a+2;
            while(1){
                if(h>5&&a>10){
                    h=h-2;
                    a=a-8;
                    t=t+2;
                }else if(h>20&&a<=10){
                    h=h-17;
                    a=a+7;
                    t=t+2;
                }else {
                    cout<<t<<"\n";
                    break;
                }
            }
     }
    }
}

