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
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(head == NULL || head->next == NULL) return head;
        int len = 1;
        ListNode* tail  = head;
        while(tail->next != NULL) {
            len++; tail = tail->next;
        }
        if(k%len == 0){ return head;}
        k=k%len;  
       
        tail->next = head;

        ListNode* detach = pointNode(head, k,len);
        head = detach->next;
        detach->next = NULL;

        return head;
    }
};