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
    TreeNode* searchBST(TreeNode* root, int val) {
        if(root == nullptr) return root;
        
        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front(); q.pop();
            if(temp && temp->val == val) return temp;
            
            else if(temp->val < val && temp->right) q.push(temp->right);
            else if(temp->val > val && temp->left) q.push(temp->left);
        }
        return nullptr;
    }
};