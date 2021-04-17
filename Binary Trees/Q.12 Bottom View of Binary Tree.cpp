#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node
{
    int data;
    Node* left;
    Node* right;
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


void bottomView(Node *root);

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



int main() {
    int t;
    string tc;
    getline(cin, tc);
    t=stoi(tc);
    while(t--)
    {
        string s ,ch;
        getline(cin, s);
        Node* root = buildTree(s);

        bottomView(root);
        cout << endl;
    }
    return 0;
}


void solve(Node* root,int h,int l,map< int, pair < int, int > > &m)
{
    if(root==NULL)
    return ;
    if(m.find(h)==m.end())
    {
        m[h]=make_pair(root->data,l);
    }
    else
    {
         pair < int, int > p = m[h]; 
        if(l>=p.second)
        {
            m[h].second=l;
            m[h].first=root->data;
        }
    }
    solve(root->left,h-1,l+1,m);
    solve(root->right,h+1,l+1,m);
}
void bottomView(Node *root)
{
  if(root==NULL)
  return ;
  map < int, pair < int, int > > m; 
  solve(root,0,0,m);
  map < int, pair < int, int > > ::iterator it; 
  for(it=m.begin();it!=m.end();it++)
  {
      pair < int, int > p = it -> second; 
        cout << p.first << " ";
  }
}
