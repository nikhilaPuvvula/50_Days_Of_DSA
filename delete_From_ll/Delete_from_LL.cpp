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
    ListNode* removeElements(ListNode* head, int val) {
        
        if(head==NULL)
         return NULL;
        while(head->val==val && head->next!=NULL)
        { 
          head=head->next;
        }
        if(head->next == NULL && head->val == val)
         return NULL;
        
        if(head->next==NULL && head->val!=val)
        {
            return head;
        }

        struct ListNode *temp =head;
        struct ListNode *p;
        while(temp->next!=NULL)
        {
            if(temp->val == val)
            { 
               p->next = temp->next; 
               temp=p->next;
            }  
            else
            {
             p = temp;
             temp=temp->next;
            }
        }
        if(p->next->val == val)
        {
            p->next=NULL;
        }
        
        return head;
         
    }
};