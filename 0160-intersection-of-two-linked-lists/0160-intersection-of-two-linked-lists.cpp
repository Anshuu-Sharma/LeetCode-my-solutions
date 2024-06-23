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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(headA == NULL || headB == NULL) return NULL;

        ListNode* tA = headA;
        ListNode* tB = headB;
        while (tA != tB) {
            tA = tA->next;
            tB = tB->next;

            if (tA == tB) return tA;

            if (tA == NULL) tA = headB;
            if (tB == NULL) tB = headA;
        }
        return tA;
    }
};