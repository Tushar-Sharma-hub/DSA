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
    ListNode* reverseList(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* nh=reverseList(head->next);
        head->next->next=head;
        head->next=NULL;
        return nh;
    }
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if(head==NULL || head->next==NULL) return head;
        int l=1,r=1;
        ListNode* temp=head,*a=NULL,*b=NULL,*ln=NULL;
        while(r<=right && temp!=NULL){
            if(l==left-1){
                ln=temp;
            }
            if(l==left){
                a=temp;
            }
            if(r==right){
                b=temp;
                break;
            }
            temp=temp->next;
            l++;
            r++;
        }
        ListNode* rn=NULL;
        if(b->next!=NULL){ rn=b->next;
        b->next=NULL;}
        ListNode* nh=reverseList(a);
        if(ln!=NULL) ln->next=nh;
        if(rn!=NULL){
            ListNode* temp1=nh;
            while(temp1->next!=NULL){
                temp1=temp1->next;
            }
            temp1->next=rn;
        }
        if(left==1) head=nh;
        return head;
    }
    ListNode* reverseEvenLengthGroups(ListNode* head) {
        ListNode* temp=head;
        int gap=1;
        while(temp && temp->next!=NULL){
            int remlen=0;
            ListNode* t=temp->next;
            for(int i=1;i<=gap+1 && t!=NULL;i++){
                t=t->next;
                remlen++;
            }
            if(remlen<gap+1) gap=remlen-1;
            if(gap%2!=0) reverseBetween(temp,2,2+gap);
            gap++;
            for(int i=1;temp!=NULL && i<=gap;i++){
                temp=temp->next;
            }
        }
        return head;
    }
};
