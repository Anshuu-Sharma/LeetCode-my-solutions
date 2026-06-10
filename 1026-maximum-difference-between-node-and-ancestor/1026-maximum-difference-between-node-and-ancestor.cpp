class Solution {
public:
    int helper(TreeNode* node, int curMax, int curMin) {
        if (!node) {
            return curMax - curMin;
        }
        
        curMax = max(curMax, node->val);
        curMin = min(curMin, node->val);
        
        int leftDiff = helper(node->left, curMax, curMin);
        int rightDiff = helper(node->right, curMax, curMin);
        
        return max(leftDiff, rightDiff);
    }
    
    int maxAncestorDiff(TreeNode* root) {
        if (!root) return 0;
        return helper(root, root->val, root->val);
    }
};