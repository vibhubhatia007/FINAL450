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
    Node* SortedMerge(Node* a, Node* b)
{
    Node *head1=a;
    Node *head2=b;
   
    Node* ans=new Node(0);
    Node *t=ans; 
    
    while(head1!=NULL&&head2!=NULL)
    {
        if(head1->data==head2->data)
        {
            ans->next=new Node(head1->data);
            ans=ans->next;
            head1=head1->next;
            head2=head2->next;
        }
        else if(head1->data<head2->data)
        {
             head1=head1->next;
        }
        else
        {
             head2=head2->next;
        }
    }
   
    t=t->next;
    
    return t;
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