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
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return depthFirstSearch(root).first;
    }
    pair<TreeNode*, int> depthFirstSearch(TreeNode* node) {
        if (!node) {
            return {nullptr, 0};
        }
      
        auto [leftSubtreeLCA, leftDepth] = depthFirstSearch(node->left);
        auto [rightSubtreeLCA, rightDepth] = depthFirstSearch(node->right);
      
        if (leftDepth > rightDepth) {
            return {leftSubtreeLCA, leftDepth + 1};
        } else if (leftDepth < rightDepth) {
            return {rightSubtreeLCA, rightDepth + 1};
        } else {
            return {node, leftDepth + 1};
        }
    }
};
