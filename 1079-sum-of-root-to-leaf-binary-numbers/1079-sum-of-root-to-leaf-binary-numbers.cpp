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
private:
    int ans = 0;
public:

    void traverse(TreeNode* root, string s){
        if(!root) return;

        s.push_back(root->val + '0');

        if(!root->left && !root->right) {
            ans += stoi(s, nullptr, 2);
        }
        
        if(root->left) traverse(root->left, s);
        if(root->right) traverse(root->right, s);

    }
    int sumRootToLeaf(TreeNode* root) {
        
        string num = "";

        traverse(root, num);
        return ans;

    
    }

        
    
};