#include <bits/stdc++.h>
using namespace std;


class node{
    public : 
    node* left;
    node* right;
    
};

class trie{
    node* root;
    public :
    trie(){
        root = new node();
    }
    
    void insert(int n){
        node* temp = root;
        
        for(int i=31;i>=0;i--){
            int bit = (n>>i)&1;
            if(bit==0){
                if(temp->left==NULL){
                    temp->left = new node();
                }
                temp = temp->left;
            }
            else{
                if(temp->right==NULL){
                    temp->right = new node();
                }
                temp = temp->right;
            }
        }
    }
    
    int helper(int value){
         node* temp = root;
         
        int cur = 0;
        for(int j=31;j>=0;j--){
            int bit = (value>>j)&1;
            
            if(bit==0){
                if(temp->right!=NULL){
                    temp =temp->right;
                    cur+= (1<<j);
                }
                else
                    temp = temp->left;
            }
            else{
                if(temp->left!=NULL){
                    temp =temp->left;
                    cur+= (1<<j);
                }
                else
                    temp = temp->right;
            }
            
            
        }
        
        return cur;
        
    }
    
    int max_xo(int *input,int n){
        int max_xor = 0;
        
        for(int i=0;i<n;i++){
            int val = input[i];
            insert(val);
            int current_xor = helper(val);
            max_xor = max(max_xor,current_xor);
        }
        
        return max_xor;
    }
    
};


class Solution
{
    public:
    int max_xor(int arr[] , int n)
    {
        //code here
      int ans = 0;
      
      trie t;
      return t.max_xo(arr,n);
       
       
    }
    
};

int main()
{
	int t;
	cin >> t;

	while (t--)
	{
		int n;
		cin >> n;

		int a[n];
		for (int i = 0; i < n; i++)
			cin >> a[i];

        Solution ob;
		cout << ob.max_xor(a, n) << endl;

	}
}

