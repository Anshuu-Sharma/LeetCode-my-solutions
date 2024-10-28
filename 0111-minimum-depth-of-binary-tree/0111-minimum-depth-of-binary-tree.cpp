class Solution {
private:
    int mini = INT_MAX; 
public:
    void dfs(TreeNode* root, int depth) {
        if (!root) return;


        if (!root->left && !root->right) {
            mini = min(mini, depth);
        }


        if (root->left) dfs(root->left, depth + 1);
        if (root->right) dfs(root->right, depth + 1);
    }

    int minDepth(TreeNode* root) {
        if (!root) return 0; 

        dfs(root, 1);
        return mini;
    }
};
