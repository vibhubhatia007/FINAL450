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


int sumOfLongRootToLeafPath(Node* root);

int main()
{
  int t;
  scanf("%d", &t);
  while (t--)
  {
     map<int, Node*> m;
     int n;
     scanf("%d",&n);
     struct Node *root = NULL;
     struct Node *child;
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
     cout<<sumOfLongRootToLeafPath(root)<<endl;
  }
  return 0;
}

// your task is to complete this function
int height(Node* root)
{
    if(root==NULL)
    return 0;
    else
    return 1+ max(height(root->left),height(root->right));
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	if(root==NULL)
	return 0;
	
	int ans=root->data;
	while(root->left!=NULL||root->right!=NULL)
	{
	    if(height(root->left)>height(root->right))
	    {
	        root=root->left;
	        ans=ans+root->data;
	    }
	    else if(height(root->left)<height(root->right))
	    {
	        root=root->right;
	        ans=ans+root->data;
	    }
	    else
	    {
	        if(root->left->data>root->right->data)
	        {
	            root=root->left;
	            ans=ans+root->data;
	        }
	        else
	        {
	            root=root->right;
	            ans=ans+root->data;
	        }
	    }
	    
	    
	}
	
	return ans;
}


///////////Method-2/////////////

void solve(Node* root,int sum,int length,int &maxsum,int &maxl)
{
    if(root==NULL)
    {
        if(length>maxl||(maxl==length&&sum>maxsum))
        {
            maxsum=sum;
            maxl=length;
        }
        
        return ;
    }
    
    solve(root->left,sum+root->data,length+1,maxsum,maxl);
    solve(root->right,sum+root->data,length+1,maxsum,maxl);
}

int sumOfLongRootToLeafPath(Node* root)
{
	// Code here
	int maxsum=0;int maxl=0;
	solve(root,0,0,maxsum,maxl);
	
	return maxsum;
}