#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

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

vector <int> zigZagTraversal(Node* root);

int main()
{
    int t;
    scanf("%d ",&t);
  while (t--)
  {
        string s;
		getline(cin,s);
		Node* root = buildTree(s);
        vector <int> res = zigZagTraversal(root);
        for (int i = 0; i < res.size (); i++) cout << res[i] << " ";
        cout<<endl;
  }
  return 0;
}


// return a vector containing the zig zag level order traversal of the given tree
void solve(Node* root,int d,int h, map<int, vector<int>> &m)
{
    if(root==NULL)
    return ;
    
    m[h].push_back(root->data);
    solve(root->left,d-1,h+1,m);
    solve(root->right,d+1,h+1,m);
}

vector <int> zigZagTraversal(Node* root)
{
    map<int, vector<int>> m;
    vector<int> ans;
	solve(root,0,0,m);int c=0;
	 for (auto it :m)
    {
        vector<int> v=it.second;
        if(c%2==0)
        {
            for(int i=0;i<v.size();i++)
            {
                ans.push_back(v[i]);
            }
            c++;
        }
        else
        {
            for(int i=v.size()-1;i>=0;i--)
            {
                ans.push_back(v[i]);
            }
            c++;
        }
    }
    
    return ans;
}