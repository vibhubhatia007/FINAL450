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




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}


void inorder(Node* root,vector<int> &v)
{
    if(root==NULL)
    return;
    
    inorder(root->left,v);
    v.push_back(root->data);
    inorder(root->right,v);
}
void leaf(Node*root,unordered_map<int,int> &m)
{
    if(root==NULL)
    return ;
    
    if(root->left==NULL&&root->right==NULL)
    m[root->data]++;
    
    leaf(root->left,m);
    leaf(root->right,m);
    
}

bool isDeadEnd(Node *root)
{
    //Your code here
    vector<int> v;
    unordered_map<int,int> m;
    v.push_back(0);
    inorder(root,v);
    leaf(root,m);
    int c=0;
    for(int i=1;i<v.size()-1;i++)
    {
        if(v[i]-v[i-1]==1&&v[i+1]-v[i]==1)
        {
            if(m[v[i]]>0||v[i]==1)
            c=1;
            
        }
    }
    if(c==1)
    return true;
    else
    return false;
}