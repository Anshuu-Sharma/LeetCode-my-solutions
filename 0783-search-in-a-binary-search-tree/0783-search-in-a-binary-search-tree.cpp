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
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
      
        if(root == NULL) return NULL;
        TreeNode* temp = root;

        while(temp) {
            if(temp->val == val) return temp;

            else if(temp->val < val){
                if(temp->right) temp = temp->right;
                else return NULL;
            }

            else if(temp->val > val){
                if(temp->left) temp = temp->left;
                else return NULL;
            }
        }
    return root;
    }
};