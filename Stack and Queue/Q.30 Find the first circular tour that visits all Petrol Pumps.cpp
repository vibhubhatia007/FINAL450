#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


class Solution{
  public:
  
    int tour(petrolPump p[],int n)
    {
       //Your code here
       
       int start = 0;
       int end = 1;
       int c = p[start].petrol - p[start].distance;
       
       while(end!=start||c<0)
       {
           while(c<0&&end!=start)
           {
               c = c - ( p[start].petrol - p[start].distance);
               start= (start+1)%n;
               
               if(start==0)
               return -1;
           }
           
           c = c + ( p[end].petrol - p[end].distance);
           end=(end+1)%n;
       }
       
       return start;
    }
};




int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
