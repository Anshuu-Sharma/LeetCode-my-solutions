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
    ListNode* swapNodes(ListNode* head, int k) {

        // this is brute one from my side , ig it'll use rabbit and hare method 
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        ListNode* start = head;
        ListNode* end = head;
        ListNode* temp = head;

        // First, find the length of the list `n`
        int n = 0;
        while (temp) {
            n++;
            temp = temp->next;
        }

        // Find the `k-th` node from the start
        temp = head;
        for (int i = 1; i < k; i++) {
            temp = temp->next;
        }
        start = temp;  // `start` now points to the `k-th` node from the start
            // it is important to keep this statement out of any loop to be executed;

        // Find the `k-th` node from the end
        temp = head;
        for (int i = 1; i < (n - k + 1); i++) {
            temp = temp->next;
        }
        end = temp;  // `end` now points to the `k-th` node from the end
         // it is important to keep this statement out of any loop to be executed;

        // Swap the values of `start` and `end`
        int t = start->val;
        start->val = end->val;
        end->val = t;

        return head;
    }
};
