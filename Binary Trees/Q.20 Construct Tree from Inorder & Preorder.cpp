// { Driver Code Starts
//

#include<bits/stdc++.h>
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


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

class Solution{
    public:
    
Node* buildUtil(int in[], int pre[], int inStrt,
    int inEnd, int* pIndex, unordered_map<int, int>& mp)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
 

    int curr = pre[*pIndex];
    Node* node = new Node(curr);
    (*pIndex)++;
 

    if (inStrt == inEnd)
        return node;

    int iIndex = mp[curr];
 
    node->left = buildUtil(in, pre, inStrt,
                           iIndex - 1, pIndex, mp);
    node->right = buildUtil(in, pre, iIndex + 1,
                            inEnd, pIndex, mp);
   
 
    return node;
}
 
    
    Node* buildTree(int in[],int pre[], int len)
    {
        // Code here

    unordered_map<int, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    int index = 0; 
    return buildUtil(in, pre, 0, len - 1, &index, mp);
    }
};

// { Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
