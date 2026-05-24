class Solution {
    TreeNode *first = NULL, *second = NULL, *prev = NULL;

    void inorder(TreeNode* root) {
        if (!root) return;
        
        inorder(root->left);
        
        // If the previous node is greater than the current node, we found a violation
        if (prev != NULL && prev->val > root->val) {
            // The first node is the 'prev' at the first violation
            if (first == NULL) {
                first = prev;
            }
            // The second node is always the current 'root'
            // This works for both adjacent and non-adjacent swaps
            second = root;
        }
        
        prev = root;
        inorder(root->right);
    }

public:
    void recoverTree(TreeNode* root) {
        inorder(root);
        // Swap the values of the two identified nodes
        if (first && second) {
            swap(first->val, second->val);
        }
    }
};