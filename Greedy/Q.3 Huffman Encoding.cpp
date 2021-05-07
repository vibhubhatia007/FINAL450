#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution
{
	public:
	
	struct MinHeapNode {

    char data;
 
    unsigned freq;
 
    MinHeapNode *left, *right;
 
    MinHeapNode(char data, unsigned freq)
 
    {
 
        left = right = NULL;
        this->data = data;
        this->freq = freq;
    }
};
	
	struct compare {
 
    bool operator()(MinHeapNode* l, MinHeapNode* r)
 
    {
        return (l->freq > r->freq);
    }
 };
	
	void printCodes(struct MinHeapNode* root, string str, vector<string> &ans)
{
 
    if (!root)
        return;
 
    if (root->data != '$')
    {
        ans.push_back(str);
    }
 
    printCodes(root->left, str + "0", ans);
    printCodes(root->right, str + "1", ans);
}
	
		vector<string> huffmanCodes(string data,vector<int> freq,int size)
		{
		    // Code here
		    
    struct MinHeapNode *left, *right, *top;
 

    priority_queue<MinHeapNode*, vector<MinHeapNode*>, compare> minHeap;
 
    for (int i = 0; i < size; ++i)
        minHeap.push(new MinHeapNode(data[i], freq[i]));
 

    while (minHeap.size() != 1) {
 

        left = minHeap.top();
        minHeap.pop();
 
        right = minHeap.top();
        minHeap.pop();
 

        top = new MinHeapNode('$', left->freq + right->freq);
 
        top->left = left;
        top->right = right;
 
        minHeap.push(top);
    }
 
    vector<string> ans;
    printCodes(minHeap.top(), "",ans);
    
    
    return ans;
		}
};

int main(){
    int T;
    cin >> T;
    while(T--)
    {
	    string S;
	    cin >> S;
	    int N = S.length();
	    vector<int> f(N);
	    for(int i=0;i<N;i++){
	        cin>>f[i];
	    }
	    Solution ob;
	    vector<string> ans = ob.huffmanCodes(S,f,N);
	    for(auto i: ans)
	    	cout << i << " ";
	    cout << "\n";
    }
	return 0;
} 