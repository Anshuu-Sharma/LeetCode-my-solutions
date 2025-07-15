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
unordered_map<TreeNode*, TreeNode*> mpp;
vector<int> ans;
unordered_set<TreeNode*> st;
    void helper(TreeNode* root, TreeNode* par){
        if(!root) return;

        mpp[root] = par;

        helper(root->left, root);
        helper(root->right, root);
    }
    void helper2(TreeNode* root, int k, int curr){
        if(!root) return;
        if(st.find(root) != st.end()) return;
        if(curr == k) {
            ans.push_back(root->val);
            return;
        }
        st.insert(root);
        helper2(mpp[root], k, curr+1);
        helper2(root->left, k, curr+1);
        helper2(root->right, k, curr+1);
        
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
       
       helper(root, nullptr);

    
        helper2(target, k, 0);
        return ans;
        
    }
};