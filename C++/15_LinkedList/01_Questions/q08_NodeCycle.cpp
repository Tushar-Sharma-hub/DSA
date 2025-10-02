//141. Linked List Cycle II , return where cycle begins.
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
    ListNode *detectCycle(ListNode *head) {
        ListNode* slow=head;
        ListNode* fast=head;
        int flag=0;
        while(fast!=NULL && fast->next!=NULL){
            slow=slow->next;
            fast=fast->next->next;
            if(slow==fast){
                flag=1;
                break;
            }
        }
        if(flag==1){  //Just find where slow fast meet(means have cycle).
            ListNode* temp=head;
            while(temp!=slow){ //Jaise he temp slow ke equal ayga it means the cycle will start from there.
                temp=temp->next;
                slow=slow->next;
            }
            return temp;
        }
        return NULL;
    }
};