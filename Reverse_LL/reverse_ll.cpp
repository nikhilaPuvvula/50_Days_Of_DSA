class Solution {
public:
    ListNode* reverseList(ListNode* head) {
  struct ListNode *temp=head;
        if(head==NULL || head->next==NULL)
          return head;
        vector<int> a;
        while(temp!=NULL)
        {
            a.push_back(temp->val);
            temp=temp->next;
        }
        ListNode* h1 = NULL;
        ListNode *t1=h1;
        for(int i=a.size()-1;i>=0;i--)
        {
            ListNode * p = new ListNode(a[i]);
            if(h1==NULL)
            {
              h1=p;
              t1=h1;
            }
            t1->next=p;
            t1=t1->next;
        }
        return h1;
    }
}


// OPTIMAL SOLUTION---POINTERS
    
class Solution {
public:
    ListNode* reverseList(ListNode* head) {

       if(head==nullptr || head->next==nullptr)
     {
         return head;
     }
     ListNode *curr, *prev, *next;
     curr=head;
     prev=nullptr;
     while(curr!=nullptr)
     {
         next=curr->next;
         curr->next=prev;
         prev=curr;
         curr=next;
     }
     return prev;
       
    }
};