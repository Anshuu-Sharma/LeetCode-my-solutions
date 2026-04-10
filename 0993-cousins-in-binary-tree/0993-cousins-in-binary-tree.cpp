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
    bool isCousins(TreeNode* root, int x, int y) {
        queue<TreeNode*> q;
        q.push(root);
        int h1 = -1;
        int h2 = -1;
        TreeNode* parent1 = root;
        TreeNode* parent2 = root;
        int curr_height = -1;
        while(!q.empty()) {
            int siz = q.size();
            curr_height++;
            for(int i = 0; i<siz; i++) {
                TreeNode* temp = q.front(); q.pop();

                // check if both are items are found or not
                if(h1 != -1 && h2 != -1 && parent1 != parent2) return (h1==h2);

                // saving height of item found
                if(temp->val == x) h1 = curr_height;
                else if(temp->val == y) h2 = curr_height;

                // traversing further
                if(temp->left) {
                    if(((temp->left->val == x) || (temp->left->val == y))) parent1 = temp;
                    q.push(temp->left);
                }
                if(temp->right) {
                    if(((temp->right->val == y) || (temp->right->val == x))) parent2 = temp;
                    q.push(temp->right);
                }
            }
        }
        return ((h1 == h2) && parent1 != parent2);
        
    }
};