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
    TreeNode* rightMostFinder(TreeNode* root){
        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }
        return temp;
    }
    TreeNode* helper(TreeNode* root) {
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;
        else{
            TreeNode* rightChild = root->right;
            TreeNode* lastChild = rightMostFinder(root->left);
            lastChild->right = rightChild;
        }
        return root->left;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root == nullptr) return root;
        
        if(root->val == key) return helper(root);

        TreeNode* dummy = root;
        while(dummy){
            if(dummy->val > key){
                if(dummy->left && dummy->left->val == key){
                    dummy->left = helper(dummy->left);
                    break;
                }
                else dummy = dummy->left;
            }
            else{
                if(dummy->right && dummy->right->val == key){
                    dummy->right = helper(dummy->right);
                    break;
                }
                else dummy = dummy->right;
            }
        }
        return root;
    }
};