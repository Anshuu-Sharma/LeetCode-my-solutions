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

    bool helper(TreeNode* root1, TreeNode* root2){
        if(root1 == NULL && root2 == NULL) return true;
        if(!root1 || !root2) return false;
        if(root1->val != root2->val) return false;

        return helper(root1->left, root2->left) &&  helper(root1->right, root2->right) || 
                helper(root1->left, root2->right) &&  helper(root1->right, root2->left);
        

    }
    bool flipEquiv(TreeNode* root1, TreeNode* root2) {
        return helper(root1, root2);
    }

    // if(root1->left && root2->left && root1->left->val == root2->left->val){
    //         if(root1->right && root2->right && root1->right->val == root2->right->val){
    //             return helper(root1->left, root2->left) &&  helper(root1->right, root2->right);
               
    //         }
    //         else return false;
    //     }
    //     else if(root1->left && root2->right && root1->left->val == root2->right->val){
    //         if(root1->right && root2->left && root1->right->val == root2->left->val) {
    //             return helper(root1->left, root2->right) &&  helper(root1->right, root2->left);
    //         }
    //         else return false;
    //     }
    //     else return false;

    //     return true;
};