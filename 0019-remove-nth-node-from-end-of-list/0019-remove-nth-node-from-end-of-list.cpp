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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        /*
        To find the nth node from the end without knowing the total length of the list, maintain a gap of $n$ nodes between two pointers (fast and slow). When fast reaches the end of the list, slow will be positioned right before the node that needs to be deleted.
        */
        ListNode* slow = head;
        ListNode* fast = head;

        for(int i = 0; i<n; i++){
            fast = fast->next;
        }

        if(fast == nullptr) return head->next; // if n = length of LL then remove the head
        
        while(fast->next){
            slow = slow->next;
            fast = fast->next;
        }

        ListNode* delNode = slow->next;
        slow->next = slow->next->next;

        delete delNode;
        return head;
    }
};