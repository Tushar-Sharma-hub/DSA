//LC-2095 Deleete Middle Node , usign slow and fast pointer.
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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode* temp=head;
        if(temp->next==NULL) return NULL;
        int idx=0;
        while(temp!=NULL && temp->next!=NULL){
            idx++;
            temp=temp->next->next;
        }
        temp=head;
        for(int i=0;i<idx-1;i++){
            temp=temp->next;
        }
        temp->next=temp->next->next;
        return head;
    }
};