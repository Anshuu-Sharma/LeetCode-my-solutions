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
    int sum = 0;
    void helper(TreeNode* root) {
        if(!root) return;

        if(root->left && root->left->left == nullptr && root->left->right == nullptr) sum += root->left->val;

        if(root->right) helper(root->right);
        if(root->left) helper(root->left);
    }
    int sumOfLeftLeaves(TreeNode* root) {
        helper(root);
        return sum;
    }
};