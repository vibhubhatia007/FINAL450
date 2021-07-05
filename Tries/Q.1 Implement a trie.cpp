#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Node {
    public : 
    char data ;
    unordered_map<char,Node*> children;
    bool terminal ;

    Node(char d)
    {
        data = d;
        terminal = false;
    }
};

class Trie{

    Node* root;
    int cnt;

    public : 
    Trie()
    {
        root = new Node ('\0');
        cnt = 0;
    }

    void insert(string w)
    {
        Node* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch))
                temp = temp->children[ch];
            else{
                Node* n = new Node(ch);
                temp->children[ch] = n;
                temp = n;
            }
        }
        temp->terminal = true;
    }

    bool find(string w)
    {
        Node* temp = root;
        for(int i=0;w[i]!='\0';i++)
        {
            char ch = w[i];
            if(temp->children.count(ch)==0){
                return false;
            }
            else{
                temp = temp ->children[ch];
            }
        }
        return temp->terminal;
    }

};

int main() {

    Trie t;
    vector<string> words;
    words.push_back("hello");
    words.push_back("hell");
    words.push_back("nope");
    words.push_back("no");
    words.push_back("yo");
    string w;
    cin>>w;

    for(int i=0;i<5;i++)
    {
        t.insert(words[i]);
    }

    if(t.find(w))
    cout<<"Present";
    else
    cout<<"Not Present";



}