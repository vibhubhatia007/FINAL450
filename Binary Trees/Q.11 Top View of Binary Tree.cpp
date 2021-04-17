#include <bits/stdc++.h>
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

void topView(struct Node *root);


int main()
{
    int t;cin>>t;
    while(t--)
    {
        int n,i,k;
        cin>>n;
        i=n;

        Node* root=NULL;
        queue <Node*> q;
        while(i>0)
        {
            int a,b;
            char c;
            cin>> a >> b >> c;
            if(!root){
                root = new Node(a);
                q.push(root);
            }
            Node* pick = q.front();
            q.pop();

            if(c == 'L'){
                pick->left = new Node(b);
                q.push( pick->left );
            }
            cin>> a >> b >> c;
            if(c == 'R'){
                pick->right = new Node(b);
                q.push( pick->right );
            }
            i-=2;
        }
//        inorder(root);
//        cout<<endl;
        topView(root);
        cout << endl;
    }
    return 0;
}



void solve(struct Node* root,int h,int l,map< int, pair < int, int > > &m)
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
        if(l<p.second)
        {
            m[h].second=l;
            m[h].first=root->data;
        }
    }
    solve(root->left,h-1,l+1,m);
    solve(root->right,h+1,l+1,m);
}
void topView(struct Node* root)
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

