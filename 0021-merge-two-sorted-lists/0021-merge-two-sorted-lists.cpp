/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:

    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* demi1 = new ListNode(-1);
        ListNode* cur = demi1;
        ListNode* temp1 = list1;
        ListNode* temp2 = list2;
      while(temp1 && temp2)
        { if(temp1->val <= temp2->val)
              {    cur->next = temp1;
                  temp1 = temp1->next;
               }
         else
        {
        cur->next = temp2;
        temp2 = temp2->next;
         }

         cur = cur->next;
         }

if(temp1)
    cur->next = temp1;
else
    cur->next = temp2;

return demi1->next;
    }
};