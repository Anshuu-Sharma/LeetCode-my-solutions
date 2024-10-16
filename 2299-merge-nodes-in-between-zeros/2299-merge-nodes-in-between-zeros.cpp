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
    ListNode* mergeNodes(ListNode* head) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        ListNode* first_zero = head;
        ListNode* temp = head->next;
        ListNode* prev = head;
        while(temp->next){
            int data = 0;
            while(temp->val){
                data += temp->val;
                prev = temp;
                temp = temp->next;
            }
            ListNode* between = new ListNode(data);
            between->next = prev->next;
            first_zero->next = between;
            first_zero = temp;
            if(temp->next)temp = temp->next;
        }
        
        head = head->next;
        temp = head->next;
        prev = head;
        while(temp->next){
            prev->next = temp->next;
            prev = temp->next;
            temp = prev->next;
        }
        prev->next = nullptr;

        return head;
    }
};