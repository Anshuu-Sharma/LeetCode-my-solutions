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
    //KNK
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
        unordered_map<TreeNode*, int> d;
        function<int(TreeNode*)> f = [&](TreeNode* root) -> int {
            if (!root) return 0;
            int l = f(root->left), r = f(root->right);
            d[root] = 1 + max(l, r);
            return d[root];
        };
        f(root);
        vector<int> res(d.size() + 1);
        function<void(TreeNode*, int, int)> dfs = [&](TreeNode* root, int depth, int rest) {
            if (!root) return;
            ++depth;
            res[root->val] = rest;
            dfs(root->left, depth, max(rest, depth + d[root->right]));
            dfs(root->right, depth, max(rest, depth + d[root->left]));
        };
        dfs(root, -1, 0);
        vector<int> ans;
        for (int v : queries) ans.emplace_back(res[v]);
        return ans;
    }

    // MYK -> TLE
    // int helper(TreeNode* root, int val){
    //     if(!root || root->val == val) return 0;

    //     int lh = helper(root->left, val);
    //     int rh = helper(root->right, val);

    //     return 1 + max(lh, rh);
    // }
    
    // vector<int> treeQueries(TreeNode* root, vector<int>& queries) {
    //     vector<int> ans;

    //     for(int i = 0; i<queries.size(); i++){
    //         ans.push_back(helper(root, queries[i]) - 1);
    //     }
    //     return ans;
    // }
};