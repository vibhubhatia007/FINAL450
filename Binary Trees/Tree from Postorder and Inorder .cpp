
#include <bits/stdc++.h>
using namespace std;


struct Node {
    int data;
    struct Node* left;
    struct Node* right;

    Node(int x) {
        data = x;
        left = right = NULL;
    }
};

/* This funtcion is here just to test buildTreeUtil() */
void preOrder(Node* node) {
    if (node == NULL) return;

    /* then print the data of node */
    printf("%d ", node->data);

    /* first recur on left child */
    preOrder(node->left);

    /* now recur on right child */
    preOrder(node->right);
}

Node* buildTree(int in[], int post[], int n);

int main() {
    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        int in[n], post[n];
        for (int i = 0; i < n; i++) cin >> in[i];
        for (int i = 0; i < n; i++) cin >> post[i];
        Node* root = buildTree(in, post, n);
        preOrder(root);
        cout << endl;
    }
    return 0;
}


Node* buildUtil(int in[], int post[], int inStrt,
    int inEnd, int* pIndex, unordered_map<int, int>& mp)
{
    // Base case
    if (inStrt > inEnd)
        return NULL;
 

    int curr = post[*pIndex];
    Node* node = new Node(curr);
    (*pIndex)--;
 

    if (inStrt == inEnd)
        return node;

    int iIndex = mp[curr];
 

    node->right = buildUtil(in, post, iIndex + 1,
                            inEnd, pIndex, mp);
    node->left = buildUtil(in, post, inStrt,
                           iIndex - 1, pIndex, mp);
 
    return node;
}
 

Node *buildTree(int in[], int post[], int len) {
    // Your code here
     unordered_map<int, int> mp;
    for (int i = 0; i < len; i++)
        mp[in[i]] = i;
 
    int index = len - 1; 
    return buildUtil(in, post, 0, len - 1,
                     &index, mp);
}
