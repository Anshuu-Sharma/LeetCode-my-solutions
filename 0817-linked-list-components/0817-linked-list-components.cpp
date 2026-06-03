class Solution {
public:
    int numComponents(ListNode* head, vector<int>& nums) {
        // Store nums in an unordered_set for O(1) lookups
        unordered_set<int> numSet(nums.begin(), nums.end());
        
        int componentCount = 0;
        ListNode* current = head;
        
        while (current != nullptr) {
            // Check if current node is in the set
            if (numSet.count(current->val)) {
                // If the next node is null or NOT in the set, we've reached the end of a component
                if (current->next == nullptr || !numSet.count(current->next->val)) {
                    componentCount++;
                }
            }
            current = current->next;
        }
        
        return componentCount;
    }
};