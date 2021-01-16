
#include <bits/stdc++.h>

using namespace std;
struct Node {
    int data;
    struct Node *next;
    Node(int x) {
        data = x;
        next = NULL;
    }
};

struct Node *start = NULL;

struct Node* segregate(struct Node *head);

void printList(struct Node *Node) {
    while (Node != NULL) {
        printf("%d ", Node->data);
        Node = Node->next;
    }
    printf("\n");
}

void insert(int n1) {
    int n, value, i;
    n = n1;
    struct Node *temp;
    for (i = 0; i < n; i++) {
        scanf("%d", &value);

        if (i == 0) {
            start = new Node(value);
            temp = start;
            continue;
        } else {
            temp->next = new Node(value);
            temp = temp->next;
            temp->next = NULL;
        }
    }
}

int main() {

    int n;

    int t;
    scanf("%d", &t);

    while (t--) {
        scanf("%d", &n);

        insert(n);
        struct Node *newHead = segregate(start);
        printList(newHead);
    }

    return 0;
}

Node* segregate(Node *head) {
    
    int c1=0,c2=0,c3=0;
    while(head!=NULL)
    {
        if(head->data==0)
        c1++;
        if(head->data==1)
        c2++;
        if(head->data==2)
        c3++;
        Node *x=head;
        free(x);
        head=head->next;
    }
    
    Node *t=new Node(0);
    Node *ans=t;
    while(c1--)
    {
        t->next=new Node(0);
        t=t->next;
    }
     while(c2--)
    {
        t->next=new Node(1);
        t=t->next;
    }
     while(c3--)
    {
        t->next=new Node(2);
        t=t->next;
    }
    
    ans=ans->next;
    
    return ans;
}
