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
    int depthcheck(TreeNode* root) {
        if(root == NULL) return 0;

        int lh = depthcheck(root->left);
        int rh = depthcheck(root->right);

        if(lh == -1 || rh == -1) return -1;
        if(abs(lh - rh) > 1) return -1;
        return max(lh,rh) + 1;

    }
    bool isBalanced(TreeNode* root) {
        int ans = depthcheck(root);
        return !(ans == -1);
    }
};