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
    bool dfs(TreeNode* root, int target){
        if(!root->left && !root->right){
            if(root->val == target)return true;
        }

        bool lh = false;
        bool rh = false;
        if(root->left)  lh = dfs(root->left, target);
        if(root->right)  rh = dfs(root->right, target);

        if(lh) root->left = NULL;
        if(rh) root->right = NULL;

        return !root->left && !root->right && root->val == target;

    }
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return dfs(root, target) ? nullptr : root;
    }
};