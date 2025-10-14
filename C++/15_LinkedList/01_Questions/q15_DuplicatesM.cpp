// 82. Remove Duplicates from Sorted List II
// Given the head of a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list. Return the linked list sorted as well.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* nh=new ListNode(0);
        nh->next=head;
        ListNode* temp=nh;
        while(head!=NULL){
            if(head->next && head->val==head->next->val){
                while(head->next && head->val==head->next->val){
                    head=head->next;
                }
                temp->next=head->next;
            }
            else {
                temp->next=head;
                temp=head;
            }
            head=head->next;
        }
        return nh->next;
    }
};
