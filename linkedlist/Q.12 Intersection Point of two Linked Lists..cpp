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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        
        if (headA == NULL || headB == NULL) {
  
        return NULL;
    }
        
        ListNode* l1= headA;
        ListNode* l2= headB;
        int c1=0;int c2=0;
        while(l1!=l2)
        {
            l1=l1->next;
            l2=l2->next;
            
            if(l1==NULL)
            {
                if(c1==0)
                l1=headB;
                else
                break;
                c1++;
            
            }
            if(l2==NULL)
            {
                if(c2==0)
                l2=headA;
                else
                break;
                c2++;
            }
        }
        
        if(l1==l2)
        return l1;
        else
        return NULL;
        
        
    }
};