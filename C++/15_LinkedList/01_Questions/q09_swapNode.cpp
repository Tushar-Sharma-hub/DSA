//1721. Swapping Nodes in a Linked List
#include<iostream>
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
    ListNode* swapNodes(ListNode* head, int k) {
        int size=0;
        ListNode* temp=head;
        while(temp!=NULL){
            size++;
            temp=temp->next;
        }
        temp=head;
        int fidx=k-1,eidx=size-k;
        ListNode* temp1=head;
        for(int i=0;i<fidx;i++){
            temp=temp->next;
        }
        for(int i=0;i<eidx;i++){
            temp1=temp1->next;
        }
        swap(temp->val,temp1->val);
        return head;
    }
};