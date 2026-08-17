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
    int findlen(ListNode* head){
        if(!head) return 0;

        return 1 + findlen(head->next);
    }
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        // if(!head) return {};

        int len = findlen(head);
        vector<ListNode*> ans;

        // if len < k then there will be partitions of size 1
        int size = len/k;
        int rem = len%k;

        ListNode* temp = head;
        while(temp){
            ans.push_back(temp);
            int finalSize = (rem>0) ? size+1 : size;
            rem--;

            for (int j = 0; j < finalSize - 1; ++j) {
                temp = temp->next;
            }

            ListNode* temp2 = temp->next;
            temp->next = nullptr;
            temp = temp2;
        }

        int a = ans.size();
        if(a < k){
            for(int i = 0; i<(k - a); i++){
                ans.push_back({});
            }
        }

        return ans;


    }
};