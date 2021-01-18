#include <stdio.h>
#include <stdlib.h>
#include<iostream>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

int getNthFromLast(struct Node* head, int n);

int main()
{
  int T,i,n,l,k;

    cin>>T;

    while(T--){
    struct Node *head = NULL,  *tail = NULL;

        cin>>n>>k;
        int firstdata;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }

    cout<<getNthFromLast(head, k)<<endl;
    }
    return 0;
}

int getNthFromLast(Node *head, int n)
{
       Node *next=NULL;Node *prev=NULL;
       Node *cur=head;
       while(cur!=NULL)
       {
           next=cur->next;
           cur->next=prev;
           prev=cur;
           cur=next;
       }
       head=prev;
       
       while(head!=NULL)
       {
           n--;
           if(n==0)
           {
               break;
           }
           else
           {
               head=head->next;
           }
       }
       if(head!=NULL)
       return head->data;
       else
       return -1;
       
}

