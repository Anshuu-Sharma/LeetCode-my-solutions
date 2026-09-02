#include <bits/stdc++.h>
using namespace std;

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
    int pathSum(TreeNode* root, int targetSum) {
        unordered_map<long long, int> prefix;
        prefix[0] = 1; // base
        return dfs(root, 0, targetSum, prefix);
    }
private:
    int dfs(TreeNode* node, long long currSum, int target,
    unordered_map<long long, int>& prefix) {
        if (!node) return 0;
        // update current prefix sum
        currSum += node->val;
        // check if any prev prefix makes a valid path
        int count = 0;
        if (prefix.count(currSum - target)) {
            count += prefix[currSum - target];
        }
        // include curr prefix sum in map
        prefix[currSum]++;
        // explore chilren
        count += dfs(node->left, currSum, target, prefix);
        count += dfs(node->right, currSum, target, prefix);
        // backtrack
        prefix[currSum]--;
        return count;
    }
};