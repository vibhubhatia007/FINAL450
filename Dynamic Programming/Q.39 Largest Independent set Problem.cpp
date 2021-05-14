#include <bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};

int LISS(struct Node *root);


int main()
{
  int t;
  struct Node *child;
  scanf("%d\n", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d\n",&n);
     struct Node *root = NULL;
     while (n--)
     {
        Node *parent;
        char lr;
        int n1, n2;
        scanf("%d %d %c", &n1, &n2, &lr);
        if (m.find(n1) == m.end())
        {
           parent = new Node(n1);
           m[n1] = parent;
           if (root == NULL)
             root = parent;
        }
        else
           parent = m[n1];
        child = new Node(n2);
        if (lr == 'L')
          parent->left = child;
        else
          parent->right = child;
        m[n2]  = child;
     }
     cout<<LISS(root)<<endl;
  }
  return 0;
}

int LISS(struct Node *root)
{

    if(root==NULL)
    return 0;

    
    int inc=1;int exc=0;
    if(root->right!=NULL)
    inc=inc+LISS(root->right->left)+LISS(root->right->right);
    if(root->left!=NULL)
    inc=inc+LISS(root->left->left)+LISS(root->left->right);
    
    exc=LISS(root->left)+LISS(root->right);
    
    
    return max(inc,exc);
    
}