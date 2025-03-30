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
    vector<TreeNode*> helper(int n){
        if (n % 2 == 0) return {}; // No full binary tree possible with even n
        if (n == 1) return { new TreeNode(0) }; 

        vector<TreeNode*> res;
        for(int l = 0; l<n; l++){
            int r = n-1-l;
            vector<TreeNode*> leftTrees = helper(l);
            vector<TreeNode*> rightTrees = helper(r);

            for(auto it1: leftTrees){
                for(auto it2: rightTrees){
                    res.push_back(new TreeNode(0, it1, it2));
                }
            }
        }
        return res;
    }
    vector<TreeNode*> allPossibleFBT(int n) {
        return helper(n);
    }
};