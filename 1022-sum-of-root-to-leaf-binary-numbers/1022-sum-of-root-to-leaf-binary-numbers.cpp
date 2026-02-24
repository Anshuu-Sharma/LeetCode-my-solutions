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
    int sum = 0;
    
    void helper(TreeNode* root, std::string s) {
    if (!root) return;
    s += (root->val ? '1' : '0');
    if (!root->left && !root->right) {
        int num = std::stoi(s, nullptr, 2);
        sum += num;
        return;
    }
    if (root->left) helper(root->left, s);
    if (root->right) helper(root->right, s);
}
    int sumRootToLeaf(TreeNode* root) {
        helper(root, "");
        return sum;
    }
};