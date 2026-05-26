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
        // we can have a seen array -> it'll mark all the items that are present in nums, size = 100001
        // have dummy set before head, in case head gets removed.
        // then we start our traversal from dummy itself, what we will do is that, curr node if next node is there skip to the curr.next.next otherwise dont.

        bool seen[100001] = {false};
        for(int i : nums){
            seen[i] = true;
        }
        ListNode dummy(0);
        dummy.next = head;
        head = &dummy;
        ListNode* curr = &dummy;
        while(curr -> next){
            if(seen[curr -> next -> val]){
                curr -> next = curr -> next -> next;
            }
            else{
                curr = curr -> next;
            }
        }
        return dummy.next;
    }
};