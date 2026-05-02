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
    bool isValidBST(TreeNode* root) {
        if(root == nullptr) return true;
        long long prev = LLONG_MIN; // To handle INT_MIN nodes
        TreeNode* curr = root;
        bool valid = true;
        while (curr) {
            if (!curr->left) {
                // Visit current node
                if (curr->val <= prev) valid = false;
                prev = curr->val;
                curr = curr->right;
            } else {
                // Find inorder predecessor of curr
                TreeNode* pred = curr->left;
                while (pred->right && pred->right != curr) {
                    pred = pred->right;
                }
                if (!pred->right) {
                    // Make a temporary link to curr
                    pred->right = curr;
                    curr = curr->left;
                } else {
                    // Remove the link
                    pred->right = nullptr;
                    if (curr->val <= prev) valid =  false;
                    prev = curr->val;
                    curr = curr->right;
                }
            }
        }
        return valid;
    }
};