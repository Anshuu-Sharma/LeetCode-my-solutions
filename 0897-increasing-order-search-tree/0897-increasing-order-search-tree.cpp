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
    vector<int> ans;
    void dfs(TreeNode* root){
        if(!root) return;

        dfs(root->left);
        ans.push_back(root->val);
        dfs(root->right);
    }
    TreeNode* increasingBST(TreeNode* root) {
        dfs(root);

        TreeNode* head = new TreeNode(ans[0]);
        TreeNode* temp = head;
        for(int i = 1; i<ans.size(); i++){
           temp->right = new TreeNode(ans[i]);
           temp = temp->right;
        }

        return head;
    }
};