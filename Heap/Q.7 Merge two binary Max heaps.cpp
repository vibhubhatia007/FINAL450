#include <bits/stdc++.h>
using namespace std;

void mergeHeaps(int merged[], int a[], int b[], int n, int m);

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, i;
        cin >> n >> m;
        int a[n], b[m];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        for (i = 0; i < m; i++) {
            cin >> b[i];
        }
        int merged[m + n];
        mergeHeaps(merged, a, b, n, m);

        for (int i = 0; i < n + m; i++) cout << merged[i] << " ";
        cout << endl;
    }
    return 0;
}


void heapify(int *a,int n,int i)
{
    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    
    if(l<n&&a[l]>a[largest])
    largest=l;
    if(r<n&&a[r]>a[largest])
    largest=r;
    
    if(i!=largest)
    {
        swap(a[largest],a[i]);
        heapify(a,n,largest);
    }
}

void mergeHeaps(int m[], int a[], int b[], int n, int m1) {
    
    for(int i=0;i<n;i++)
    {
        m[i]=a[i];
    }
    for(int i=0;i<m1;i++)
    {
        m[n+i]=b[i];
    }
    
    for(int i= (m1+n)/2 -1 ; i >=0 ; i--)
    {
        heapify(m,m1+n,i);
    }
    
}