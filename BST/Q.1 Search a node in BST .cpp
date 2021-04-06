#include<bits/stdc++.h>

using namespace std;

struct Node {
    int data;
    Node* right;
    Node* left;
    
    Node(int x){
        data = x;
        right = NULL;
        left = NULL;
    }
};

bool search(Node* root, int x);

Node *insert(Node *tree, int val)
{
    Node *temp = NULL;
    if (tree == NULL)
        return new Node(val);

    if (val < tree->data)
    {
        tree->left = insert(tree->left, val);
    }
    else if (val > tree->data)
    {
        tree->right = insert(tree->right, val);
    }
    
    return tree;
}

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            root = insert(root, k);

        }

        int s;
        cin>>s;
        
     cout<<search(root,s);
     cout<<endl;
    }
}

bool search(Node* root, int x)
{
    if(root==NULL)
    return false;
    if(root->data==x)
    return true;
    if(root->data<x)
    return search(root->right,x);
    else
    return search(root->left,x);
}


/////////////////////////////////////////////////////////////////////////////////

  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 };

class Solution {
public:

    
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(root==NULL)
            return NULL;
        
         if (!root) {
            return nullptr;
        }

        if (key < root->val) {
            root->left = deleteNode(root->left, key);
        }
        else if (key == root->val) {
            if (!root->left || !root->right) {
                TreeNode* del = root;
                root = (root->left ? root->left : root->right);
                delete del;
            }
            else {
                TreeNode* tmp = root->right;
                while (tmp->left) {
                    tmp = tmp->left;
                }
                root->val = tmp->val;
                root->right = deleteNode(root->right, root->val);
            }
        }
        else {
            root->right = deleteNode(root->right, key);
        }
        
        return root;
    }
};