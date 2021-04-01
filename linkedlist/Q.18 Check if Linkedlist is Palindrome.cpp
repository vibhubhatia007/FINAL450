#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
using namespace std;

struct Node {
  int data;
  struct Node *next;
  Node(int x) {
    data = x;
    next = NULL;
  }
};

bool isPalindrome(Node *head);

int main()
{
  int T,i,n,l,firstdata;
    cin>>T;
    while(T--)
    {
        
        struct Node *head = NULL,  *tail = NULL;
        cin>>n;
        cin>>firstdata;
        head = new Node(firstdata);
        tail = head;
      
        for(i=1;i<n;i++)
        {
            cin>>l;
            tail->next = new Node(l);
            tail = tail->next;
        }
   	cout<<isPalindrome(head)<<endl;
    }
    return 0;
}


bool isPalindrome(Node *head)
{
    Node *t=head;
    Node *h=new Node(head->data);Node *h1=h;
    head=head->next;
    while(head!=NULL)
    {
        h->next=new Node(head->data);
        h=h->next;
        head=head->next;
    }
    Node* cur=t;Node* nex=NULL;Node* prev=NULL;
    while(cur!=NULL)
    {
        nex=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nex;
    }
    
    t=prev;
    
   
   while(h1!=NULL && t!=NULL)
   {
       if(h1->data==t->data)
       {
           h1=h1->next;
           t=t->next;
       }
       else
       return false;
   }
    
   return true;
    
}

