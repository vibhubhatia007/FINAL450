#include <bits/stdc++.h>
using namespace std;


struct Node
{
	int data;
	Node* next;
	
	Node(int x){
	    data = x;
	    next = NULL;
	}
	
};

void printList(Node* node)
{
	while (node != NULL)
	{
		printf("%d ", node->data);
		node = node->next;
	}
	cout<<endl;
}



class Solution{
  public:
    //Function to merge K sorted linked list.
    Node* SortedMerge(Node* a, Node* b)
{
    Node* result = NULL;
    if (a == NULL)
        return (b);
    else if (b == NULL)
        return (a);

    if (a->data <= b->data) {
        result = a;
        result->next = SortedMerge(a->next, b);
    }
    else {
        result = b;
        result->next = SortedMerge(a, b->next);
    }
 
    return result;
}

Node* mergeKList(Node* arr[], int last)
{
    while (last != 0) {
        int i = 0, j = last;

        while (i < j) {

            arr[i] = SortedMerge(arr[i], arr[j]);
 
            i++, j--;
 
        
            if (i >= j)
                last = j;
        }
    }
 
    return arr[0];
}
 
    Node * mergeKLists(Node *arr[], int k)
    {
           // Your code here
           Node* head = mergeKList(arr, k - 1);
           return head;
           
    }
};


int main()
{
   int t;
   cin>>t;
   while(t--)
   {
	   int N;
	   cin>>N;
       struct Node *arr[N];
       for(int j=0;j<N;j++)
        {
           int n;
           cin>>n;

           int x;
           cin>>x;
           arr[j]=new Node(x);
           Node *curr = arr[j];
           n--;

           for(int i=0;i<n;i++)
           {
               cin>>x;
               Node *temp = new Node(x);
               curr->next =temp;
               curr=temp;
           }
   		}
   		Solution obj;
   		Node *res = obj.mergeKLists(arr,N);
		printList(res);

   }

	return 0;
}