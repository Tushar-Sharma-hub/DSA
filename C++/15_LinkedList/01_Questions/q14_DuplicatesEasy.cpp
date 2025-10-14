// 83. Remove Duplicates from Sorted List
// Given the head of a sorted linked list, delete all duplicates such that each element appears only once. Return the linked list sorted as well.
class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL) return head;
        ListNode* prevnode=head;
        ListNode* currnode=head->next;
        while(currnode!=NULL){
            if(currnode->val==prevnode->val){
                prevnode->next=currnode->next;
                currnode=currnode->next;
            }
            else{
                prevnode=prevnode->next;
                currnode=currnode->next;
            }
        }
        return head;
    }
};
