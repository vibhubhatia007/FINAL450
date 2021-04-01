#include <iostream>
#include <bits/stdc++.h>

using namespace std;

  struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
 };

class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        
       ListNode* slow=head;
       ListNode* fast=head;
       int flag=1;
        
    while(slow!=NULL&&fast!=NULL&&fast->next!=NULL)
    {
     slow=slow->next;
     fast=fast->next->next;
     if(slow==fast)
     {
         slow = head;
         while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
          }
         return fast;
     }
    }
        
        return NULL;
    
   
        
    }
};