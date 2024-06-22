/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    bool hasCycle(ListNode *head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        map<ListNode*,int> mpp;
        ListNode* temp = head;
        while (temp != nullptr) {
            if (mpp.find(temp) != mpp.end()) {
                return true;
            }
            mpp[temp] = 1;
            temp = temp->next;
        }
        return false;
    }
};