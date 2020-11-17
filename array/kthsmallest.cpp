#include<bits/stdc++.h>
using namespace std;

int kthSmallest(int *, int, int, int);
 
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int test_case;
    cin>>test_case;
    while(test_case--)
    {
        int number_of_elements;
        cin>>number_of_elements;
        int a[number_of_elements];
        
        for(int i=0;i<number_of_elements;i++)
            cin>>a[i];
            
        int k;
        cin>>k;
        cout<<kthSmallest(a, 0, number_of_elements-1, k)<<endl;
    }
    return 0;
}

int kthSmallest(int arr[], int l, int r, int k) {
    
    priority_queue <int> q;
    for (int i=0;i<k;i++)
    {
        q.push(arr[i]);
    }
     for (int i=k;i<=r;i++)
    {
        if(arr[i]<q.top())
        {
             q.pop();
            q.push(arr[i]);
        }
       
    }
    
    return q.top();
}