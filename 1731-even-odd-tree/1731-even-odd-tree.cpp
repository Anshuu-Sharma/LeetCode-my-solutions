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
    bool isEvenOddTree(TreeNode* root) {
        queue<TreeNode*> q;
        q.push(root);
        int level = -1;
        while(!q.empty()){
            int siz = q.size();
            level++;
            int prev = INT_MIN;
            if(level%2 != 0) prev = INT_MAX;
            for(int i = 0; i<siz; i++) {
                TreeNode* temp = q.front(); q.pop();

                if(level%2 == 0) {
                    if(temp->val % 2 == 0 || prev >= temp->val) {
                        return false;
                    }
                }
                else if(level%2 != 0) {
                    if(temp->val % 2 != 0 || prev <= temp->val) {
                        return false;
                    }
                }

                prev = temp->val;
                if(temp->left) q.push(temp->left);
                if(temp->right) q.push(temp->right);
            }
        }
        return true;
    }
};