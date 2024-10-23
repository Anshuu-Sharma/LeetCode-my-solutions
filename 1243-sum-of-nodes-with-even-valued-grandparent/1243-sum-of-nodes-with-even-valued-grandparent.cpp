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
private:
    int sum = 0;
public:
    void checker(TreeNode* root){
        if(root->left && root->left->left) sum += root->left->left->val;
        if(root->left && root->left->right) sum += root->left->right->val;
        if(root->right && root->right->left) sum += root->right->left->val;
        if(root->right && root->right->right) sum += root->right->right->val;
    }
    void helper(TreeNode* root){
        if(!root) return;

        if(root->val % 2 == 0){
            checker(root);
        }
        helper(root->left);
        helper(root->right);
    }
    int sumEvenGrandparent(TreeNode* root) {
        helper(root);
        return sum;
    }
};