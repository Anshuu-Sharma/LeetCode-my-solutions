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
    bool isUnivalTree(TreeNode* root) {
        if(!root) return true;

        int n = root->val;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();

            if(temp->left){
                if(temp->left->val == n){
                    q.push(temp->left);
                }
                else return false;
            }
            
            if(temp->right){
                if(temp->right->val == n){
                    q.push(temp->right);
                }
                else return false;
            }
        }
        return true;
    }
};