class Solution {
public:
// method 2 - dfs
    void reverse(TreeNode* left, TreeNode* right, int level){
        if(left==NULL) return;

        if(level&1) swap(left->val,right->val);

        reverse(left->left, right->right, level+1);
        reverse(left->right, right->left, level+1);
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        reverse(root->left,root->right,1);
        return root;
    }
};