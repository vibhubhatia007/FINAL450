
#include<iostream>
#include<stack>
using namespace std;
void push(stack<int>& s,int a);
bool isFull(stack<int>& s,int n);
bool isEmpty(stack<int>& s);
int pop(stack<int>& s);
int getMin(stack<int>& s);


stack<int> s;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,a;
		cin>>n;
		while(!isEmpty(s)){
		    pop(s);
		}
		while(!isFull(s,n)){
			cin>>a;
			push(s,a);
		}
		cout<<getMin(s)<<endl;
	}
}// } Driver Code Ends


int dummy = 10001;
int m = 10001;


void push(stack<int>& s, int a){
	// Your code goes here
	
	if(s.size()==0)
	{
	    int x = dummy * a + a;
	    s.push(x);
	    m=a;
	}
	else
	{
	    if(a<m)
	    m=a;
	    int x = dummy * a + m;
	    s.push(x);
	}
	
}

bool isFull(stack<int>& s,int n){
	// Your code goes here
	if(s.size()==n)
	return true;
	else
	return false;
}

bool isEmpty(stack<int>& s){
	// Your code goes here
	if(s.size()==0)
	return true;
	else
	return false;
}

int pop(stack<int>& s){
	// Your code goes here
    int x=s.top();
    s.pop();
    return x/dummy;
    
}

int getMin(stack<int>& s){
	// Your code goes here
	return s.top()%dummy;
	
}