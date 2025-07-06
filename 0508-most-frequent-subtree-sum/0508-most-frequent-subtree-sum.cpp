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
    int dfs(TreeNode* root){
        if(!root) return 0;

        int lh = root->val + dfs(root->left);
        int rh = root->val + dfs(root->right);

        return lh + rh - root->val; 


    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int, int> freq;

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()) {
            TreeNode* temp = q.front(); q.pop();

            int sum = dfs(temp);
            freq[sum]++;

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        int maxi = INT_MIN;
        for(auto it:freq) {
            maxi = max(maxi, it.second);
        }

        vector<int> ans;

        for(auto it:freq) {
            if(it.second == maxi) ans.push_back(it.first);
        }

        return ans;



        
    }
};