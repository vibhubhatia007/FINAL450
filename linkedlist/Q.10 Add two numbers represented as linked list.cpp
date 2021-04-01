#include <bits/stdc++.h>
using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode() : val(0), next(nullptr) {}
      ListNode(int x) : val(x), next(nullptr) {}
      ListNode(int x, ListNode *next) : val(x), next(next) {}
  };


class Solution {
public:
    
    ListNode* rev(ListNode* head)
    {
        ListNode* cur=head;
        ListNode* prev=NULL;ListNode* next=NULL;
        
        while(cur!=NULL)
        {
            next=cur->next;
            cur->next=prev;
            prev=cur;
            cur=next;
        }
        
        head = prev;
        
        return head;
    }
    
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        
        ListNode* r1 = l1;
        ListNode* r2 = l2;
        
        ListNode* ans= new ListNode();
        int c=0; ListNode* anst=ans;
        while(r1!=NULL && r2!=NULL)
        {
            int x=r1->val+r2->val+c;
            ListNode* e =  new ListNode(x%10);
            c=x/10;
            r1=r1->next;
            r2=r2->next;
            ans->next=e;
            ans=ans->next;
        }
        while(r1!=NULL)
        {
            int x=r1->val+c;
            ListNode* e =  new ListNode(x%10);
            c=x/10;
            r1=r1->next;
            ans->next=e;
            ans=ans->next;
        }
        while(r2!=NULL)
        {
            int x=r2->val+c;
            ListNode* e =  new ListNode(x%10);
            c=x/10;
            r2=r2->next;
            ans->next=e;
            ans=ans->next;
        }
        
        while(c>0)
        {
            ListNode* e =  new ListNode(c%10);
            c=c/10;
            ans->next=e;
            ans=ans->next;
        }
        
        anst=anst->next;
        return anst;
        
    }
};