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
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == nullptr) return head;
        ListNode* temp = head;
        vector<int> vec;
        while(temp) {
           if(temp->next == nullptr || temp->val != temp->next->val) {
                vec.push_back(temp->val);
                temp = temp->next;
           }

           else if(temp->val == temp->next->val) {
            int v = temp->val;
            while(temp!=nullptr && temp->val == v) {
                    temp = temp->next;
            }
           }
        }
        if(vec.size() == 0) return nullptr;
        ListNode* root = new ListNode(vec[0]);
        temp = root;
        for(int i = 1; i<vec.size(); i++) {
            temp->next = new ListNode(vec[i]);
            temp = temp->next;
        }

        return root;
    }
};