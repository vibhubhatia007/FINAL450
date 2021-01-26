#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};
// Utility function to create a new Tree Node
Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}
// Function to Build Tree
Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}

bool isSumTree(struct Node* node);

int main()
{

    int t;
	scanf("%d ",&t);
    while(t--)
    {
        string s;
		getline(cin,s);
        Node* root = buildTree(s);
        cout <<isSumTree(root) << endl;
    }
    return 1;
}

bool isleaf(Node *root)
{
    if(root==NULL)
    return false;
    if(root->left==NULL && root->right==NULL)
    return true;
    
    return false;
}

bool isSumTree(Node* root)
{
     if(root==NULL || isleaf(root))
     return true;
     
     int ls,rs;
     
     if(root->left==NULL)
     ls=0;
     else if(isleaf(root->left))
     ls=root->left->data;
     else
     ls=2*(root->left->data);
     
     if(root->right==NULL)
     rs=0;
     else if(isleaf(root->right))
     rs=root->right->data;
     else
     rs=2*(root->right->data);
     
     
     if(root->data == ls+rs)
     return (isSumTree(root->left)&&isSumTree(root->right));
     else
     return false;
     
}