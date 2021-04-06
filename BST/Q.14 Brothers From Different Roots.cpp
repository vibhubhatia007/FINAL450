#include <bits/stdc++.h>
using namespace std;

// structure of a node of BST
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

void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}

int countPairs(Node* root1, Node* root2, int x);

// Driver code
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node* root1 = NULL;
        Node* root2 = NULL;
        int n1, n2, k;
        cin>>n1;
        for(int i=0; i<n1; i++)
        {
            cin>>k;
            insert(&root1, k);
        }
        cin>>n2;
        for(int i=0; i<n2; i++)
        {
            cin>>k;
            insert(&root2, k);
        }
        int s;
        cin>>s;
        cout<<countPairs(root1, root2, s)<<"\n";
    }
    return 0;
}


// } Driver Code Ends


//User function Template for C++
/*Structure of the Node of the BST is as
struct Node {
	int data;
	Node* left, *right;
};*/
// You are required to complete this function
void insert1(Node* root1,vector<int> &v1)
{
    if(root1==NULL)
    return ;
    insert1(root1->left,v1);
    v1.push_back(root1->data);
    insert1(root1->right,v1);
}
void insert2(Node* root2,vector<int> &v2)
{
    if(root2==NULL)
    return ;
    insert2(root2->left,v2);
    v2.push_back(root2->data);
    insert2(root2->right,v2);
}

int countPairs(Node* root1, Node* root2, int x)
{
    // Code here
    vector<int> v1;vector<int> v2;
    insert1(root1,v1);
    insert2(root2,v2);
    int c=0;
    int i=0;int j=v2.size()-1;
    while(i<v1.size()&&j>=0)
    {
        if(v1[i]+v2[j]==x)
        c++;
        if(v1[i]+v2[j]<x)
        i++;
        else
        j--;
        
    }
    
    return c;
}