/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    void helper(TreeNode* root, unordered_map<TreeNode*, TreeNode*>& mpp, TreeNode* par){
        if(!root) return;

        mpp[root] = par;
        helper(root->left, mpp, root);
        helper(root->right, mpp, root);
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        unordered_set<TreeNode*> vis;

        unordered_map<TreeNode*, TreeNode*> mpp;
        helper(root, mpp, nullptr);


        while(p){
            vis.insert(p);
            p = mpp[p];
        }

         while(q){
             if(vis.count(q)) return q;
            q = mpp[q];
        }
        return nullptr;

    }
};