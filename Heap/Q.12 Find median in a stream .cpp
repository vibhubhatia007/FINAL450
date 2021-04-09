#include<bits/stdc++.h>

using namespace std;


int main() 
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);    
      
 priority_queue <long long int> q1;
 priority_queue <long long int, vector<long long int>, greater<long long int> > q2;
 long long int n;
cin>>n;
while(n--)
{
    int c=0;
    long long int x;
    cin>>x;
   if(q1.size()==0)
   q1.emplace(x);
   else if(q1.top()>=x)
   q1.push(x);
   else if((q2.size()!=0)&&q2.top()<x)
   q2.push(x);
   else
  {
      if(q1.size()<q2.size())
      q2.push(x);
      else
      q1.push(x);
  }
   
   if((q1.size()>q2.size())>0)
   while((q1.size()-q2.size())>1&&q1.size()>1)
   {
       q2.emplace(q1.top());
       q1.pop();
   }
   else
   {
       while((q2.size()-q1.size())>1&&q2.size()>1)
       {
           q1.emplace(q2.top());
           q2.pop();
       }
   }
   if(q1.size()==q2.size())
    cout<<(q1.top()+q2.top())/2<<"\n";
    else
     if((q1.size()>q2.size())>0)
    cout<<q1.top()<<"\n";
    else
     cout<<q2.top()<<"\n";
}
}