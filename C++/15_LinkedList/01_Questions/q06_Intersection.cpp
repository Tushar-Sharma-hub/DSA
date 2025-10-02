//160. Intersection of Two Linked Lists
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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode* tempA=headA;
        ListNode* tempB=headB;
        int lenA=0;
        while(tempA!=NULL){
            lenA++;
            tempA=tempA->next;
        }
        int lenB=0;
        while(tempB!=NULL){
            lenB++;
            tempB=tempB->next;
        }
        tempA=headA;
        tempB=headB;
        if(lenA>lenB){
            int diff=lenA-lenB;
            for(int i=1;i<=diff;i++){
                tempA=tempA->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        if(lenB>lenA){
            int diff=lenB-lenA;
            for(int i=1;i<=diff;i++){
                tempB=tempB->next;
            }
            while(tempA!=tempB){
                tempA=tempA->next;
                tempB=tempB->next;
            }
            return tempA;
        }
        while(tempA!=tempB){
            tempA=tempA->next;
            tempB=tempB->next;
        }
        return tempA;
    }
};