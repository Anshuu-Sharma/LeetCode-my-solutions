/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* prev;
    Node* next;
    Node* child;
};
*/

class Solution {
public:
    Node* flatten(Node* head) {
        if (!head) return nullptr;
        
        Node* curr = head;
        while (curr) {
            // If a child exists, we need to handle it
            if (curr->child) {
                Node* nextNode = curr->next;
                Node* childNode = curr->child;
                
                // 1. Connect current node to child
                curr->next = childNode;
                childNode->prev = curr;
                curr->child = nullptr; // Important: clear the child pointer
                
                // 2. Find the tail of the child list
                Node* tail = childNode;
                while (tail->next) {
                    tail = tail->next;
                }
                
                // 3. Connect tail of child list to the original next node
                tail->next = nextNode;
                if (nextNode) {
                    nextNode->prev = tail;
                }
            }
            // Move to the next node
            curr = curr->next;
        }
        
        return head;
    }
};