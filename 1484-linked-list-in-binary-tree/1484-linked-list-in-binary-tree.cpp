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
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
   bool checkPath(ListNode* head, TreeNode* root) {
        if (head == nullptr) return true;  // Reached the end of the list, valid subpath found
        if (root == nullptr) return false; // Reached a leaf, but the list is not fully matched yet

        // If the current node matches, continue checking the next list node in left and right subtrees
        if (head->val == root->val) {
            return checkPath(head->next, root->left) || checkPath(head->next, root->right);
        }

        return false;  // Current node does not match
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if (root == nullptr) return false;

        // Check if the path starting from the current tree node matches the linked list
        if (checkPath(head, root)) return true;

        // Otherwise, try matching the linked list in the left or right subtree
        return isSubPath(head, root->left) || isSubPath(head, root->right);
    }
};