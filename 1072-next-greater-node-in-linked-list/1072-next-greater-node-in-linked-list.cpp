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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans;

        ListNode* temp = head;
        while(temp){
            ans.push_back(temp->val);
            temp = temp->next;
        }

        int n = ans.size();

        for(int i = 0; i<n-1; i++){
            int temp = ans[i];
            for(int j = i + 1; j<n; j++){
                if(ans[j] > ans[i]){
                    ans[i] = ans[j];
                    break;
                } 
            }
            if(ans[i] == temp) ans[i] = 0;
        }
        ans[n-1] = 0;

        return ans;


    }
};