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

    ListNode* pointNode( ListNode* head, int k, int n) {
        ListNode* temp = head;
        for(int i = 1; i<(n-k); i++) {
            temp = temp->next;
        }
        return temp;
    }
    ListNode* rotateRight(ListNode* head, int k) {
        if(head == NULL || head->next == NULL) return head;

        int len = 1;

        // calculated length of LL
        ListNode* tail  = head;
        while(tail->next != NULL) {
            len++; tail = tail->next;
        }

        // if rotation is 0 then no change
        if(k%len == 0) return head;

        // because after n, the values of k gets repeated as number of rotations range: 0 to n
        k=k%len;  

        // connecting the tail to head
        tail->next = head;

        // break at the rotated point
        ListNode* detach = pointNode(head, k,len);
        head = detach->next;
        detach->next = NULL;

        return head;
    }
};