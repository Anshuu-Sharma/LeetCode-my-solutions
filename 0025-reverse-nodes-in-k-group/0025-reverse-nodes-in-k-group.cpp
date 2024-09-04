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
    ListNode* findkth(ListNode* temp, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
         k -= 1; 
    while(temp != NULL && k > 0){
        k--; 
        temp = temp -> next; 
    }
    
    return temp; 
    }

    ListNode* reverse(ListNode* head) {
        ListNode* temp = head;
        ListNode* prevNode = NULL;
        while(temp) {
        ListNode* front = temp->next;
        temp->next = prevNode;
        prevNode = temp;
        temp = front;
        }
        return prevNode;
        
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
       
        ListNode* temp = head;
        ListNode* prevNode = NULL;

        while(temp != NULL) {
            ListNode* kthNode = findkth(temp, k);


            if(kthNode == NULL) {
              if(prevNode){ prevNode->next = temp;
                }
                break;
            }
            ListNode* nextNode = kthNode->next;
            kthNode->next = NULL;
            reverse(temp);
            if(temp == head) head = kthNode;
            else{
                prevNode->next = kthNode;
            }
            prevNode = temp;
            temp = nextNode;
        }
        return head;


    }
};