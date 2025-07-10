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
    bool isCompleteTree(TreeNode* root) {

        queue<TreeNode*> q;
        q.push(root);

        bool foundNull = false;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(!node) foundNull = true;
            else{
                if(foundNull) return false;
                q.push(node->left);
                q.push(node->right);
            }
            
        }
        return true;
    }
};