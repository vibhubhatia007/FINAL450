#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

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

class Solution {
public:

  Node* create(vector<int> v,int s,int e)
  {
      if(s>e)
      return NULL;
      
      int m= (s+e)/2;
      Node* root=new Node(v[m]);
      root->left=create(v,s,m-1);
      root->right=create(v,m+1,e);
      
      return root;
      
  }
  
  void preorder(Node* root,vector<int> &v)
  {
      if(root==NULL)
      return ;
      
      v.push_back(root->data);
      preorder(root->left,v);
      preorder(root->right,v);
  }
    
    vector<int> sortedArrayToBST(vector<int>& nums) {
        int s=0;int e=nums.size()-1;
        Node* root=create(nums,s,e);
        vector<int> v;
        preorder(root,v);
        
        return v;
    }
};


int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)cin >> nums[i];
		Solution obj;
		vector<int>ans = obj.sortedArrayToBST(nums);
		for(auto i: ans)
			cout << i <<" ";
		cout << "\n";
	}
	return 0;
}  // 