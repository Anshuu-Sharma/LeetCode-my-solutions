#include <unordered_set>

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        // Use an unordered_set for fast O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        // Create a dummy node to handle edge cases (e.g., removing head)
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;

        // Traverse through the list
        while (head) {
            // If the current node's value is in numSet, remove the node
            if (numSet.count(head->val)) {
                prev->next = head->next;  // Skip the current node
            } else {
                prev = head;  // Move prev pointer forward
            }
            head = head->next;  // Move to the next node
        }

        // Return the modified list, skipping the dummy node
        return dummy->next;
    }
};
