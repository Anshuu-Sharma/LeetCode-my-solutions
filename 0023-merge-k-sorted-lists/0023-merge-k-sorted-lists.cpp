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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<int, vector<int>, greater<int>> minHeap;

        for(auto it : lists) {
            ListNode* temp = it;
            while(temp) {
                minHeap.push(temp->val);
                temp=temp->next;
            }
        }

        if(minHeap.empty()) return nullptr;
        
        ListNode* ans = new ListNode(minHeap.top());
        ListNode* root = ans;
        minHeap.pop();
        
        while(!minHeap.empty()) {
            ListNode*  temp = new ListNode(minHeap.top());
            minHeap.pop();
            ans->next = temp;
            ans = ans->next;
        }
        return root;
    }
};