#include<bits/stdc++.h>
using namespace std;

class SortedStack{
public:
	stack<int> s;
	void sort();
};

void printStack(stack<int> s)
{
    while (!s.empty())
    {
        printf("%d ", s.top());
       	s.pop();
    }
    printf("\n");
}

int main()
{
int t;
cin>>t;
while(t--)
{
	SortedStack *ss = new SortedStack();
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
	int k;
	cin>>k;
	ss->s.push(k);
	}
	ss->sort();
	printStack(ss->s);
}
}

void insert(stack<int>& s,int x)
{
    if(s.size()==0 || x > s.top() )
        s.push(x);
    else
    {
        int a = s.top();
        s.pop();
        insert(s,x);
        s.push(a);
    }
} 

void SortedStack :: sort()
{
    int x;
    if(s.size()==0)
    {
        return ;
    }
    x = s.top();
    s.pop();
    sort();
    insert(s,x);
}