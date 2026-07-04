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
    ListNode* getkth(ListNode* temp,int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp = temp->next;

        }
        return temp;

    }
    ListNode* reversed(ListNode* temp){
      ListNode* prev = NULL;
      if(temp==NULL || temp->next == NULL){
        return temp;
      }
        while(temp!=NULL){
            ListNode* front = temp->next;
        temp -> next = prev;
        prev = temp;
        temp = front;
        }
        return prev;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
       ListNode* prevnode = NULL;
       ListNode* nextnode = NULL;
       ListNode* temp = head;
       while(temp!= NULL){
        ListNode* kthelement = getkth(temp,k);
        if(kthelement == NULL){
            if(prevnode) prevnode->next = temp;
                 break;
        }
       
        nextnode = kthelement->next;
        kthelement ->next = NULL;
        reversed(temp);
        if(temp==head){
            head = kthelement;
        }
        else{
            prevnode->next = kthelement;
        }
        prevnode = temp;
        temp = nextnode;
       }
       return head;
}
    };