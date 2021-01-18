#include<bits/stdc++.h>

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

void print(Node *root)
{
    Node *temp = root;
    while(temp!=NULL)
    {
        cout<<temp->data<<" ";
        temp=temp->next;
    }
}


int main() {
	int t;
	cin>>t;
	while(t--)
	{
	    int n;
	    cin>>n;
	    int data;
	    struct Node* head=new Node(0);
	    struct Node* t=head;
	    for(int i=0;i<n;i++)
	    {
	        cin>>data;
	        head->next=new Node(data);
	        head=head->next;
	    }
	    t=t->next;
	    head=t;
	    
	    
	    struct Node* ans=new Node(0);
	    struct Node* t1=ans;
	    
	    while(t!=NULL)
	    {
	        if(t->data%2==0)
	        { 
	            t1->next=new Node(t->data);
	            t1=t1->next;
	        }
	   	        t=t->next;
	    }
	    
	    t=head;
	    
	     while(t!=NULL)
	    {
	        if(t->data%2==1)
	        { 
	            t1->next=new Node(t->data);
	            t1=t1->next;
	        }
	   	        t=t->next;
	    }
	    
	    ans=ans->next;
	    print(ans);
	    cout<<"\n";
	}
	
}