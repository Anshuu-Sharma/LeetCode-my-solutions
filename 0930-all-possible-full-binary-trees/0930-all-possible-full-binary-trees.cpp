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
    vector<TreeNode*> helper(int n,   vector<vector<TreeNode*>>& dp){
        if (n % 2 == 0) return dp[n]={}; // No full binary tree possible with even n
        if (n == 1) return dp[n] = { new TreeNode(0) }; 

        if (!dp[n].empty()) return dp[n];

        vector<TreeNode*> res;
        for(int l = 1; l<n; l+=2){
            int r = n-1-l;
            vector<TreeNode*> leftTrees = helper(l, dp);
            vector<TreeNode*> rightTrees = helper(r, dp);

            for(auto it1: leftTrees){
                for(auto it2: rightTrees){
                    res.push_back(new TreeNode(0, it1, it2));
                }
            }
        }
        return dp[n] = res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        vector<vector<TreeNode*>> dp(n+1);
        return helper(n, dp);
    }
};