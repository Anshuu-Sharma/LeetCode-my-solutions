/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        
        // If root is NULL, nothing is found
        if(root == NULL)
            return NULL;

        // If root is p or q, return root
        if(root == p || root == q)
            return root;

        // Search in left subtree
        TreeNode* leftLCA = lowestCommonAncestor(root->left, p, q);

        // Search in right subtree
        TreeNode* rightLCA = lowestCommonAncestor(root->right, p, q);

        // One node found on each side
        // Therefore, root is the LCA
        if(leftLCA && rightLCA)
            return root;

        // If found on left, return left result
        else if(leftLCA != NULL)
            return leftLCA;

        // Otherwise return right result
        else
            return rightLCA;
    }
};