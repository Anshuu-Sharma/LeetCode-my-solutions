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
    bool helper(TreeNode* root, int targetSum) {
        if(root->left == nullptr && root->right == nullptr && root->val == targetSum) return true;

        bool left = false;
        bool right = false;

        if(root->left) left = helper(root->left, targetSum - root->val);
        if(root->right) right = helper(root->right, targetSum - root->val);

        return left || right;
    }
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(!root) return false;
        return helper(root, targetSum);
    }
};