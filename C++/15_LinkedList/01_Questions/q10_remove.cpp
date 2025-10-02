// Given the head of a linked list and an integer val, remove all the nodes of the linked list that
// has Node.val == val, and return the new head.
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
    ListNode* removeNodes(ListNode* head, int value) {
        while (head != nullptr && head->val == value) {
            ListNode* delnode = head;
            head = head->next;
            delete delnode;  // free memory
        }

        // Now head is either nullptr or has a value != target
        ListNode* temp1 = head;
        while (temp1 != nullptr && temp1->next != nullptr) {
            if (temp1->next->val == value) {
                ListNode* delnode = temp1->next;
                temp1->next = temp1->next->next;
                delete delnode;
            } else {
                temp1 = temp1->next;
            }
        }
        return head;
    }
};

