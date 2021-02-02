#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};



vector<int> merge(Node *root1,Node *root2);

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
   Node* root = new Node(stoi(ip[0]));

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
           currNode->left = new Node(stoi(currVal));

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
           currNode->right = new Node(stoi(currVal));

           // Push it to the queue
           queue.push(currNode->right);
       }
       i++;
   }

   return root;
}



int main() {

   int t;
   string tc;
   getline(cin, tc);
   t=stoi(tc);
   while(t--)
   {
        string s; 
       getline(cin, s);
       Node* root1 = buildTree(s);

       getline(cin, s);
       Node* root2 = buildTree(s);
    
       // getline(cin, s);

       vector<int> vec = merge(root1, root2);
       for(int i=0;i<vec.size();i++)
            cout << vec[i] << " ";
        cout << endl;
       ///cout<<"~"<<endl;
   }
   return 0;
}// } Driver Code Ends


void inorder1(Node* root1,vector<int> &v1){
    
    if(root1==NULL)
    return ;
    
    inorder1(root1->left,v1);
    v1.push_back(root1->data);
    inorder1(root1->right,v1);
    
}

void inorder2(Node* root2,vector<int> &v2){
    
    if(root2==NULL)
    return ;
    
    inorder2(root2->left,v2);
    v2.push_back(root2->data);
    inorder2(root2->right,v2);
}

Node* create(vector<int> v,int s,int e)
{
    if(s>e)
    return NULL;
    
    int m=(s+e)/2;
    Node* root=new Node(v[m]);
    root->left=create(v,s,m-1);
    root->right=create(v,m+1,e);
    
    return root;
}

void inorder(Node* tree,vector<int> &ans)
{
    if(tree==NULL)
    return ;
    
    inorder(tree->left,ans);
    ans.push_back(tree->data);
    inorder(tree->right,ans);
    
}

vector<int> merge(Node *root1, Node *root2)
{
   vector<int> v1;vector<int> v2;
   inorder1(root1,v1);
   inorder2(root2,v2);
   vector<int> v;
   int i=0;int j=0;
   while(i<v1.size()&&j<v2.size())
   {
       if(v1[i]<v2[j])
       v.push_back(v1[i++]);
       else
       v.push_back(v2[j++]);
   }
   while(i<v1.size())
   v.push_back(v1[i++]);
   while(j<v2.size())
   v.push_back(v2[j++]);
   int s=0;int e=v.size()-1;
   Node* tree=create(v,s,e);
   vector<int> ans;
   inorder(tree,ans);
   
   return ans;
}