#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node
{
    int data;
    struct Node* next;
    
    Node(int x){
        data = x;
        next = NULL;
    }
};

void append(struct Node** head_ref, struct Node **tail_ref, int new_data)
{
    struct Node* new_node = new Node(new_data);
    
    if (*head_ref == NULL)
       *head_ref = new_node;
    else
       (*tail_ref)->next = new_node;
    *tail_ref = new_node;
}

int getMiddle(struct Node *head);

int main()
{
  int T,i,n,l;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n;
        for(i=1;i<=n;i++)
        {
            cin>>l;
            append(&head, &tail, l);
        }

    printf("%d\n", getMiddle(head));
    }
    return 0;
}

int getMiddle(Node *head)
{
  
   if(head==NULL)
   return -1;
   Node *slow=head;
   Node *fast=head;
   while(fast!=NULL&&fast->next!=NULL)
   {
       fast=fast->next->next;
       slow=slow->next;
   }
   return slow->data;
}
