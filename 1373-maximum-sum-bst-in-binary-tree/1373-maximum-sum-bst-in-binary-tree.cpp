/**
 * Definition for a binary tree node.
 * struct TreeNode {
 * int val;
 * TreeNode *left;
 * TreeNode *right;
 * TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */

class Solution {
    struct NodeValue {
        int minNode, maxNode, sum;
        bool isBST;
    };

    int maxSum = 0;

    NodeValue helper(TreeNode* root) {
        // Base case: An empty node is a valid BST with sum 0
        if (!root) return {INT_MAX, INT_MIN, 0, true};

        // Post-order traversal
        auto left = helper(root->left);
        auto right = helper(root->right);

        // Check if the current tree is a BST
        if (left.isBST && right.isBST && root->val > left.maxNode && root->val < right.minNode) {
            // It is a BST, calculate current sum
            int currentSum = root->val + left.sum + right.sum;
            maxSum = max(maxSum, currentSum);
            
            return {
                min(root->val, left.minNode),
                max(root->val, right.maxNode), // this calculates maximum value of the whole subtree rooted at root, and as all values in left half is less than root therefore only right side is compared. same for minimum value.
                currentSum,
                true
            };
        }

        // Not a BST
        return {INT_MIN, INT_MAX, 0, false};
    }

public:
    int maxSumBST(TreeNode* root) {
        maxSum = 0;
        helper(root);
        return maxSum;
    }
};