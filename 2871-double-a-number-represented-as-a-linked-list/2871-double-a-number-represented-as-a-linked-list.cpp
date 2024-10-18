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
    ListNode* doubleIt(ListNode* head) {

        string s = "";
        
        ListNode* temp = head;
        while(temp){
            s.push_back(temp->val + '0');
            temp = temp->next;
        }

        int carry = 0;
        reverse(s.begin(), s.end());  
        for(int i = 0; i < s.size(); i++) {
            int num = (s[i] - '0') * 2 + carry;  
            carry = num / 10;
            s[i] = (num % 10) + '0'; 
        }
        if(carry > 0) {
            s.push_back(carry + '0');  
        }
        reverse(s.begin(), s.end());  

        ListNode* head1 = new ListNode(s[0]-'0');
        temp = head1;
        for(int i = 1; i<s.size(); i++){
            ListNode* t1 = new ListNode(s[i] - '0');
            temp->next = t1;
            temp = t1;
        }
        return head1;

        



    }
};