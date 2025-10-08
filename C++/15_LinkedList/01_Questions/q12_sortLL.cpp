class Solution {
public:
    ListNode* merge(ListNode* list1, ListNode* list2) {
        ListNode* c=new ListNode(100);
        ListNode* temp=c;
        while(list1!=NULL && list2!=NULL){
            if(list1->val<=list2->val){
                temp->next=list1;
                temp=list1;
                list1=list1->next;
            }
            else{
                temp->next=list2;
                temp=list2;
                list2=list2->next;
            }
        }
        if(list1==NULL) temp->next=list2;
        else temp->next=list1;
        return c->next;
    }
    ListNode* sortList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* slow=head;
        ListNode* fast=head;
        while(fast->next!=NULL && fast->next->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
        }
        ListNode* a=head;
        ListNode* b=slow->next;
        slow->next=NULL;
        a=sortList(a);
        b=sortList(b);
        ListNode* c=merge(a,b);
        return c;
    }
};
