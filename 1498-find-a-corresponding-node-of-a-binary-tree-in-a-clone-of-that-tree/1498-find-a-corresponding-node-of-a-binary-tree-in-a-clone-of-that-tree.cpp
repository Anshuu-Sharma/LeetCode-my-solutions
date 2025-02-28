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
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        if(!cloned) return nullptr;
        int data = target->val;

        queue<TreeNode*> q;
        q.push(cloned);
        while(!q.empty()){
            TreeNode* temp = q.front();
            q.pop();
            if(temp->val == data) return temp;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        return target;
    }
};