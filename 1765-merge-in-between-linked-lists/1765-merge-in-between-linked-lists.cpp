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
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* end = list2;
        while(end->next){
            end = end->next;
        }

        ListNode* prev = list1;
        for (int i = 0; i < a - 1; ++i) {
            prev = prev->next;
        }


        ListNode* temp = prev;
        for (int i = 0; i <= b - a + 1; ++i) {
            temp = temp->next;
        }

        prev->next = list2;
        end->next = temp;
        return list1;

    }
};