class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (!head || left == right) return head;

        ListNode dummy(0);
        dummy.next = head;
        ListNode* prev = &dummy;

        // Step 1: Reach node at position (left - 1)
        for (int i = 0; i < left - 1; ++i) {
            prev = prev->next;
        }

        // Step 2: Reverse nodes from 'left' to 'right' iteratively
        ListNode* curr = prev->next;
        for (int i = 0; i < right - left; ++i) {
            ListNode* temp = curr->next;
            curr->next = temp->next;
            temp->next = prev->next;
            prev->next = temp;
        }

        return dummy.next;
    }
};