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
    int ans = 0;
    int dfs(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return root->val;

        int left = dfs(root->left);
        int right = dfs(root->right);

        ans += abs(right-left);
        return left + right + root->val;
    }
    int findTilt(TreeNode* root) {
        dfs(root);
        return ans;
    }
};