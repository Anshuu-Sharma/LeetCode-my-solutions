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
    // void i_sort(vector<int>& arr){
    //     int el = arr[0];
    //     for(int i = 1; i<arr.size(); i++){
    //         if(arr[i] < arr[i-1]){
    //             int j = i;
    //             while(j>0 && arr[j] < arr[j-1]){
    //                 swap(arr[j], arr[j-1]);
    //                 j--;
    //             }
    //         }
    //     }
    // }
    ListNode* insertionSortList(ListNode* head) {
        if(head->next == NULL) return head;
        vector<int> arr;
        ListNode* temp = head;
        while(temp){
            arr.push_back(temp->val);
            temp = temp->next;
        }

        //i_sort(arr);
        sort(arr.begin(), arr.end());

        head->val = arr[0];
        temp = head->next;
        for(int i = 1; i<arr.size(); i++){
            temp->val = arr[i];
            temp = temp->next;
        }
        return head;
    }
};