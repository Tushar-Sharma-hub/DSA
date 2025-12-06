class Solution {
public:
    ListNode* insertionSortList(ListNode* head) {
        // Base case: if list is empty or has only one node, it's already sorted
        if (head == NULL || head->next == NULL) return head;

        // Create a dummy node (new head) before the actual head
        // This helps easily insert nodes at the beginning of the list
        ListNode* nh = new ListNode();
        nh->next = head;

        // 'curr' points to the current node being checked
        // 'prev' is used to find the correct position to insert nodes
        ListNode *curr = head, *prev = nh;

        // Traverse through the linked list
        while (curr) {
            // Check if the next node is out of order
            if (curr->next && (curr->next->val < curr->val)) {
                // Find the correct position to insert curr->next
                while (prev->next && (prev->next->val < curr->next->val))
                    prev = prev->next;

                // Re-link the nodes to insert curr->next in the right position
                ListNode* temp = prev->next;          // store insertion point
                prev->next = curr->next;              // link prev to smaller node
                curr->next = curr->next->next;        // unlink inserted node
                prev->next->next = temp;              // complete insertion

                // Reset prev back to dummy head for next iteration
                prev = nh;
            } 
            else {
                // Move forward if already in correct order
                curr = curr->next;
            }
        }

        // Return the sorted list (excluding dummy node)
        return nh->next;
    }
};
