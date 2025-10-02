//Find the length of the cycle LL.
#include<iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution {
public:
    int countCycleLength(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;

        // Step 1: Detect cycle using Floyd's algorithm
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;

            if (slow == fast) { // Cycle detected
                return getLength(slow);
            }
        }
        return 0; // No cycle
    }

private:
    int getLength(ListNode* meetingPoint) {
        ListNode* current = meetingPoint;
        int length = 0;
        do {
            current = current->next;
            length++;
        } while (current != meetingPoint);
        return length;
    }
};
