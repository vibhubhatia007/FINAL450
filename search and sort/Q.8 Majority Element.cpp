#include<bits/stdc++.h>
using namespace std;


int majorityElement(int a[], int n)
{
    
  int m=0;int c=1;
  for(int i=1;i<n;i++)
  {
      if(a[m]==a[i])
      c++;
      else
      c--;
      
      if(c==0)
      {
          m=i;
          c=1;
      }
  }
  c=0;
  for(int i=0;i<n;i++)
  {
      if(a[m]==a[i])
      c++;
  }
  
  if(c>n/2)
  return a[m];
  else
  return -1;
  
}
    

int main(){

    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;
        int arr[n];
        
        for(int i = 0;i<n;i++){
            cin >> arr[i];
        }
        
        cout << majorityElement(arr, n) << endl;
    }

    return 0;
}
  