class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        // 1. Create a dummy node to handle edge cases (like removing the head)
        ListNode* dummy = new ListNode(0, head);
        ListNode* prev = dummy; // 'prev' is the last known "distinct" node

        while (head != nullptr) {
            // 2. If we find a sequence of duplicates...
            if (head->next != nullptr && head->val == head->next->val) {
                // Skip all nodes with the same value
                while (head->next != nullptr && head->val == head->next->val) {
                    head = head->next;
                }
                // Link 'prev' to the node AFTER the last duplicate
                prev->next = head->next;
            } else {
                // 3. No duplicate found, move 'prev' forward
                prev = prev->next;
            }
            // Move 'head' forward for the next iteration
            head = head->next;
        }

        // best step -> we will directly get next element
        return dummy->next;
    }
};